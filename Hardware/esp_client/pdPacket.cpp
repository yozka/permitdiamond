﻿#include "pdPacket.h"

using namespace Network;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
APacket :: APacket()
	:
	mSize(0)
{
	memset(mData, 0, sizeof(mData));
}
///--------------------------------------------------------------------------------------





///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
APacket :: ~APacket()
{

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// создание пакета
/// 
/// 
///--------------------------------------------------------------------------------------
void APacket :: create(const int size)
{
	memset(mData, 0, sizeof(mData));
	mSize = size;
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// возвратим указатель на данные
/// 
/// 
///--------------------------------------------------------------------------------------
unsigned char* APacket :: data()
{
	return mData;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// возратим размерность данных
/// 
/// 
///--------------------------------------------------------------------------------------
int APacket::size() const
{
	return mSize;
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// проверка, пакет валидный или нет
/// 
/// 
///--------------------------------------------------------------------------------------
bool APacket::isValid() const
{
	if (mSize <= sizeof(Protocol::THeader))
	{
		//пакет маленький, пришло какоето гавно
		return false;
	}

	const auto *header = (Protocol::THeader*)mData;
	if (header->SRC != Protocol::SRC)
	{
		//проблема с магическим числом. пакет неверный
		return false;
	}

	//пакет в норме
	return true;
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// возвратим указатель на заголовок
/// 
/// 
///--------------------------------------------------------------------------------------
Protocol::THeader* APacket::header()const
{
	return (Protocol::THeader*)mData;
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// возратим тип пакета действий
/// 
/// 
///--------------------------------------------------------------------------------------
int APacket::typeAction() const
{
	const auto *header = (Protocol::THeader*)mData;
	return header->typeAction;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// чистка всего пакета
/// 
/// 
///--------------------------------------------------------------------------------------
void APacket :: clear()
{
	memset(mData, 0, sizeof(mData));
	mSize = 0;
}
///--------------------------------------------------------------------------------------


