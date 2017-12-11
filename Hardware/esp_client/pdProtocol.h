#pragma once
#include <Arduino.h>
namespace Network
{
	///--------------------------------------------------------------------------------------
	namespace Protocol
	{
		const int packetMaxSize = 0xFF; //размер буфера для пакетов
		const int SRC			= 0x9A; //индификатор пакета

		#pragma push pack(1)
	
		//заголовок пакета
		struct THeader
		{
			uint8_t		SRC;		//магическое число индфификатора пакета
			uint8_t		typeAction; //тип команды
			uint32_t	sequence;	//индификатор пакета
			uint8_t		stp[16];	//хешь пакета подпись
		};
		//
		




		#pragma pop pack


	}
	///--------------------------------------------------------------------------------------
}
