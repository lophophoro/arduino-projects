#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>

const char *ssid = "<wifi ssid>";
const char *password = "<password>";

ESP8266WebServer server(80);

// Serving Hello world
void getHelloWord()
{
  server.send(200, "text/json", "{\"name\": \"Hello world\"}");
}

void indoor()
{
  DynamicJsonDocument jsonData(48);
  jsonData["temperature"] = WiFi.RSSI();
  jsonData["humidity"] = WiFi.RSSI();

  Serial.print(F("getting indoor conditions..."));
  String buf;
  serializeJson(jsonData, buf);
  server.send(200, F("application/json"), buf);
  Serial.print(F("done."));
}

// Serving Hello world
void getSettings()
{
  // Allocate a temporary JsonDocument
  // Don't forget to change the capacity to match your requirements.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  //  StaticJsonDocument<512> doc;
  // You can use DynamicJsonDocument as well
  DynamicJsonDocument doc(512);

  doc["ip"] = WiFi.localIP().toString();
  doc["gw"] = WiFi.gatewayIP().toString();
  doc["nm"] = WiFi.subnetMask().toString();

  if (server.arg("signalStrength") == "true")
  {
    doc["signalStrengh"] = WiFi.RSSI();
  }

  if (server.arg("chipInfo") == "true")
  {
    doc["chipId"] = ESP.getChipId();
    doc["flashChipId"] = ESP.getFlashChipId();
    doc["flashChipSize"] = ESP.getFlashChipSize();
    doc["flashChipRealSize"] = ESP.getFlashChipRealSize();
  }
  if (server.arg("freeHeap") == "true")
  {
    doc["freeHeap"] = ESP.getFreeHeap();
  }

  Serial.print(F("Stream..."));
  String buf;
  serializeJson(doc, buf);
  server.send(200, F("application/json"), buf);
  Serial.print(F("done."));
}

// Define routing
void restServerRouting()
{
  server.on("/", HTTP_GET, []()
            { server.send(200, F("text/html"),
                          F("Welcome to the REST Web Server")); });
  server.on(F("/helloWorld"), HTTP_GET, getHelloWord);
  server.on(F("/indoor"), HTTP_GET, indoor);
  server.on(F("/settings"), HTTP_GET, getSettings);
}

// Manage not found URL
void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void)
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Activate mDNS this is used to be able to connect to the server
  // with local DNS hostmane esp8266.local
  if (MDNS.begin("esp8266"))
  {
    Serial.println("MDNS responder started");
  }

  // Set server routing
  restServerRouting();
  // Set not found response
  server.onNotFound(handleNotFound);
  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void)
{
  MDNS.update();
  server.handleClient();
}