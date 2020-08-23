/*
* Author: Dan Langehough
* Assignment Title: Pokemon Go Group Project
* Assignment Description: This file loads backgrounds
    and draws them
* Due Date:
* Date Created: 11/26/2016
* Date Last Modified: 11/27/2016
 */

#include "Background.h"

Background::Background()
{
    srand(time(NULL));
}

void Background::loadFile(string fileName)
{
    //Enter room name
    roomName = fileName;

    //open file
    backgroundFile.open(fileName.c_str());

    //Check to see if file is open
    //  while loading background id number
    //  the height of the room and
    //  the length of the room
    if(backgroundFile >> roomID >> height >> width >> numOfP)
    {
        //Load background line by line
        while(!backgroundFile.eof())
        {
            getline(backgroundFile, fileName);
            backgroundChars += fileName;
        }
    }

    //Load grass coordinates
    //The background hight
    for(int y = 0; y < height; y++)
    {
        //The background width
        for(int x = 0; x < width; x++)
        {
            if(backgroundChars[x+width*y] == '^')
            {
                grassSpot.resize(grassSpot.size()+1);
                int cell = grassSpot.size()-1;
                grassSpot[cell].xCoor = x;
                grassSpot[cell].yCoor = y;
                grassSpot[cell].open = true;
            }
        }
    }

    //Close file
    backgroundFile.close();
}

//Private
ink Background::getInk(char c)
{
        ink sendInk;

        //Is character a wall, floor or roof?
        if(c == '|' || c == '_' || c == '/'
           || c == '\\' || c == '-')
        {
            sendInk = lightgrey;
        }
        //Is character water?
        else if(c == '~')
        {
            sendInk = blue;
        }
        //Is character road?
        else if(c == '*')
        {
            sendInk = yellow;
        }
        //Is character shop?
        else if(c == '$')
        {
            sendInk = darkblue;
        }
        //Is character health?
        else if(c == '+')
        {
            sendInk = red;
        }
        //Then it must be grass
        else
        {
            sendInk = green;
        }

        return sendInk;
}

//Public
void Background::draw()
{
    char toPlot;

    //The background hight is 22 lines
    for(int y = 0; y < height; y++)
    {
        //The background width is 75 characters
        for(int x = 0; x < width; x++)
        {

            //Get character to plot
            toPlot = backgroundChars[x+y*width];

            //Set ink color
            backgroundPlotter.setColor(getInk(toPlot));

            //Plot character
            backgroundPlotter.plot(x, y, toPlot);
        }
    }
}

void Background::rePlot(int x, int y)
{
    char toPlot = charAt(x, y);
    char toPlot2 = charAt(x+1, y);

    backgroundPlotter.setColor(getInk(toPlot));
    backgroundPlotter.plot(x, y, toPlot);

    backgroundPlotter.setColor(getInk(toPlot2));
    backgroundPlotter.plot(x+1, y, toPlot2);
}


void Background::rePlot(Sprite sprt)
{
    int x = sprt.getX();
    int y = sprt.getY();

    char toPlot = charAt(x, y);
    char toPlot2 = charAt(x+1, y);

    backgroundPlotter.setColor(getInk(toPlot));
    backgroundPlotter.plot(x, y, toPlot);

    backgroundPlotter.setColor(getInk(toPlot2));
    backgroundPlotter.plot(x+1, y, toPlot2);
}




bool Background::outOfBounds(Sprite character, char move)
{
    bool good;

    int charX = character.getX();
    int charY = character.getY();

    int yMove = 0;
    int xMove = 0;

    switch(move)
    {
        case TOP:yMove--;break;
        case LEFT:xMove--;break;
        case RIGHT:xMove++;break;
        case BOTTOM:yMove++;break;
    }

    //Check to make sure valid space
    char space = charAt(charX+xMove, charY+yMove);

    if(space == '~' || space == '|' ||
       space == '\\' || space == '/' ||
       space == '_' || space == '-')
    {
        good = false;
    }
    else
    {
        good = true;
    }

    return !good;
}

 char Background::charAt(int x, int y)
{
    return backgroundChars[x + width*y];
}

string Background::getName()
{
    return roomName;
}

int Background::getWidth()
{
    return width;
}

int Background::getHeight()
{
    return height;
}

int Background::getNumOfPoke()
{
    return numOfP;
}

Grass Background::getRandomGrass()
{
    int cell;

    do
    {
        cell = rand()%grassSpot.size();
    }while(!grassSpot[cell].open);

    grassSpot[cell].open = false;

    return grassSpot[cell];
}

