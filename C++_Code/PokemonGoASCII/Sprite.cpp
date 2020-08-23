/*
* Author: Dan Langehough
* Assignment Title: Pokemon Go Group Project
* Assignment Description: This file loads a sprite
    into the console
* Due Date:
* Date Created: 11/26/2016
* Date Last Modified: 11/27/2016
 */

#include "Sprite.h"

Sprite::Sprite()
{
    hide = false;
}

void Sprite::loadSprite(string spriteBodyOfTwoChars,
    int x, int y, string n, ink c)
{
    //Load body
    body[0] = spriteBodyOfTwoChars[0];
    body[1] = spriteBodyOfTwoChars[1];

    //Load coordinates
    xCoor = x;
    yCoor = y;

    //Load name
    name = n;

    //Load color
    color = c;

    hide = false;
}

void Sprite::draw()
{
    spritePlotter.setColor(color);

    if(!hide)
    {
        spritePlotter.plot(xCoor, yCoor, body[0]);
        spritePlotter.plot(xCoor+1, yCoor, body[1]);
    }
}

void Sprite::move(char direction)
{
    //Change coordinate appropriately
    direction == TOP? yCoor--:
    direction == LEFT? xCoor--:
    direction == RIGHT? xCoor++:
    direction == BOTTOM? yCoor++:
        xCoor = xCoor;
}

int Sprite::getX()
{
    return xCoor;
}

int Sprite::getY()
{
    return yCoor;
}

string Sprite::getName()
{
    return name;
}


char Sprite::randomMove()
{
    srand(time(NULL));

    char send;

    switch(rand()%4)
    {
        case 0: send = TOP;break;
        case 1: send = LEFT;break;
        case 2: send = RIGHT;break;
        default:send = BOTTOM;
    }

    return send;
}

void Sprite::setHide(bool h)
{
    hide = h;
}

bool Sprite::getHide()
{
    return !hide;
}

void Sprite::display()
{
    spritePlotter.setColor(color);
    ifstream fin((name + ".txt").c_str());

    string line;
    int y = 0;
    while(!fin.eof())
    {
        getline(fin, line);

        for(int x = 0; x < line.length(); x++)
        {
            spritePlotter.plot(x, y, line[x]);
        }
        y++;
    }

    fin.close();

}
