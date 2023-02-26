#include <WifiClient.h>
#include <WebServer.h>

void WifiClient::connect(const char *ssid,const char *pswd)
{
  Serial.print("Connecting to Wi-Fi");

  WiFi.begin(ssid, pswd);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Connected!");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}
