#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <conio.h>
#include <fstream>
#include <string>
#include "plotter.h"
#include "Sprite.h"
using namespace std;

const int centerX = 10;
const int centerY = 20;

class Event
{
    private:
        Plotter eventPlotter;
        string eventBoxLines[5];
        string eventSentences[6];
        Sprite catching;
        int width, height;
        int setLineW;
        void draw();


    public:
        Event(Sprite toCatch);
        bool captureProcess(int& pokeballs);
};

#endif // EVENT_H_INCLUDED
