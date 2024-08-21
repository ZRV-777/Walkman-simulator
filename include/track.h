#include <iostream>
#include <ctime>

using namespace std;

class Track
{
    string trackName;
    time_t t = time(nullptr);
    tm local_time = *localtime(&t);
    tm trackDate;
    int trackDuration;

public:
    string getTrackName();
    tm getTrackDate();
    int getTrackDuration();

    void setTrackName();
    void setTrackDate();
    void setTrackDuration();
};