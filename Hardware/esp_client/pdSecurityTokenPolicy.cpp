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
/// ��������� ������
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
/// �������� ������� �����
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
/// �������� �� ������������ ������
/// 
/// 
///--------------------------------------------------------------------------------------
bool ASecurityTokenPolicy :: securityCheck(const APacket &packet)
{
	//�������� ���� �������
	//���� ��������� �� Sequince + typeCommand + token
	const auto header = packet.header();
	
	mHash.sequence		= header->sequence;
	mHash.typeAction	= header->typeAction;

	mMD5.update((char*)&mHash, sizeof(TSelectorHash));
	mMD5.finalize();
	if (!mMD5.equals(header->stp))
	{
		//!!!���� �� ���������, ��� ����� ����� �������
		Serial.println("INVALID HASH!!");
		return false;
	}
	//

	return true;
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// ������������ ������
/// 
/// 
///--------------------------------------------------------------------------------------
void ASecurityTokenPolicy :: sign(const APacket &receiv, APacket &send)
{
	//�������� ���� �������
	//���� ��������� �� Sequince + typeCommand + token
	const auto *headerReceiv = receiv.header();
	auto *header = send.header();

	
	//������������ ���������
	header->SRC			= Protocol::SRC;
	header->typeAction	= headerReceiv->typeAction;
	header->sequence	= headerReceiv->sequence;


	//�������� ���
	mHash.sequence		= header->sequence;
	mHash.typeAction	= header->typeAction;

	mMD5.update((char*)&mHash, sizeof(TSelectorHash));
	mMD5.finalize();
	mMD5.copyTo(header->stp);
}
///--------------------------------------------------------------------------------------

