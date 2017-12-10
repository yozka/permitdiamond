#include "pdWorkerWiFi.h"
#include "pdSettings.h"
#include "pdOptions.h"

#include <ESP8266WiFi.h>
///--------------------------------------------------------------------------------------



using namespace Network;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AWorkerWiFi :: AWorkerWiFi(Stream *stream, Options::AOptions *options)
	:
	mStream(stream),
	mOptions(options)
{
	
}
///--------------------------------------------------------------------------------------





///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AWorkerWiFi::~AWorkerWiFi()
{

}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// Начальная настройка
/// 
/// 
///--------------------------------------------------------------------------------------
void AWorkerWiFi::begin()
{
	reconnect();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// подключение к точке доступа
/// 
/// 
///--------------------------------------------------------------------------------------
void AWorkerWiFi :: connect(const String &ssid, const String &password)
{
	if (mOptions)
	{
		mOptions->setSsid(ssid);
		mOptions->setPassword(password);
	}
	reconnect();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// подключение к точке доступа
/// 
/// 
///--------------------------------------------------------------------------------------
void AWorkerWiFi :: reconnect()
{
	if (mOptions == nullptr)
	{
		mStream->println(F("Ошибка, система настроек не работает."));
		return;
	}
	WiFi.hostname(mOptions->name());

	const auto ssid		= mOptions->ssid();
	const auto password = mOptions->password();

	WiFi.disconnect();

	if (ssid.length() == 0)
	{
		return;
	}

	mStream->print(F("Соеденение с WiFi: "));
	mStream->print(ssid);
	
	//mStream->print("["); mStream->print(password); mStream->print("]");
	
	WiFi.begin(ssid.c_str(), password.c_str());
	while (WiFi.status() != WL_CONNECTED)
	{
		if (WiFi.status() == WL_CONNECT_FAILED)
		{
			mStream->println(F(" ОШИБКА!!!"));
			return;
		}

		if (WiFi.status() == WL_NO_SSID_AVAIL)
		{
			mStream->println(F(" Точка доступа не найденна!!!"));
			return;
		}

		delay(500);
		mStream->print(".");
	}
	mStream->println(F(" соеденение установленно"));
}
///--------------------------------------------------------------------------------------


/*
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>





WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacekt[] = "Hi there! Got the message :-)";  // a reply string to send back







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