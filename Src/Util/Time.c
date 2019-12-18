#include "Time.h"

int __Time_Last_Update;

int GetTime()
{
	return __Time_Last_Update + 1;
}

void Time_OnStart()
{
	__Time_Last_Update = 0;
}

void Time_OnUpdate()
{
	float temp = GetTime();
	delta_time = temp - __Time_Last_Update;
	__Time_Last_Update = temp;
}
