/**
 * @file titan_param_registry.h
 * @brief Industrial Parameter Store with Schema Validation, Persistence & Range Verification
 * @version 2.4.0
 * @date 2026-08-29
 */

#ifndef TITAN_PARAM_REGISTRY_H
#define TITAN_PARAM_REGISTRY_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TITAN_PARAM_TYPE_U8 = 0,
    TITAN_PARAM_TYPE_U16,
    TITAN_PARAM_TYPE_U32,
    TITAN_PARAM_TYPE_S8,
    TITAN_PARAM_TYPE_S16,
    TITAN_PARAM_TYPE_S32,
    TITAN_PARAM_TYPE_F32
} titan_param_type_t;

typedef struct {
    u16_t              id;
    const char        *name;
    titan_param_type_t type;
    f32_t              min_val;
    f32_t              max_val;
    f32_t              default_val;
    void              *val_ptr;
    bool_t             is_dirty;
} titan_param_entry_t;

#define TITAN_PARAM_COUNT 350

titan_status_t titan_param_init_all(void);
titan_status_t titan_param_get_by_id(u16_t id, f32_t *out_val);
titan_status_t titan_param_set_by_id(u16_t id, f32_t in_val);
titan_status_t titan_param_reset_defaults(void);
const titan_param_entry_t* titan_param_find_by_name(const char *name);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_PARAM_REGISTRY_H */
