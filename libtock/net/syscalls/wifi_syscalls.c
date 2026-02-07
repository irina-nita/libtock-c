#include "wifi_syscalls.h"

bool libtock_wifi_driver_exists(void) {
  return driver_exists(DRIVER_NUM_WIFI);
}

// Wi-Fi Allow syscalls
returncode_t libtock_wifi_set_readonly_allow_ssid(const uint8_t* buffer, uint32_t len) {
  allow_ro_return_t aval = allow_readonly(DRIVER_NUM_WIFI, ALLOW_RO_SSID, (void*)buffer, len);
  return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_wifi_set_readonly_allow_pass(const uint8_t* buffer, uint32_t len) {
  allow_ro_return_t aval = allow_readonly(DRIVER_NUM_WIFI, ALLOW_RO_PASS, (void*)buffer, len);
  return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_wifi_set_readwrite_allow_mac(const uint8_t* buffer) {
  allow_rw_return_t aval = allow_readwrite(DRIVER_NUM_WIFI, ALLOW_RW_MAC, (void*)buffer, 6);
  return tock_allow_rw_return_to_returncode(aval);
}

returncode_t libtock_wifi_set_readwrite_allow_ssid(const uint8_t* buffer, uint32_t len) {
  allow_rw_return_t aval = allow_readwrite(DRIVER_NUM_WIFI, ALLOW_RW_SCAN_SSID, (void*)buffer, len);
  return tock_allow_rw_return_to_returncode(aval);
}

// Wi-Fi Subscribe syscalls
returncode_t libtock_wifi_set_upcall_join(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_JOIN_NETWORK, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_leave(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_LEAVE_NETWORK, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_ap(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_SET_MODE_AP, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_sta(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_SET_MODE_STA, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_start_scan(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_START_SCAN, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_stop_scan(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_STOP_SCAN, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_scanned(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_SCAN_RES, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_wifi_set_upcall_on(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_WIFI, SUBSCRIBE_ON, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

// Wi-Fi command syscalls
returncode_t libtock_wifi_command_mac(void) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_GET_MAC, 0, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_ap(uint8_t security, uint8_t channel) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_SET_MODE_AP, security, channel);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_sta(void) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_SET_MODE_STA, 0, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_join(uint8_t security) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_JOIN_NETWORK, security, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_leave(void) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_LEAVE_NETWORK, 0, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_start_scan(void) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_START_SCAN, 0, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_stop_scan(void) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_STOP_SCAN, 0, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtock_wifi_command_on(void) {
  syscall_return_t cval = command(DRIVER_NUM_WIFI, COMMAND_ON, 0, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

