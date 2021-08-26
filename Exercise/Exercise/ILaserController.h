#pragma once

namespace NS_Laser_Controller
{
	/// \brief Abstract class that defines the interface of a laser controller
	class ILaserController
	{
	public:
		ILaserController();
		virtual ~ILaserController();

		/// \brief Starts the emission of the laser
		/// \return true if the command was succesful, false otherwise
		virtual bool StartEmission() = 0;

		/// \brief Stops the emission of the laser
		/// \return true if the command was succesful, false otherwise
		virtual bool StopEmission() = 0;

		/// \brief Returns the emission status
		/// \return 1 if the laser is emitting, 0 otherwise
		virtual int GetEmissionState() const = 0;

		/// \brief Returns the laser power
		/// \return 0 if the laser is off, the power value in [1,100] otherwise
		virtual int GetLaserPower() const = 0;

		/// \brief Sets the laser power
		/// \return false if the laser is off or the power value is not in [1,100]. Returns true otherwise
		virtual bool SetLaserPower(int power) = 0;

		/// \brief Resets the timer that keeps the laser on
		/// \return true if the command was succesful, false otherwise
		virtual bool KeepAlive() = 0;
	};
}
