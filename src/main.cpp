#include "duration.h"
#include <iostream>
#include <cstdio>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    Duration dur;

    std::cout << dur.getDuration() << "\n";

    Duration d(5);

    assert(d.getDuration() == 5);

    d.tick();

    assert(d.getDuration() == 6);

    d.tick(3);

    assert(d.getDuration() == 9);

    Duration dur2(1);

    dur2.setAlarm(6);

    assert(dur2.tick(4) == 0);
    assert(dur2.getDuration() == 5);

    assert(dur2.tick() == true);
    assert(dur2.getDuration() == 6);
    
    // since the alarm was fired in the last tick()
    // call, we expect the alarm to have been reset
    // so when we tick again, it should not go off
    // and return false.
    assert(dur2.tick() == false);
    assert(dur2.getDuration() == 7);
    

    dur2.setAlarm(10);
    assert(dur2.tick(4) == true);
    assert(dur2.getDuration() == 11);
    
    std::cout << "All test passed\n";

    return 0;
}