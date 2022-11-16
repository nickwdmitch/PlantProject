#include "Wifi.h"
#include "NetworkCredentials.h"

void createWifiNetwork()
{
 	Serial.begin(115200);
 	Serial.println();
 	Serial.print("Setting soft-AP configuration ... ");
 	Serial.println(WiFi.softAPConfig(Local_IP, Gateway, Subnet) ? "Ready" : "Failed!");
 	Serial.print("Setting soft-AP ... ");
 	Serial.println(WiFi.softAP(SSID,Password) ? "Ready" : "Failed!");
	
 	//WiFi.softAP(ssid);
 	//WiFi.softAP(ssid, password, channel, hidden, max_connection)
 	
 	Serial.print("Soft-AP IP address = ");
 	Serial.println(WiFi.softAPIP());
}
void checkConnection() {
 	Serial.print("[Server Connected] ");
 	Serial.println(WiFi.softAPIP());
}