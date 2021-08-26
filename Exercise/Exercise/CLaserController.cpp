
#include "CLaserController.h"

namespace NS_Laser_Controller
{
	const int DEFAULT_LASER_POWER = 1;

	CLaserController::CLaserController()
	{
		mEmitting = false;
		mPower = DEFAULT_LASER_POWER;
	}

	CLaserController::~CLaserController()
	{
	}

	bool CLaserController::StartEmission()
	{
		if (!mEmitting)
		{
			mEmitting = true;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CLaserController::StopEmission()
	{
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

	int CLaserController::GetEmissionState() const
	{
		if (mEmitting)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int CLaserController::GetLaserPower() const
	{
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
		if (mEmitting)
		{
			// TODO implement timer
			return true;
		}
		else
		{
			return false;
		}
	}
}