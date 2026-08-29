/**
 * @file titan_safety_voter.h
 * @brief 2-out-of-3 (2oo3) Triple Modular Redundancy Voting Engine
 */

#ifndef TITAN_SAFETY_VOTER_H
#define TITAN_SAFETY_VOTER_H

#include "core/titan_types.h"
#include "core/titan_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    f32_t tolerance;        /**< Maximum acceptable delta between sensors */
    u8_t  failed_channel;   /**< Bitmask of detected fault channels */
} titan_voter_2oo3_t;

titan_status_t titan_voter_init(titan_voter_2oo3_t *voter, f32_t tolerance);
titan_status_t titan_voter_vote_f32(titan_voter_2oo3_t *voter, f32_t ch1, f32_t ch2, f32_t ch3, f32_t *voted_val);

#ifdef __cplusplus
}
#endif

#endif /* TITAN_SAFETY_VOTER_H */
