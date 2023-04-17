
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <DNSServer.h>
#include "esp_wifi.h"
// Replace with your network credentials
const char* ssid = "testtttt";
//set to null for open ap
const char* password = NULL;//"testtest";
typedef uint8_t MacAddr[6];
uint8_t buffer[200];
uint16_t seqnum;


const byte DNS_PORT = 53;
DNSServer dnsServer;
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

 
void setup(){
  Serial.begin(115200);
  Serial.println("starting...");
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  WiFi.softAP(ssid, password);

  //point all dns entries to this IP for captive portal
  dnsServer.start(53, "*", IPAddress(192, 168, 4, 1));
  
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });
  //server everything else statically
  server.serveStatic("/", SPIFFS, "/");
  server.begin();
}
 
void loop(){
  dnsServer.processNextRequest();
}
