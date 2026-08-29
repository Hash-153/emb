/**
 * @file titan_circular_buffer.h
 * @brief Thread-Safe Lockless FIFO Byte Ring Buffer
 */

#ifndef TITAN_CIRCULAR_BUFFER_H
#define TITAN_CIRCULAR_BUFFER_H

#include "titan_types.h"
#include "titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u8_t               *buffer;         /**< Pointer to contiguous memory storage */
    mem_size_t          capacity;       /**< Total capacity in bytes (power of 2 recommended) */
    volatile mem_size_t head;           /**< Write pointer offset */
    volatile mem_size_t tail;           /**< Read pointer offset */
    volatile bool_t     is_full;        /**< Saturation indicator */
    bool_t              overwrite_on_full; /**< Overwrite oldest unread byte on overflow */
} titan_cbuf_t;

titan_status_t titan_cbuf_init(titan_cbuf_t *cbuf, u8_t *storage, mem_size_t capacity, bool_t overwrite);
titan_status_t titan_cbuf_reset(titan_cbuf_t *cbuf);
bool_t         titan_cbuf_is_empty(const titan_cbuf_t *cbuf);
bool_t         titan_cbuf_is_full(const titan_cbuf_t *cbuf);
mem_size_t     titan_cbuf_available(const titan_cbuf_t *cbuf);
mem_size_t     titan_cbuf_space_left(const titan_cbuf_t *cbuf);

titan_status_t titan_cbuf_put(titan_cbuf_t *cbuf, u8_t data);
titan_status_t titan_cbuf_get(titan_cbuf_t *cbuf, u8_t *data);
titan_status_t titan_cbuf_peek(const titan_cbuf_t *cbuf, mem_size_t offset, u8_t *data);
mem_size_t     titan_cbuf_write(titan_cbuf_t *cbuf, const u8_t *src, mem_size_t len);
mem_size_t     titan_cbuf_read(titan_cbuf_t *cbuf, u8_t *dest, mem_size_t len);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_CIRCULAR_BUFFER_H */
