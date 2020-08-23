/*
* Author: Dan Langehough
* Assignment Title: Pokemon Go Group Project
* Assignment Description: This file loads backgrounds
    and draws them
* Due Date:
* Date Created: 11/26/2016
* Date Last Modified: 11/27/2016
 */

#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "plotter.h"
#include "Sprite.h"
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Grass
{
    int xCoor;
    int yCoor;
    bool open;
};

class Background
{
    private:
        int roomID;
        string roomName;
        int height, width;
        Plotter backgroundPlotter;
        string backgroundChars;
        int numOfP;
        vector <Grass> grassSpot;
        ifstream backgroundFile;

        /*
        * description: Return the ink corresponding to
            the char sent
        * return: ink
        * precondition: a char exists
        * postcondition: The appropriate ink is sent back
            which matches the char sent
        *
        */
        ink getInk(char c);

        void addPokemon();

    public:
        Background();

        /*
        * description: Load a file into the class instance
        * return: void
        * precondition: A name name exists in a string
        * postcondition: The file with the given name
            is loaded into the class instance
        *
        */
        void loadFile(string fileName);

        /*
        * description: Draws the background character
            by character plotting each character based
            on its location in the backgroundChars string

        * precondition: N/A
        * postcondition: The background is plotted to the
            console
        *
        */
        void draw();

        void drawPokemon();

        /*
        * description: Fills the background where the
            the coordinates are and (x+1, y)
        * return: void
        * precondition: N/A
        * postcondition: The background is refilled at
            the location given and (x+1, y)
        *
        */
        void rePlot(int x, int y);


        /*
        * description: Fills the background where the
            the sprite is
        * return: void
        * precondition: N/A
        * postcondition: The background is refilled at
            the location of the sprite
        *
        */
        void rePlot(Sprite sprt);




        /*
        * description: Check to see is the area a sprite
            is moving into is a valid spot for the sprite
            to move into
        * return: boolean
        * precondition: A sprite exists and a valid move
            exists
        * postcondition: Return true or false depending on
            where the sprite is moving and if this move is valid
        *
        */
        bool outOfBounds(Sprite character, char move);

        /*
        * description: Returns the char of the room
            at the given coordinates
        * return: char
        * precondition: two integers exists
        * postcondition: The char of the room at the
            given coordinates is returned
        *
        */
        char charAt(int x, int y);

        /*
        * description: Returns the width of the room
        * return: int
        * precondition: N/A
        * postcondition: The width of the room is returned
        *
        */
        int getWidth();

        /*
        * description: Returns the height of the room
        * return: int
        * precondition: N/A
        * postcondition: The height of the room is returned
        *
        */
        int getHeight();

        /*
        * description: Returns the name of the room
        * return: string
        * precondition: N/A
        * postcondition: The name of the room is returned
        *
        */
        string getName();


        int getNumOfPoke();

        Grass getRandomGrass();

};

#endif // BACKGROUND_H_INCLUDED
