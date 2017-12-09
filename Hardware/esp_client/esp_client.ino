#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "pdTerminal.h"



Terminal::ATerminal terminal(&Serial, 10);


const char* ssid = "Zoopark";
const char* password = "dfokldfsjnjfri545kghqp9";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacekt[] = "Hi there! Got the message :-)";  // a reply string to send back


void setup()
{
    Serial.begin(9600);
    Serial.println();


	terminal.addCommand("list", "WiFi point" , [](const String &cmd, const String &line)
									{

	});


    Serial.printf("Connecting to %s ", ssid);
    
	WiFi.hostname("Fablab permit");
	WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" connected");

    Udp.begin(localUdpPort);
    Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
	terminal.update();

	/*
    int packetSize = Udp.parsePacket();
    if (packetSize)
    {
      // receive incoming UDP packets
      Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
      int len = Udp.read(incomingPacket, 255);
      if (len > 0)
      {
          incomingPacket[len] = 0;
      }
      Serial.printf("UDP packet contents: %s\n", incomingPacket);

      // send back a reply, to the IP address and port we got the packet from
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(incomingPacket, len);
      Udp.endPacket();
    }
	*/
}
