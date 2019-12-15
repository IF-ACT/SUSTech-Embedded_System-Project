#include "Time.h"

float __Time_Last_Update;

float GetTime()
{
	// to impliment
}

void Time_OnStart()
{
	__Time_Last_Update = GetTime();
}

void Time_OnUpdate()
{
	float temp = GetTime();
	delta_time = temp - __Time_Last_Update;
	__Time_Last_Update = temp;
}
