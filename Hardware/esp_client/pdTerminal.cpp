#include "Arduino.h"
#include "pdTerminal.h"

using namespace Terminal;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ATerminal::ATerminal(Stream *stream, const int maxCmds)
	: 
		mStream(stream),
		mCmdIndex(0),
		mMaxCmds(maxCmds)
{
	mCommands	= new TRegCommand[mMaxCmds];
};
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ATerminal::~ATerminal() 
{
	delete[] mCommands;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Добавление комманд
/// 
/// 
///--------------------------------------------------------------------------------------
bool ATerminal ::addCommand(const String &name, const String &description, const FAction action)
{
	if (mCmdIndex >= mMaxCmds) 
	{
		return false;
	}
	
	const int index = mCmdIndex;
	mCmdIndex++;
	
	TRegCommand *cmd = &mCommands[index];
	cmd->name = name;
	cmd->actionExec = action;
	cmd->description = description;
	return true;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// обработка потока данных
/// 
/// 
///--------------------------------------------------------------------------------------
void ATerminal :: update() 
{
	if (mStream ==  nullptr)
	{
		return;
	}
	

	while (mStream->available())
	{
		char c = mStream->read();
		switch (c)
		{
		case '.':
		case ',':
		case '0' ... '9' :
		case 'A' ... 'z' :
			{
				mBuffer += c;
				mStream->write(c);
				break;
			}
		case KEY_BS:
		case KEY_DEL:
			{
				if (mBuffer.length() > 0)
				{
					mBuffer = mBuffer.substring(0, mBuffer.length() - 1);
					mStream->write(KEY_DEL);
				}
				break;
			}

		case KEY_CR:
			{
				mStream->println();
				anaylseLine(mBuffer);
				mBuffer = String();
				break;
			}

		default:
			break;
		}
	}
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// покажем помощь
/// 
/// 
///--------------------------------------------------------------------------------------
void ATerminal :: printHelp() 
{
	commandHelp();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// установка текущего потока
/// 
/// 
///--------------------------------------------------------------------------------------
void ATerminal :: setStream(Stream* stream) 
{
	mStream = stream;
}
///--------------------------------------------------------------------------------------





/// PRIVATE




 ///=====================================================================================
///
/// fанализ линии
/// 
/// 
///--------------------------------------------------------------------------------------
void ATerminal:: anaylseLine(const String &line) 
{
	if (line.length() == 0)
	{
		return;

	}
	String cmd = getFirstWord(line);
	if (cmd.equals(Settings::CMD_HELP)) 
	{
		commandHelp();
		return;
	}
	
	

	// обработка команд
	for (int i = 0; i < mCmdIndex; i++) 
	{
		const auto *command = &mCommands[i];
		if (cmd.equals(command->name))
		{
			command->actionExec(cmd, line);
			return;
		}
	}

	mStream->print("Unknown command : ");
	mStream->println(cmd);
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// найти первое входящее слово
/// 
/// 
///--------------------------------------------------------------------------------------
String ATerminal :: getFirstWord(const String & line) 
{
	int firstSpace = line.indexOf(' ');
	if (firstSpace == -1) 
	{
		firstSpace = line.length();
	}
	return line.substring(0, firstSpace);
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Показать помощь
/// 
/// 
///--------------------------------------------------------------------------------------
void ATerminal::commandHelp() 
{
	mStream->println("==================================");
	mStream->println("          System terminal");
	mStream->println("==================================");
	mStream->println("commands available : ");
	mStream->print(" - ");
	mStream->println(Settings::CMD_HELP);
	

	for (int i = 0; i < mCmdIndex; i++) 
	{
		const auto *command = &mCommands[i];
		mStream->print(" - ");
		mStream->print(command->name);
		mStream->print(" ");
		mStream->println(command->description);
	}
	mStream->println("==================================");
}
///--------------------------------------------------------------------------------------










