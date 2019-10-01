#ifndef THREAD_H
#define THREAD_H

#include <QtCore>
#include <qserialprotocol.h>

class Thread
{
public:
    Thread();
    static Thread fromInfo(mavlink_thread_info_t thread_info);

    int id();
    int priority();
    int averageDuration();
    int averageLatency();
    int duration();
    int latency();
    int executions();

    void setId(int id);
    void setPriority(int priority);
    void setTotalDuration(int total_duration);
    void setTotalLatency(int total_latency);
    void setNumberOfExecutions(int number_of_executions);
    void setDuration(int duration);
    void setLatency(int latency);
    void setTime(int time);

private:
    quint32 _time;
    quint32 _total_duration;
    quint32 _total_latency;
    quint32 _number_of_executions;
    quint16 _duration;
    quint16 _latency;
    quint8 _ID;
    quint8 _priority;
};

#endif // THREAD_H
