#pragma once

#include <chrono>
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

		virtual int GetEmissionState();

		virtual int GetLaserPower();

		virtual bool SetLaserPower(int power);

		virtual bool KeepAlive();

	protected:
		/// \brief Indicates if the laser is emitting
		bool mEmitting;

		/// \brief Current power of the laser in [1,100]
		int mPower;

		/// \brief Stores the last time the laser controller was updated
		std::chrono::time_point<std::chrono::system_clock> mLastUpdate;

		/// \brief Updates internal state. If the laser has been emitting for
		///        more than 5 seconds without any KeepAlive command, it stops emitting
		void Update();
	};
}
