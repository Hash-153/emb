/**
 * @file titan_circular_buffer.c
 * @brief High-Speed Byte FIFO Implementation for Interrupt and DMA Streams
 */

#include "titan_circular_buffer.h"

titan_status_t titan_cbuf_init(titan_cbuf_t *cbuf, u8_t *storage, mem_size_t capacity, bool_t overwrite)
{
    if (!cbuf || !storage || capacity == 0) {
        return TITAN_ERROR_INVALID_ARGUMENT;
    }
    cbuf->buffer = storage;
    cbuf->capacity = capacity;
    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->is_full = FALSE;
    cbuf->overwrite_on_full = overwrite;
    return TITAN_OK;
}

titan_status_t titan_cbuf_reset(titan_cbuf_t *cbuf)
{
    if (!cbuf) return TITAN_ERROR_NULL_POINTER;
    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->is_full = FALSE;
    return TITAN_OK;
}

bool_t titan_cbuf_is_empty(const titan_cbuf_t *cbuf)
{
    if (!cbuf) return TRUE;
    return (!cbuf->is_full && (cbuf->head == cbuf->tail));
}

bool_t titan_cbuf_is_full(const titan_cbuf_t *cbuf)
{
    if (!cbuf) return FALSE;
    return cbuf->is_full;
}

mem_size_t titan_cbuf_available(const titan_cbuf_t *cbuf)
{
    if (!cbuf) return 0;
    if (cbuf->is_full) return cbuf->capacity;
    if (cbuf->head >= cbuf->tail) {
        return cbuf->head - cbuf->tail;
    }
    return cbuf->capacity + cbuf->head - cbuf->tail;
}

mem_size_t titan_cbuf_space_left(const titan_cbuf_t *cbuf)
{
    if (!cbuf) return 0;
    return cbuf->capacity - titan_cbuf_available(cbuf);
}

titan_status_t titan_cbuf_put(titan_cbuf_t *cbuf, u8_t data)
{
    if (!cbuf) return TITAN_ERROR_NULL_POINTER;

    if (cbuf->is_full) {
        if (!cbuf->overwrite_on_full) {
            return TITAN_ERROR_BUFFER_FULL;
        }
        /* Advance tail if overwriting */
        cbuf->tail = (cbuf->tail + 1) % cbuf->capacity;
    }

    cbuf->buffer[cbuf->head] = data;
    cbuf->head = (cbuf->head + 1) % cbuf->capacity;
    cbuf->is_full = (cbuf->head == cbuf->tail);

    return TITAN_OK;
}

titan_status_t titan_cbuf_get(titan_cbuf_t *cbuf, u8_t *data)
{
    if (!cbuf || !data) return TITAN_ERROR_NULL_POINTER;
    if (titan_cbuf_is_empty(cbuf)) return TITAN_ERROR_BUFFER_EMPTY;

    *data = cbuf->buffer[cbuf->tail];
    cbuf->tail = (cbuf->tail + 1) % cbuf->capacity;
    cbuf->is_full = FALSE;

    return TITAN_OK;
}

titan_status_t titan_cbuf_peek(const titan_cbuf_t *cbuf, mem_size_t offset, u8_t *data)
{
    if (!cbuf || !data) return TITAN_ERROR_NULL_POINTER;
    if (offset >= titan_cbuf_available(cbuf)) return TITAN_ERROR_OUT_OF_BOUNDS;

    mem_size_t index = (cbuf->tail + offset) % cbuf->capacity;
    *data = cbuf->buffer[index];
    return TITAN_OK;
}

mem_size_t titan_cbuf_write(titan_cbuf_t *cbuf, const u8_t *src, mem_size_t len)
{
    if (!cbuf || !src || len == 0) return 0;
    mem_size_t written = 0;
    for (mem_size_t i = 0; i < len; ++i) {
        if (titan_cbuf_put(cbuf, src[i]) == TITAN_OK) {
            written++;
        } else {
            break;
        }
    }
    return written;
}

mem_size_t titan_cbuf_read(titan_cbuf_t *cbuf, u8_t *dest, mem_size_t len)
{
    if (!cbuf || !dest || len == 0) return 0;
    mem_size_t read_bytes = 0;
    for (mem_size_t i = 0; i < len; ++i) {
        if (titan_cbuf_get(cbuf, &dest[i]) == TITAN_OK) {
            read_bytes++;
        } else {
            break;
        }
    }
    return read_bytes;
}
