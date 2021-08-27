#include "CCommandInterpreter.h"

namespace NS_Laser_Controller
{
	CCommandInterpreter::CCommandInterpreter()
	{
		mpLaserController = nullptr;
	}

	CCommandInterpreter::~CCommandInterpreter()
	{
	}

	void CCommandInterpreter::SetPointerToLaserController(ILaserController* pLaserController)
	{
		mpLaserController = pLaserController;
	}

	std::string CCommandInterpreter::ParseCommand(std::string wholeCommand)
	{
		if (mpLaserController != nullptr)
		{
			// Get only the command
			std::string pipe = "|";
			std::size_t pos = 0;
			int parameter = 0;
			std::string command;
			pos = wholeCommand.find(pipe);

			// Found pipe character
			if (pos != std::string::npos)
			{
				command = wholeCommand.substr(0, pos);
				parameter = std::stoi(wholeCommand.substr(pos + 1));
			}
			else
			{
				command = wholeCommand;
			}

			// Start
			if (command.compare("STR") == 0)
			{
				return SendCommand(CommandId::CMD_START);
			}
			// Stop
			else if (command.compare("STP") == 0)
			{
				return SendCommand(CommandId::CMD_STOP);
			}
			// Emission status
			else if (command.compare("ST?") == 0)
			{
				return SendCommand(CommandId::CMD_GET_EMISSION_STATUS);
			}
			// Get power
			else if (command.compare("PW?") == 0)
			{
				return SendCommand(CommandId::CMD_GET_POWER);
			}
			// Set power
			else if (command.compare("PW=") == 0)
			{
				return SendCommand(CommandId::CMD_SET_POWER, parameter);
			}
			// Keep alive
			else if (command.compare("KAL") == 0)
			{
				return SendCommand(CommandId::CMD_KEEP_ALIVE);
			}
			// Unknown command
			else
			{
				return "UK!\n"; 
			}
		}
		else
		{
			return "";
		}
	}

	std::string CCommandInterpreter::SendCommand(CommandId command, int value)
	{
		switch (command)
		{
		case CommandId::CMD_START:
			if (mpLaserController->StartEmission())
			{
				return "STR#\n";
			}
			else
			{
				return "STR!\n";
			}
			break;

		case CommandId::CMD_STOP:
			if (mpLaserController->StopEmission())
			{
				return "STP#\n";
			}
			else
			{
				return "STP!\n";
			}
			break;

		case CommandId::CMD_GET_EMISSION_STATUS:
			return "ST?|" + std::to_string(mpLaserController->GetEmissionState()) + "#\n";
			break;

		case CommandId::CMD_GET_POWER:
			return "PW?|" + std::to_string(mpLaserController->GetLaserPower()) + "#\n";
			break;

		case CommandId::CMD_SET_POWER:
			if (mpLaserController->SetLaserPower(value))
			{
				return "PW=#\n";
			}
			else
			{
				return "PW=!\n";
			}
			break;

		case CommandId::CMD_KEEP_ALIVE:
			if (mpLaserController->KeepAlive())
			{
				return "KAL#\n";
			}
			else
			{
				return "KAL!\n";
			}
			break;
		}
	}
}