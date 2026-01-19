idf_component_register(SRCS "wifi_manager/wifi_manager.c" "wifi_manager/wifi_manager_connect.c" "wifi_manager/wifi_manager_scaner.c" "softap_sta.c"
                    PRIV_REQUIRES esp_wifi nvs_flash
                    INCLUDE_DIRS "." "wifi_manager")
