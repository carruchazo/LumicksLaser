#include "CLaserController.h"

namespace NS_Laser_Controller
{
	const int DEFAULT_LASER_POWER = 1;

	CLaserController::CLaserController()
	{
		mEmitting = false;
		mPower = DEFAULT_LASER_POWER;
		mLastUpdate = std::chrono::system_clock::now();
	}

	CLaserController::~CLaserController()
	{
	}

	bool CLaserController::StartEmission()
	{
		Update();

		if (!mEmitting)
		{
			mEmitting = true;
			// Reset timer
			mLastUpdate = std::chrono::system_clock::now();
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CLaserController::StopEmission()
	{
		Update();

		if (mEmitting)
		{
			mEmitting = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	int CLaserController::GetEmissionState()
	{
		Update();

		if (mEmitting)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int CLaserController::GetLaserPower()
	{
		Update();

		if (!mEmitting)
		{
			return 0;
		}
		else
		{
			return mPower;
		}
	}

	bool CLaserController::SetLaserPower(int power)
	{
		Update();

		if (!mEmitting)
		{
			return false;
		}
		else
		{
			if (power < 1 || power > 100)
			{
				return false;
			}
			else
			{
				mPower = power;
				return true;
			}
		}
	}

	bool CLaserController::KeepAlive()
	{
		Update();

		if (mEmitting)
		{
			// Reset timer
			mLastUpdate = std::chrono::system_clock::now();
			return true;
		}
		else
		{
			return false;
		}
	}

	void CLaserController::Update()
	{
		auto currentTime = std::chrono::system_clock::now();

		// If the laser is emitting
		if (mEmitting)
		{
			// If more than 5 seconds have passed since the last keep alive message 
			// or the beginning of the emission, the laser stops emitting
			if ((currentTime - mLastUpdate) > std::chrono::seconds(5))
			{
				mEmitting = false;
			}
		}
	}
}