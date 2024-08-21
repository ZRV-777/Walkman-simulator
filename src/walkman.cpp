#include <iomanip>
#include "walkman.h"

void Walkman::stateControl(string commandInput)
{
    if(commandInput == "play")
        command = Walkman::play;
    else if (commandInput == "pause")
        command = Walkman::pause;
    else if (commandInput == "next")
        command = Walkman::next;
    else if (commandInput == "stop")
        command = Walkman::stop;
    else if (commandInput == "exit")
        command = Walkman::exit;
    else
        cerr << "Incorrect command" << endl;

    if (command == Walkman::play)
    {
        isPlaying = true;
        isStopped = false;
        isPaused = false;
        string track_name;
        cout << "Input track name: ";
        cin >> track_name;
        playTrack(track_name);
    }
    else if (command == Walkman::pause)
    {
        isPlaying = false;
        isStopped = false;
        isPaused = true;
        pauseTrack();
    }
    else if (command == Walkman::next)
    {
        nextTrack(currentTrack);
    }
    else if (command == Walkman::stop)
    {
        isPlaying = false;
        isStopped = true;
        isPaused = false;
        stopTrack();
    }
    else if (command == Walkman::exit)
    {
        exitProgram();
    }
}

void Walkman::addTrack()
{
    Track track;
    track.setTrackName();
    track.setTrackDate();
    track.setTrackDuration();
    trackList.push_back(track);
}

void Walkman::fillTrackList()
{
    int track_list_quantity = 0;

    cout << "Load track list, input track list quantity: ";
    cin >> track_list_quantity;
    for (int i = 0; i < track_list_quantity; i++)
    {
        addTrack();
    }
}

void Walkman::playTrack(string &track_name_playing)
{
    tm playing_track_date;
    int playing_track_duration;
    if (isPlaying)
    {
        cout << "Track is playing" << endl;

        for (int i = 0; i < trackList.size(); i++)
        {
            if (trackList[i].getTrackName() == track_name_playing)
            {
                currentTrack = track_name_playing;
                playing_track_date = trackList[i].getTrackDate();
                playing_track_duration = trackList[i].getTrackDuration();
            }
        }
        cout << "Track name: " << currentTrack << endl;
        cout << "Track was created " << put_time(&playing_track_date, "%d/%m/%Y") << endl;
        cout << "Track duration " << playing_track_duration << " sec" << endl;
    }
}

void Walkman::pauseTrack()
{
    if (isPaused)
    {
        cout << "Track is paused" << endl;
    }
}

void Walkman::nextTrack(string &currTrack)
{
    srand(time(nullptr));
    if (isPlaying)
    {
        for (int i = 0; i < trackList.size(); i++)
        {
            int start = 0;
            int end = trackList.size();
            int x = rand() % (end - start) + start;
            if (trackList[i].getTrackName() != currentTrack)
            {
                nTrack = trackList[x].getTrackName();
            }
        }
        cout << "Next track: " << nTrack << endl;
    }
    playTrack(nTrack);
}

void Walkman::stopTrack()
{
    if (isStopped)
    {
        cout << "Track is stopped" << endl;
        currentTrack.clear();
    }
}

void Walkman::exitProgram()
{
    cout << "Goodbye!" << endl;
}
