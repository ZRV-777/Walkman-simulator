#include "walkman.h"

int main()
{
    Walkman* walkman = new Walkman();
    string commandInput;

    walkman->fillTrackList();

    while (commandInput != "exit")
    {
        cout << "Input command: ";
        cin >> commandInput;
        walkman->stateControl(commandInput);
    }

    delete walkman;
}
