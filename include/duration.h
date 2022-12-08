#include <cassert>

class duration
{
    private:
    // sekunder der er gået
    int time = 0;
    // laver en alarm
    int alarm = 0;
    // sætter en alarm
    bool alarmHasBeenSet = false;
    // checker alarmen og opdaterer den tilbage til 0
    bool checkAndUpdateAlarm(); 

    public:
    // giver tidsværdien
    int getDuration();
    // sætter tiden
    duration(int t);
    // sætter tiden to 0
    duration();
    // ticks uret med 1++
    bool tick();
    // tilføjer b to den nuværende tid
    bool tick(int b);
    // tillader brugeren at sætte en alarm
    void setAlarm(int t);
};