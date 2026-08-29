/**
 * @file titan_safety_voter.c
 * @brief Outlier Rejection and Median Selection for Redundant Transducers
 */

#include "safety/titan_safety_voter.h"
#include "core/titan_defs.h"

titan_status_t titan_voter_init(titan_voter_2oo3_t *voter, f32_t tolerance)
{
    if (!voter || tolerance <= 0.0f) return TITAN_ERROR_INVALID_ARGUMENT;
    voter->tolerance = tolerance;
    voter->failed_channel = 0;
    return TITAN_OK;
}

titan_status_t titan_voter_vote_f32(titan_voter_2oo3_t *voter, f32_t ch1, f32_t ch2, f32_t ch3, f32_t *voted_val)
{
    if (!voter || !voted_val) return TITAN_ERROR_NULL_POINTER;

    f32_t d12 = TITAN_ABS(ch1 - ch2);
    f32_t d23 = TITAN_ABS(ch2 - ch3);
    f32_t d13 = TITAN_ABS(ch1 - ch3);

    bool_t m12 = (d12 <= voter->tolerance);
    bool_t m23 = (d23 <= voter->tolerance);
    bool_t m13 = (d13 <= voter->tolerance);

    if (m12 && m23 && m13) {
        /* All 3 channels agree: take average */
        *voted_val = (ch1 + ch2 + ch3) / 3.0f;
        voter->failed_channel = 0;
        return TITAN_OK;
    } else if (m12) {
        *voted_val = (ch1 + ch2) * 0.5f;
        voter->failed_channel = (1 << 2); /* Channel 3 failed */
        return TITAN_OK;
    } else if (m23) {
        *voted_val = (ch2 + ch3) * 0.5f;
        voter->failed_channel = (1 << 0); /* Channel 1 failed */
        return TITAN_OK;
    } else if (m13) {
        *voted_val = (ch1 + ch3) * 0.5f;
        voter->failed_channel = (1 << 1); /* Channel 2 failed */
        return TITAN_OK;
    }

    /* All 3 channels disagree */
    voter->failed_channel = 0x07;
    return TITAN_SAFETY_ERR_2OO3_DISAGREE;
}
