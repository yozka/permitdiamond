#pragma once
#include <QObject>
#include <QVector>
//-----------------------------------------------------------------------------
#include "dsClientAddress.h"
#include "dsCommand.h"
//-----------------------------------------------------------------------------



namespace Server
{
	namespace Protocol
	{
		//-------------------------------------------------------------------------





		 ///-----------------------------------------------------------------------
		///
		/// Протокол общения между клиентом и сервером
		/// 
		///
		///------------------------------------------------------------------------
		class AProtocol
			:
			public QObject
		{
			Q_OBJECT

		public:

			
			AProtocol();			//constructor
			virtual ~AProtocol();	//destructor



			void append(const PCommand &command); //добавление команды


			//заблокируем копирование
			AProtocol& operator = (const AProtocol&) = delete;
			AProtocol(const AProtocol&) = delete;
		
		public slots:


			void slot_receiv(const QByteArray &packet, const AClientAddress &address);// данные пришли



		private:

			QVector<PCommand> mCommands;


		};




	}
}