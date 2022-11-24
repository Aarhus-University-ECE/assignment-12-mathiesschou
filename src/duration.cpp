#include "duration.h"

int Duration::getDuration()
{
    return time;
}


bool Duration::checkAndUpdateAlarm() 
{
    if(alarmHasBeenSet && time >= alarm) 
    {
        alarmHasBeenSet = false;
        alarm = 0;
        
        return true;
    }
    else
        return false;
}
