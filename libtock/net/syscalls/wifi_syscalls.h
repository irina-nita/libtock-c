#pragma once

#include "../../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRIVER_NUM_WIFI 0x30008

#define COMMAND_GET_MAC 1
#define COMMAND_SET_MODE_AP 2
#define COMMAND_SET_MODE_STA 3
#define COMMAND_JOIN_NETWORK 4
#define COMMAND_LEAVE_NETWORK 5
#define COMMAND_START_SCAN 6
#define COMMAND_STOP_SCAN 7
#define COMMAND_ON 101
#define COMMAND_OFF 102

#define SUBSCRIBE_JOIN_NETWORK 0
#define SUBSCRIBE_LEAVE_NETWORK 1
#define SUBSCRIBE_SET_MODE_AP 2
#define SUBSCRIBE_SET_MODE_STA 3
#define SUBSCRIBE_START_SCAN 4
#define SUBSCRIBE_STOP_SCAN 5
#define SUBSCRIBE_SCAN_RES 6
#define SUBSCRIBE_ON 7
#define SUBSCRIBE_OFF 8

#define ALLOW_RW_MAC 0
#define ALLOW_RW_SCAN_SSID 1
#define ALLOW_RO_SSID 0
#define ALLOW_RO_PASS 1

#define SECURITY_OPEN 0
#define SECURITY_WPA1 1
#define SECURITY_WPA2 2
#define SECURITY_WPA2_WPA3 3
#define SECURITY_WPA3 4

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
returncode_t libtock_wifi_set_upcall_off(subscribe_upcall callback, void* opaque);
// Wi-Fi command syscall
returncode_t libtock_wifi_command_mac(void);
returncode_t libtock_wifi_command_ap(uint8_t security, uint8_t channel);
returncode_t libtock_wifi_command_sta(void);
returncode_t libtock_wifi_command_join(uint8_t security);
returncode_t libtock_wifi_command_leave(void);
returncode_t libtock_wifi_command_start_scan(void);
returncode_t libtock_wifi_command_stop_scan(void);
returncode_t libtock_wifi_command_on(void);
returncode_t libtock_wifi_command_off(void);

#ifdef __cplusplus
}
#endif
