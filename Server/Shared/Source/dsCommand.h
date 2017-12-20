#pragma once
#include <QSharedPointer>
//-----------------------------------------------------------------------------



namespace Server
{
	namespace Protocol
	{
		//-------------------------------------------------------------------------





		 ///-----------------------------------------------------------------------
		///
		///  оманда дл€ протокола
		/// 
		///
		///------------------------------------------------------------------------
		class ACommand
		{

		public:

			
			ACommand();			//constructor
			virtual ~ACommand();	//destructor



			//заблокируем копирование
			ACommand& operator = (const ACommand&) = delete;
			ACommand(const ACommand&) = delete;
		
		


		private:


		};


		using PCommand = QSharedPointer<ACommand>;

	}
}