#include <WiFi.h>
#include <esp_now.h>

HardwareSerial Link(1);

void onReceive(
    const esp_now_recv_info_t *info,
    const uint8_t *data,
    int len)
{
    if (len > 0)
    {
        char c = (char)data[0];

        Serial.print("RX: ");
        Serial.println(c);

        Link.write(c);
    }
}

void setup()
{
    Serial.begin(115200);

    // RX=-1, TX=GPIO8
    Link.begin(115200, SERIAL_8N1, -1, 8);

    WiFi.mode(WIFI_STA);

    Serial.print("MAC: ");
    Serial.println(WiFi.macAddress());

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW init failed");
        while (1);
    }

    esp_now_register_recv_cb(onReceive);

    Serial.println("Receiver Ready");
}

void loop()
{
}