#ifndef __TIME_H
#define __TIME_H

// 上一帧耗时
float delta_time;

float GetTime();

void Time_OnStart();
void Time_OnUpdate();

#endif
