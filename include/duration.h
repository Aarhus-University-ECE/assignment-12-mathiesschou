#include <cassert>

class Duration
{
    private:
    int time = 0;
    int alarm = 0;
    bool alarmHasBeenSet = false;
    bool checkAndUpdateAlarm(); 

    public:
    Duration(int t)
    {
        assert(t >= 0);

        time = t;
    }

    Duration()
    {
        time = 0;
    }
    
    bool tick()
    {
        time++;
       return checkAndUpdateAlarm();
    }

    bool tick(int b)
    {
       time += b; 
       return checkAndUpdateAlarm();

    }

    void setAlarm(int t)
    {
        assert(t > time);
        alarmHasBeenSet = true;
        alarm = t;
    }

    int getDuration();

};