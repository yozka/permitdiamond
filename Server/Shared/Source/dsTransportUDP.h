#pragma once
#include <QUdpSocket>
#include <QByteArray>
//-----------------------------------------------------------------------------
#include "dsClientAddress.h"
//-----------------------------------------------------------------------------




namespace Server
{
	namespace Transport
	{
		//-------------------------------------------------------------------------





		 ///-----------------------------------------------------------------------
		///
		/// Система транспорта данных
		/// 
		///
		///------------------------------------------------------------------------
		class ATransportUDP
			:
			public QObject
		{
			Q_OBJECT

		public:

			//constructor
			ATransportUDP();
			virtual ~ATransportUDP(); //destructor

			void bind(const int port); //начало отправки сообщений по указанному порту

			void sendBroadcast(const QByteArray &packet); //отправить всем
			void send(const QByteArray &packet, const AClientAddress &address); //отправка конкретному узлу




			//заблокируем копирование
			ATransportUDP& operator = (const ATransportUDP&) = delete;
			ATransportUDP(const ATransportUDP&) = delete;


		signals:

			void signal_receiv(const QByteArray &packet, const AClientAddress &address);// данные пришли


		


		private:
			QUdpSocket	mSocket;



			void slot_readData(); //пришли данные
		};




	}
}