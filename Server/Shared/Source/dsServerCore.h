#pragma once
#include <QSharedPointer>
#include <QTimer>
#include <QList>
//-----------------------------------------------------------------------------
#include "dsTransportUDP.h"
#include "dsProtocol.h"
#include "dsClient.h"
//-----------------------------------------------------------------------------





//-----------------------------------------------------------------------------
namespace Server
{
	//-------------------------------------------------------------------------



	 ///-----------------------------------------------------------------------
	///
	/// основной сервер
	///
	///
	///------------------------------------------------------------------------
	class AServerCore
		:
			public QObject
	{
		Q_OBJECT

	public:

		//constructor
		AServerCore();
		virtual ~AServerCore(); //destructor
		


		void run(); //запуск сервера

		
					//заблокируем копирование
		AServerCore& operator = (const AServerCore&) = delete;
		AServerCore(const AServerCore&) = delete;


	private:

		QTimer						mProcessing;
		Transport::ATransportUDP	mTransport;
		Protocol::AProtocol			mProtocol;
		QList<Client::PClient>		mClients; //список клиентов


		void slot_update(); //время выполнения
	};



	using PServerCore = QSharedPointer<AServerCore>;

}