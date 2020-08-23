/*
* Author: Dan Langehough
* Assignment Title: Pokemon Go Group Project
* Assignment Description: This file loads a sprite
    into the console
* Due Date:
* Date Created: 11/26/2016
* Date Last Modified: 11/27/2016
 */

#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "plotter.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

class Sprite
{
    private:
        Plotter spritePlotter;
        char body[2];
        bool hide;
        int xCoor, yCoor;
        string name;
        ink color;

    public:
        Sprite();
         /*
        * description: Creates an instance of
            the Sprite class
        * return: N/A
        * precondition: A string for the body of the
            sprite exists, and the coordinates x, and
            y of the sprite exists
        * postcondition: A Sprite is created
        *
        */
        void loadSprite(string spriteBodyOfTwoChars,
            int x, int y, string n, ink c);

        /*
        * description: A sprite is drawn in the console
        * return: void
        * precondition: N/A
        * postcondition: The sprite is drawn to the console
            at the location set with its x and y coordinates.
            The first char appears at (x,y) while the second
            char appears at (x+1, y)
        *
        */
        void draw();

        /*
        * description: Move the character in the given
            direction
        * return: void
        * precondition: a real direction has been determined
        * postcondition: the coordinates of the sprite are
            changes according to the direction sent
        *
        */
        void move(char direction);

        /*
        * description: Returns the x coordinate of
            the sprites first character
        * return: int
        * precondition: N/A
        * postcondition: xCoor is returned
        *
        */
        int getX();

        /*
        * description: Returns the y coordinate of
            the sprites first character
        * return: int
        * precondition: N/A
        * postcondition: yCoor is returned
        *
        */
        int getY();

        string getName();


        void setHide(bool h);

        bool getHide();

        void display();


        char randomMove();
};

#endif // SPRITE_H_INCLUDED
