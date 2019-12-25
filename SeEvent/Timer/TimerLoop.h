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
	void RunInLoop(const Functor_t& cb);
	void PutPendingQ(const Functor_t& cb);
	bool IsThisThread();
	TimeId RunAfter(int delay, TimerCb& cb);
	TimeId RunAt(Timestamp& timestamp, TimerCb& cb);
	TimeId RunEvery(int interval, TimerCb& cb);
	void Cancel(TimeId& timeid);
private:
	void DoPendingFunctors();
private:
	TimerQueue* mTimeQ;
	TID mThreadId;

	Mutex mMutex;
	std::vector<Functor_t> mPendingFunctors;
};

// ������������Ӧ�ü������еļ�ʱ��
