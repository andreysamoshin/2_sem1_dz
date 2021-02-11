#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>


class Timer
{
public:
    void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true; //создаём переменную, отражающую состояние таймера
    }

    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false; // когда таймер остновлен, она равна false
    }

    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;
        // если таймер активен, то время фиксируется
        if (m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        // если неактивен, то используется последнее сохранённое время 
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
};