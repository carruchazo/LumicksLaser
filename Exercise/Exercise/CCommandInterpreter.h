#pragma once

#include <string>
#include "ILaserController.h"

namespace NS_Laser_Controller
{
	/// \brief Class that interprets the laser commands and communicates with an object ILaserController
	class CCommandInterpreter
	{
	public:

		enum class CommandId
		{
			CMD_START,
			CMD_STOP,
			CMD_GET_EMISSION_STATUS,
			CMD_GET_POWER,
			CMD_SET_POWER,
			CMD_KEEP_ALIVE
		};

		CCommandInterpreter();

		~CCommandInterpreter();

		void SetPointerToLaserController(ILaserController* pLaserController);

		/// \brief Interprets command for controller
		/// \return Response from controller
		std::string ParseCommand(std::string wholeCommand);

	protected:
		ILaserController* mpLaserController;

		/// \brief Calls the appropriate interface function from ILaserController
		/// return A string containing the response from controller
		std::string SendCommand(CommandId command, int value = 0);
	};

}
