| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-S2 | ESP32-S3 | ESP32-P4 | ESP32-H2 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | --------- | -------- | -------- | -------- | -------- |

# 🚀 ESP32 Wi-Fi Bridge Manager

Проект для запуска ESP32 в режиме **AP + STA** с **NAPT**, **автоподключением**, **сохранением Wi-Fi в NVS** и **полной поддержкой Android/iOS/Windows**.

## ✅ Особенности

- 🛰️ Режим точки доступа + клиент (AP+STA)
- 🔐 Сохраняет SSID/пароль в NVS
- 🔄 Автоматическое переподключение
- 🌐 NAPT — клиенты используют интернет через STA
- 📡 Проброс DNS от роутера
- 🌍 Поддержка mDNS: `my_esp32_host.local`
- 📶 Сканирование доступных сетей
- 🧠 Мониторинг RAM
- 💻 Решение для Windows (см. ниже)
- 📄 Лёгкий встраиваемый код

## 📦 Установка

```bash
git clone https://github.com/cheldonec/esp32-wifi-bridge-manager.git
cd esp32-wifi-bridge-manager
idf.py build flash monitor
```

## 💻 Решение для Windows (ситуация, когда windows отключается от ESP при отсутствии интернета)
Registry Hive   HKEY_LOCAL_MACHINE
Registry Path   Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator
Value Name  NoActiveProbe
Value Type  REG_DWORD
Enabled Value   1
Disabled Value  0
