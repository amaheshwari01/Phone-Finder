// Import Librarys and Setup Objects
#include <WiFi.h>
#include <WiFiMulti.h>
#include <TinyPICO.h>
#include <HTTPClient.h>
#include <Preferences.h>
Preferences preferences;

TinyPICO tp = TinyPICO();

WiFiMulti wifiMulti;

void setup()
{
  // Check to See if Reset Button was pressed while in the middle of the process and if itwas then dont ping again
  preferences.begin("ping", false);
  bool state = preferences.getBool("done", true);
  if (!state)
  {
    preferences.putBool("done", true);
    tp.DotStar_SetPower(false);
    esp_deep_sleep_start();
  }

  preferences.putBool("done", false);
  // LED Initialization
  tp.DotStar_Clear();
  tp.DotStar_SetBrightness(100);
  tp.DotStar_CycleColor();

  Serial.begin(115200);
  // Add As Many Wifi Networks as you would like
  wifiMulti.addAP("WIFI1", "WIFI1PASS");
  wifiMulti.addAP("WIFI2", "WIFI2PASS");

  Serial.println("Connecting to WiFi...");

  while (wifiMulti.run() != WL_CONNECTED)
  {
    // connect to wiif
  }

  Serial.println("Connected to WiFi");

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("WIFI");

    HTTPClient http;

    int httpCode = 0;
    // SEND GET REQUEST TO  SERVER
    do
    {
      tp.DotStar_SetPixelColor(255, 255, 0);

      http.begin("<Your Server URL>");          // MAKE SURE TO FILL OUT THE IP ADDRESS/URL of the Server OF THE SERVER(Port may be required)
      http.addHeader("X-API-Key", "<API KEY>"); // MAKE SURE TO FILL OUAT API KEY OF THE SERVER AND MAKE IT THE SAME AS WHAT IS SETUP IN THE PYTHON SCRIPT
      httpCode = http.GET();
      tp.DotStar_SetPixelColor(0, 0, 255);

      Serial.println("GOT");
      Serial.println(httpCode);
      if (httpCode == 200)
      {
        break;
      }
      delay(1000);
    } while (httpCode != 200);
    tp.DotStar_SetPixelColor(0, 255, 0);

    http.end();
    Serial.println("DONE");
    delay(1000);
    tp.DotStar_SetPower(false);
    preferences.putBool("done", true);

    esp_deep_sleep_start(); // conserve power when done
  }
}

void loop()
{
  Serial.println("this shouldnt print");
}
