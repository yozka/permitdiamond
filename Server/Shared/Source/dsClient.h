#pragma once
#include <QObject>
#include <QSharedPointer>
//-----------------------------------------------------------------------------



namespace Server
{
	namespace Client
	{
		//-------------------------------------------------------------------------





		 ///-----------------------------------------------------------------------
		///
		/// Сам клиент
		/// 
		///
		///------------------------------------------------------------------------
		class AClient
			:
				public QObject
		{
			Q_OBJECT

		public:

			//constructor
			AClient();
			virtual ~AClient(); //destructor



		



		private:

			


		};


		using PClient = QSharedPointer<AClient>;

	}
}
