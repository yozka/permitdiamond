#include "pdSecurityTokenPolicy.h"
#include "pdString.h"

using namespace Network::STP;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ASecurityTokenPolicy :: ASecurityTokenPolicy()
{
	memset(&mHash, 0, sizeof(TSelectorHash));
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ASecurityTokenPolicy :: ~ASecurityTokenPolicy()
{

}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// установка токена
/// 
/// 
///--------------------------------------------------------------------------------------
void ASecurityTokenPolicy:: setToken(const String &token)
{
	memset(mHash.token, 0, sizeof(TSelectorHash::token));
	//token.toCharArray((char*)mHash.token, sizeof(Protocol::TCalcHash::token));
	const int len = min(token.length(), 11);
	for (int i = 0; i < len; i++)
	{
		mHash.token[i] = token.charAt(i);
	}
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// получить текущий токен
/// 
/// 
///--------------------------------------------------------------------------------------
String ASecurityTokenPolicy :: token()const
{
	String s;
	for (int i = 0; i < sizeof(TSelectorHash::token); i++)
	{
		s += String((char)mHash.token[i]);
	}
	return s;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// проверка на безопасность данных
/// 
/// 
///--------------------------------------------------------------------------------------
bool ASecurityTokenPolicy :: securityCheck(const APacket &packet)
{
	//проверка хеша подписи
	//хешь считается от Sequince + typeCommand + token
	const auto header = packet.header();
	
	mHash.sequence		= header->sequence;
	mHash.typeAction	= header->typeAction;

	mMD5.update((char*)&mHash, sizeof(TSelectorHash));
	mMD5.finalize();
	if (!mMD5.equals(header->stp))
	{
		//!!!хешь не совпадает, нас ктото хочет хакнуть
		Serial.println("INVALID HASH!!");
		return false;
	}
	//

	return true;
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// подписывание пакета
/// 
/// 
///--------------------------------------------------------------------------------------
void ASecurityTokenPolicy :: sign(const APacket &receiv, APacket &send)
{
	//проверка хеша подписи
	//хешь считается от Sequince + typeCommand + token
	const auto *headerReceiv = receiv.header();
	auto *header = send.header();

	
	//сформировали заголовок
	header->SRC			= Protocol::SRC;
	header->typeAction	= headerReceiv->typeAction;
	header->sequence	= headerReceiv->sequence;


	//подпишем его
	mHash.sequence		= header->sequence;
	mHash.typeAction	= header->typeAction;

	mMD5.update((char*)&mHash, sizeof(TSelectorHash));
	mMD5.finalize();
	mMD5.copyTo(header->stp);
}
///--------------------------------------------------------------------------------------

