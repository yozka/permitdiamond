#pragma once
#include <Arduino.h>
namespace Network
{
	///--------------------------------------------------------------------------------------
	namespace Protocol
	{
		const int packetMaxSize = 0xFF; //������ ������ ��� �������
		const int SRC			= 0x9A; //����������� ������

		#pragma push pack(1)
	
		//��������� ������
		struct THeader
		{
			uint8_t		SRC;		//���������� ����� ������������� ������
			uint8_t		typeAction; //��� �������
			uint32_t	sequence;	//����������� ������
			uint8_t		stp[16];	//���� ������ �������
		};
		//
		




		#pragma pop pack


	}
	///--------------------------------------------------------------------------------------
}
