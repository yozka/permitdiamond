#pragma once
#include <QSharedPointer>
#include <QHostAddress>
//-----------------------------------------------------------------------------



namespace Server
{
	//-------------------------------------------------------------------------





	 ///-----------------------------------------------------------------------
	///
	/// Адрес клиента
	/// 
	///
	///------------------------------------------------------------------------
	class AClientAddress
	{

	public:

		//constructor
		AClientAddress(const QHostAddress &host, const int port);
		virtual ~AClientAddress(); //destructor

			

		QHostAddress host()const; //возвратим хост адреса
		int port()const; //возвратим порт адреса
	


	private:
		
		QHostAddress mHost;
		int mPort;


	};


	using PClientAddress = QSharedPointer<AClientAddress>;

}
