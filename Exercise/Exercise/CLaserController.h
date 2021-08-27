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
		virtual bool StartEmission();

		virtual bool StopEmission();

		virtual int GetEmissionState() const;

		virtual int GetLaserPower() const;

		virtual bool SetLaserPower(int power);

		virtual bool KeepAlive();

	protected:
		/// \brief Indicates if the laser is emitting
		bool mEmitting;

		/// \brief Current power of the laser in [1,100]
		int mPower;
	};
}
