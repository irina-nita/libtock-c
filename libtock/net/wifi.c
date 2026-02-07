#include <string.h>

#include "syscalls/wifi_syscalls.h"
#include "wifi.h"
#include <stdio.h>

#define SECURITY_OPEN 0

static void wifi_upcall(int status,
                        __attribute__ ((unused)) int unused1,
                        __attribute__ ((unused)) int unused2,
                        void*                        opaque) {
  libtock_wifi_callback_command_done cb = (libtock_wifi_callback_command_done)opaque;
  cb(tock_status_to_returncode(status));
}

bool libtock_wifi_exists(void) {
  return libtock_wifi_driver_exists();
}

returncode_t libtock_wifi_on(libtock_wifi_callback_command_done callback) {
  returncode_t ret;
  ret = libtock_wifi_set_upcall_on(wifi_upcall, callback);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_on();
}

returncode_t libtock_wifi_mac(mac_addr_t* mac_addr) {
  returncode_t ret;
  ret = libtock_wifi_set_readwrite_allow_mac(*mac_addr);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_mac();
}

returncode_t libtock_wifi_sta(libtock_wifi_callback_command_done callback) {
  returncode_t ret;

  ret = libtock_wifi_set_upcall_sta(wifi_upcall, callback);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_sta();
}

returncode_t libtock_wifi_ap_open(uint8_t                            channel,
                                  ssid_t*                            ssid,
                                  libtock_wifi_callback_command_done callback) {
  returncode_t ret;

  ret = libtock_wifi_set_readonly_allow_ssid((uint8_t*)(*ssid), strlen(*ssid));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_upcall_ap(wifi_upcall, callback);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_ap(SECURITY_OPEN, channel);
}

returncode_t libtock_wifi_ap(uint8_t                            channel,
                             ssid_t*                            ssid,
                             passphrase_t*                      passphrase,
                             libtock_wifi_callback_command_done callback) {
  returncode_t ret;

  ret = libtock_wifi_set_readonly_allow_ssid((uint8_t*)(*ssid), strlen(*ssid));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_readonly_allow_pass((uint8_t*)(passphrase->pass), strlen(passphrase->pass));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_upcall_ap(wifi_upcall, callback);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_ap(passphrase->security, channel);
}

returncode_t libtock_wifi_join_open(ssid_t* ssid, libtock_wifi_callback_command_done callback) {
  returncode_t ret;

  ret = libtock_wifi_set_readonly_allow_ssid((uint8_t*)(*ssid), strlen(*ssid));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_upcall_join(wifi_upcall, callback);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_join(SECURITY_OPEN);
}

returncode_t libtock_wifi_join(ssid_t* ssid,
                               passphrase_t* passphrase,
                               libtock_wifi_callback_command_done callback) {
  returncode_t ret;

  ret = libtock_wifi_set_readonly_allow_ssid((uint8_t*)(*ssid), strlen(*ssid));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_readonly_allow_pass((uint8_t*)(passphrase->pass), strlen(passphrase->pass));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_upcall_join(wifi_upcall, callback);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_join(passphrase->security);
}

returncode_t libtock_wifi_scan(ssid_t* ssid,
                               libtock_wifi_callback_scanned scan_cb,
                               libtock_wifi_callback_command_done command_cb) {
  returncode_t ret;

  ret = libtock_wifi_set_readwrite_allow_ssid((uint8_t*)(*ssid), strlen(*ssid));
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_upcall_start_scan(wifi_upcall, command_cb);
  if (ret != RETURNCODE_SUCCESS) return ret;

  ret = libtock_wifi_set_upcall_scanned(wifi_upcall, scan_cb);
  if (ret != RETURNCODE_SUCCESS) return ret;

  return libtock_wifi_command_start_scan();
}
