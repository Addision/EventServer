#pragma once

#include <functional>
#include <vector>
#include "Timestamp.h"
#include "Timer.h"
#include "TimerQueue.h"
#include "SePlatForm.h"
#include "Lock.hpp"

// TODO ��ʱû�п��Ƕ��̴߳���
using Functor_t = std::function<void()>;

class TimerLoop
{
public:
	TimerLoop();
	~TimerLoop();
	void TimeLoop();
	TimeId RunAfter(int delay, TimerCb& cb);
	TimeId RunAt(Timestamp& timestamp, TimerCb& cb);
	TimeId RunEvery(int interval, TimerCb& cb);
	void Cancel(TimeId& timeid);

private:
	TimerQueue* mTimeQ;
	Mutex mMutex;
};

// ������������Ӧ�ü������еļ�ʱ��
