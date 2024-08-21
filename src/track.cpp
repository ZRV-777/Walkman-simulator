#include "track.h"
#include <iomanip>

string Track::getTrackName()
{
    return trackName;
}

tm Track::getTrackDate()
{
    return trackDate;
}

int Track::getTrackDuration()
{
    return trackDuration;
}

void Track::setTrackName()
{
    cout << "Enter track name:";
    cin >> trackName;
}

void Track::setTrackDate()
{
    cout << "Enter track date (dd/mm/yyyy); ";
    cin >> get_time(&trackDate, "%d/ %m/ %Y");
}

void Track::setTrackDuration()
{
    cout << "Enter track duration (sec): ";
    cin >> trackDuration;
}
