#include "thread.h"

Thread::Thread()
{

}

int Thread::id()
{
    return _ID;
}

int Thread::priority()
{
    return _priority;
}

int Thread::averageDuration()
{
    return _total_duration/_number_of_executions;
}

int Thread::averageLatency()
{
    return _total_latency/_number_of_executions;
}

int Thread::duration()
{
    return _duration;
}

int Thread::latency()
{
    return _latency;
}

int Thread::executions()
{
    return _number_of_executions;
}

void Thread::setId(int id)
{
    _ID = id;
}

void Thread::setPriority(int priority)
{
    _priority = priority;
}

void Thread::setTotalDuration(int total_duration)
{
    _total_duration = total_duration;
}

void Thread::setTotalLatency(int total_latency)
{
    _total_latency = total_latency;
}

void Thread::setNumberOfExecutions(int number_of_executions)
{
    _number_of_executions = number_of_executions;
}

void Thread::setDuration(int duration)
{
    _duration = duration;
}

void Thread::setLatency(int latency)
{
    _latency = latency;
}

void Thread::setTime(int time)
{
    _time = time;
}
