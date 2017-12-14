#pragma once
#include <QSharedPointer>
#include <QHostAddress>
//-----------------------------------------------------------------------------



namespace Server
{
	//-------------------------------------------------------------------------





	 ///-----------------------------------------------------------------------
	///
	/// ����� �������
	/// 
	///
	///------------------------------------------------------------------------
	class AClientAddress
	{

	public:

		//constructor
		AClientAddress(const QHostAddress &host, const int port);
		virtual ~AClientAddress(); //destructor

			

		QHostAddress host()const; //��������� ���� ������
		int port()const; //��������� ���� ������
	


	private:
		
		QHostAddress mHost;
		int mPort;


	};


	using PClientAddress = QSharedPointer<AClientAddress>;

}
