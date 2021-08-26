#pragma once

#include "ILaserController.h"

namespace NS_Laser_Controller
{
	/// \brief Class that implements the interface ILaserController
	class CLaserController : public ILaserController
	{
	public:
		CLaserController();

		~CLaserController();

		// Methods from ILaserController
		virtual bool StartEmission() = 0;

		virtual bool StopEmission() = 0;

		virtual int GetEmissionState() const = 0;

		virtual int GetLaserPower() const = 0;

		virtual bool SetLaserPower(int power) = 0;

		virtual bool KeepAlive() = 0;

	protected:
		/// \brief Indicates if the laser is emitting
		bool mEmitting;

		/// \brief Current power of the laser in [1,100]
		int mPower;
	};
}
