#include "pdClient.h"
#include "pdSettings.h"


using namespace Network;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AClient :: AClient()
{
	
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AClient :: ~AClient()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Инциализация сокетов
/// 
/// 
///--------------------------------------------------------------------------------------
void AClient :: begin()
{
	mUdp.begin(Settings::client_port);
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// обработка действий
/// 
/// 
///--------------------------------------------------------------------------------------
void AClient :: update()
{
	const int available = mUdp.available();
	if (available <= 0)
	{
		//данные не пришли
		return;
	}

	//чтение пакета
	//и создание и передача его команде
	const int packetSize = mUdp.read(mBuffer, Protocol::bufferSize);
	if (packetSize <= sizeof(Protocol::THeader))
	{
		//пакет маленький, пришло какоето гавно
		return;
	}

	const auto *header = (Protocol::THeader*)mBuffer;
	if (header->SRC != Protocol::SRC)
	{
		//проблема с магическим числом. пакет неверный
		return;
	}

	//проверка хеша подписи
	//хешь считается от Sequince + typeCommand + token
	mHash.sequence = header->sequence;
	mHash.typeCommand = header->typeCommand;
	mMD5.update((char*)&mHash, sizeof(Protocol::TCalcHash));
	m

	/*
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
	*/
}
///--------------------------------------------------------------------------------------

