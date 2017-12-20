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
		/// ������� ��� ���������
		/// 
		///
		///------------------------------------------------------------------------
		class ACommand
		{

		public:

			
			ACommand();			//constructor
			virtual ~ACommand();	//destructor



			//����������� �����������
			ACommand& operator = (const ACommand&) = delete;
			ACommand(const ACommand&) = delete;
		
		


		private:


		};


		using PCommand = QSharedPointer<ACommand>;

	}
}