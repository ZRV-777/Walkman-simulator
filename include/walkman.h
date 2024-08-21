#include <vector>
#include "track.h"

class Walkman
{
    vector<Track> trackList;
    bool isPlaying;
    bool isStopped;
    bool isPaused;
    string currentTrack;
    string nTrack;

    enum walkmanCommand
    {
        play,
        pause,
        next,
        stop,
        exit
    };
    walkmanCommand command;

public:
    void stateControl(string commandInput);
    void addTrack();
    void fillTrackList();
    void playTrack(string &track_name);
    void pauseTrack();
    void nextTrack(string &currentTrack);
    void stopTrack();
    static void exitProgram();
};