#pragma once

#include "../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  WPA1     = 1,
  WPA2     = 2,
  WPA2WPA3 = 3,
  WPA3     = 4
} security_e;

typedef struct mac_addr {
  uint8_t addr[6];
} mac_addr_t;

typedef struct ssid {
  char ssid[32];
} ssid_t;

typedef struct passphrase {
  char pass[64];
  security_e security;
} passphrase_t;

typedef void (*libtock_wifi_callback_scanned) (uint8_t);
typedef void (*libtock_wifi_callback_command_done) (returncode_t);

bool libtock_wifi_exists(void);

// Configure the Wi-Fi as STA (station).
returncode_t libtock_wifi_sta(libtock_wifi_callback_command_done callback);

// Turn the Wi-Fi device on.
returncode_t libtock_wifi_on(libtock_wifi_callback_command_done callback);

// Get MAC address
returncode_t libtock_wifi_mac(mac_addr_t* mac_addr);

// Configure the Wi-Fi as an open AP (access point).
returncode_t libtock_wifi_ap_open(uint8_t channel, ssid_t* ssid, libtock_wifi_callback_command_done callback);

// Configure the Wi-Fi as an AP (access point) with security passphrase.
returncode_t libtock_wifi_ap(
  uint8_t                            channel,
  ssid_t*                            ssid,
  passphrase_t*                      passphrase,
  libtock_wifi_callback_command_done callback);

// Join an open network.
returncode_t libtock_wifi_join_open(ssid_t* ssid, libtock_wifi_callback_command_done callback);

// Join a secure network.
returncode_t libtock_wifi_join(ssid_t* ssid, passphrase_t* passphrase, libtock_wifi_callback_command_done callback);

// Start scanning.
returncode_t libtock_wifi_scan(ssid_t* ssid, libtock_wifi_callback_scanned callback);

#ifdef __cplusplus
}
#endif
