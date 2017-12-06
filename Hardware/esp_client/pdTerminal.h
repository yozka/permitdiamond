#pragma once

#include <Arduino.h>

namespace Settings
{

	#define SIMPLETERMINAL_FLOAT_DECIMAL 10

	#define CMD_HELP		"help"
	#define CMD_VARIABLE	"variable"
	#define CMD_SET_VAR		"set"
	#define CMD_GET_VAR		"get"
}

namespace Terminal
{
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Тип настроечных переменных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	enum EVariantType
	{
		BOOL,
		INT,
		LONG,
		FLOAT,
		DOUBLE,
		STRING
	};
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// обработчик лямбд функций функций
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	using FAction	= void(*)(const String&, const String&);		
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// хранилище переменных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	using TRegVariant = struct 
	{
		String			name;
		EVariantType	type;
		void*			value;
		FAction			actionChange;
	};
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// хранилище команд
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	using TRegCommand = struct
	{
		String		name;
		String		description;
		FAction		actionExec;
	};
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Терминал
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ATerminal 
	{
	public:
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Constructor.
		/// Create the arrays for the variables and the commands.
		///
		///  @param stream stream to listen to
		///  @param maxCmds size of the commands array
		///	 @param maxVars size of the variables array
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		ATerminal(Stream *stream, const int maxCmds = 5, const int maxVars = 5);
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Destructor
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		virtual ~ATerminal();
		///--------------------------------------------------------------------------------------





		 ///=====================================================================================
		///
		/// Add a variable
		/// @param name name of the variable(must be unique)
		/// @param type the type of the variable(see VarType enum)
		/// @param ptr pointer to the variable
		/// @param fnPtr(optional) pointer to the callback invoked when the variables changed
		/// @return true if the action succeed(false if there is no more space for variables)
		/// 
		/// 
		///--------------------------------------------------------------------------------------
		bool addVariable(const String &name, const EVariantType type, void *value = nullptr, const FAction action = nullptr);

		/**
		* Add a command
		* @param name name of the command (must be unique)
		* @param fnPtr pointer to the callback of the command
		* @param description (optional) description of the command (will be printed to help)
		* @return
		*/
		bool addCommand(String name, const void *fnPtr, String description = "");

		/**
		* Enable or disable all variables (default is true, enabled)
		* @param newValue
		*/
		void setVarCmdEnabled(bool enabled);

		/**
		* Enable or disable the confirmation when a variable is set (default is true, enabled)
		* @param newValue
		*/
		void setConfirmPrintVar(bool enabled);

		/**
		* Run the system.
		*
		* Should be invoked every Arduino loop for fast response or some times if time is not
		* critical (do not wait to much to not overflow the Stream buffer)
		*/
		void run();

		/**
		* Programatically print help (equivalent of typing 'help' in the terminal)
		*/
		void printHelp();

		/**
		* Print the variables (equivalent of typing 'printenv' in the terminal)
		*/
		void printEnv();

		/**
		* Redefine the stream. Normally you should use the constructor parameter but sometimes
		* you need to define the stream afterward.
		* @param stream
		*/
		void setStream(Stream *stream);

	private:

		void anaylseLine(String &line);
		String getFirstWord(String &line);
		void commandHelp();
		void commandPrintEnv();
		void commandSet(String &line);
		void commandGet(String &line);
		void printVar(RegVar *var);

		bool varCmdEnabled = true;
		bool confirmPrintVar = true;

		int maxVars;
		int maxCmds;
		int varIndex = 0;
		int cmdIndex = 0;
		RegVar* vars;
		RegCmd* cmds;

		Stream* stream;

		String buffer;

		String VarTypePretty[] = { "BOOL", "INT", "LONG", "FLOAT", "DOUBLE" };

	};

}
