#pragma once

#include "../../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRIVER_NUM_WIFI 0x30008

// On
#define COMMAND_ON 1
#define SUBSCRIBE_ON 0

// Join
#define COMMAND_JOIN_NETWORK 5
#define SUBSCRIBE_JOIN_NETWORK 1
#define ALLOW_RO_SSID 0
#define ALLOW_RO_PASS 1

// Get MAC
#define COMMAND_GET_MAC 2
#define ALLOW_RW_MAC 0

// Set AP mode
#define COMMAND_SET_MODE_AP 3
#define SUBSCRIBE_SET_MODE_AP 3

// Set STA mode
#define COMMAND_SET_MODE_STA 4
#define SUBSCRIBE_SET_MODE_STA 4

// Leave network
#define COMMAND_LEAVE_NETWORK 6
#define SUBSCRIBE_LEAVE_NETWORK 2

// Start scan
#define COMMAND_START_SCAN 7
#define SUBSCRIBE_START_SCAN 5
#define SUBSCRIBE_SCAN_RES 7
#define ALLOW_RW_SCAN_SSID 1

// Stop scan
#define COMMAND_STOP_SCAN 8
#define SUBSCRIBE_STOP_SCAN 6

bool libtock_wifi_driver_exists(void);

// Wi-Fi Allow syscalls
returncode_t libtock_wifi_set_readonly_allow_ssid(const uint8_t* buffer, uint32_t len);
returncode_t libtock_wifi_set_readonly_allow_pass(const uint8_t* buffer, uint32_t len);
returncode_t libtock_wifi_set_readwrite_allow_mac(const uint8_t* buffer);
returncode_t libtock_wifi_set_readwrite_allow_ssid(const uint8_t* buffer, uint32_t len);

// Wi-Fi Subscribe syscall
returncode_t libtock_wifi_set_upcall_join(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_leave(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_ap(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_sta(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_start_scan(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_stop_scan(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_scanned(subscribe_upcall callback, void* opaque);
returncode_t libtock_wifi_set_upcall_on(subscribe_upcall callback, void* opaque);

// Wi-Fi command syscall
returncode_t libtock_wifi_command_mac(void);
returncode_t libtock_wifi_command_ap(uint8_t security, uint8_t channel);
returncode_t libtock_wifi_command_sta(void);
returncode_t libtock_wifi_command_join(uint8_t security);
returncode_t libtock_wifi_command_leave(void);
returncode_t libtock_wifi_command_start_scan(void);
returncode_t libtock_wifi_command_stop_scan(void);
returncode_t libtock_wifi_command_on(void);

#ifdef __cplusplus
}
#endif
