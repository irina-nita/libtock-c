// Implementation of the mbedtls timing functions required by libcoap
// using the Tock userlan alarm API

#include <stdint.h>
#include <mbedtls/timing.h>
#include <libtock/peripherals/syscalls/alarm_syscalls.h>
#include <libtock/services/alarm.h>

static uint32_t get_uptime_ms(void) {
    uint32_t ticks;
    libtock_alarm_command_read(&ticks);
    return libtock_alarm_ticks_to_ms(ticks);
}


// We cannot use mbedtls_timing_delay_context because the standard struct
// contains an opaque hr_time blob sized for Unix/Windows.  Define our own
// context that matches what coap_mbedtls.c allocates (it only cares about the
// size of mbedtls_timing_delay_context, which is large enough).
typedef struct {
    uint32_t start_ms;
    uint32_t int_ms;
    uint32_t fin_ms;
} tock_timing_ctx;

void mbedtls_timing_set_delay(void *data, uint32_t int_ms, uint32_t fin_ms) {
    tock_timing_ctx *ctx = (tock_timing_ctx *)data;

    if (ctx == NULL) return;

    ctx->int_ms = int_ms;
    ctx->fin_ms = fin_ms;

    if (fin_ms != 0) {
        ctx->start_ms = get_uptime_ms();
    } else {
        ctx->start_ms = 0;
    }
}

// Returns:
// - -1 if cancelled (fin_ms = 0)
// - 0 if none of the delays are passed
// - 1 if only the intermediate delay is passed
// - 2 if the final delay is passed
int mbedtls_timing_get_delay(void *data) {
    tock_timing_ctx *ctx = (tock_timing_ctx *)data;

    if (ctx == NULL || ctx->fin_ms == 0) return -1; // cancelled

    uint32_t elapsed = get_uptime_ms() - ctx->start_ms;

    if (elapsed >= ctx->fin_ms) return 2; // the final delay is passed
    if (elapsed >= ctx->int_ms) return 1; // the intermediate delay is passed 
    return 0; // none of the delays are passed
}
