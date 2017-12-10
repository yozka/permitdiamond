#include "pdNearFieldCommunication.h"


using namespace NFC;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ANearFieldCommunication::ANearFieldCommunication()
	:
	mDevice(D1, D2)
{
	
}
///--------------------------------------------------------------------------------------





///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ANearFieldCommunication::~ANearFieldCommunication()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Инциализация считывателя карт
/// 
/// 
///--------------------------------------------------------------------------------------
void ANearFieldCommunication :: begin()
{
	SPI.begin();
	mDevice.PCD_Init();
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// обработка действий
/// 
/// 
///--------------------------------------------------------------------------------------
void ANearFieldCommunication :: update()
{
	if (!mDevice.PICC_IsNewCardPresent())
	{
		return;
	}
	// Select one of the cards 
	if (!mDevice.PICC_ReadCardSerial())
	{
		return;
	}

	//пришла новая карта, запомним ее в буфере


	/*
	Serial.print("UID Tag:"); // Display the UID serial 
	String content = "";
	byte letter;
	for(byte i = 0; i < mDevice.uid.size; i++)
	{
		Serial.print(mDevice.uid.uidByte[i] <0x10 ? "0" : "");
		Serial.print(mDevice.uid.uidByte[i] HEX);
		cont.concat(String(mDevice.uid.uidByte[i] <0x10 ? "0" : ""));
		cont.concat(String(mDevice.uid.uidByte[i] HEX));
	}

	
	void dump_byte_array(byte *buffer, byte bufferSize) {
		for (byte i = 0; i < bufferSize; i++) {
			Serial.print(buffer[i] < 0x10 ? " 0" : " ");
			Serial.print(buffer[i], HEX);
		}
	}
	*/
}
///--------------------------------------------------------------------------------------

