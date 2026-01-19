#ifndef WIFI_MANAGER_H

#define WIFI_MANAGER_H

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif_net_stack.h"
#include "esp_netif.h"
#include "nvs_flash.h"
#include "lwip/inet.h"
#include "lwip/netdb.h"
#include "lwip/sockets.h"
#if IP_NAPT
#include "lwip/lwip_napt.h"
#endif
#include "lwip/err.h"
#include "lwip/sys.h"

//extern bool s_is_in_ap_mode;
extern char s_last_ssid[32];
extern char s_last_password[64];



esp_err_t wifi_manager_init(void);

esp_err_t wifi_manager_reinit_sta(void);

void wifi_manager_scan_network(void);

void wifi_scan(); // in scaner.c

esp_err_t load_wifi_config_from_nvs(void);

esp_err_t save_wifi_config_to_nvs(const char *ssid, const char *password);

#endif