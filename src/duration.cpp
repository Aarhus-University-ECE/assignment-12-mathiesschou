#include "duration.h"
#include <assert.h>

int duration::getDuration()
{
    //returener værdien af tiden
    return time;
}


duration::duration()
{
    // sætter tiden og alarm til 0
    time = 0;
    alarm = 0;

    //alarmen er ikke sat endnu, så falsk
    alarmHasBeenSet = false;

}

duration::duration(int t)
{
    // sætter tiden
    assert(0 <= t);
    time = t;
    alarm = 0;
    alarmHasBeenSet = false;
}

bool duration::tick()
{
    //1++
    time++;
    return checkAndUpdateAlarm();
}

bool duration::tick(int b)
{
    assert(b >= 0);
    time = time + b;
    return checkAndUpdateAlarm();
}

void duration::setAlarm(int t)
{
    // sætter alarmen
    assert(t > time);
    alarm = t;
    alarmHasBeenSet = true;
}

bool duration::checkAndUpdateAlarm() 
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
