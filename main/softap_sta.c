/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
/*  WiFi softAP & station Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
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
#include "wifi_manager.h"


void app_main(void)
{
    
    ESP_ERROR_CHECK(esp_event_loop_create_default());

   wifi_manager_init();

   vTaskDelay(pdMS_TO_TICKS(10000));
   
   wifi_manager_scan_network();

   for (;;) {
       vTaskDelay(pdMS_TO_TICKS(10000));
       size_t free = esp_get_free_heap_size();
            size_t min = heap_caps_get_minimum_free_size(MALLOC_CAP_8BIT);
            size_t largest = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
            uint32_t frag = (free > 0) ? (100 - (largest * 100) / free) : 0;

            ESP_LOGI("RAM_MONITOR", "📊 RAM: %" PRIu32 "kB, min=%" PRIu32 "kB, largest=%" PRIu32 "kB, frag=%" PRIu32 "%%",
                    (uint32_t)(free / 1024),
                    (uint32_t)(min / 1024),
                    (uint32_t)(largest / 1024),
                    frag);
       //wifi_manager_reinit_sta();
       vTaskDelay(pdMS_TO_TICKS(1000));
       //wifi_manager_scan_network(); //сканирование доступно только если нет подключения к роутеру
   }
   
}
