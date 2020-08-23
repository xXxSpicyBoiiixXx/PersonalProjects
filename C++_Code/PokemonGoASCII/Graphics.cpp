#include "Graphics.h"
#include <iostream>

using namespace std;

Graphics::Graphics(string n)
{
    ifstream inputSave;
    name = n;
    inputSave.open((name+"save.txt").c_str());
    string fileName = "openingArea.txt";
    int userX = 35, userY = 11;
    pokeballs = 10;
    numOfCaptured = 0;

    if(inputSave)
    {
        //Enter name of room
        inputSave >> fileName;

        //Enter user coordinates
        inputSave >> userX >> userY;

        //Enter number of pokeballs
        inputSave >> pokeballs;

        //Enter number of pokemon captured
        inputSave >> numOfCaptured;

        for(int i = 0; i < numOfCaptured; i++)
        {
            inputSave >> pokemonCaptured[i];
        }

    }

    loadRoom(fileName);
    man.loadSprite(":)", userX, userY, name, white);

    //Load pokemon
    Grass spot;
    for(int i = 0; i < numOfWildPokemon-1; i++)
    {
        spot = room.getRandomGrass();

        wildPokemon[i].loadSprite("}{", spot.xCoor,
            spot.yCoor, "Butterfree", cyan);
    }

    wildPokemon[numOfWildPokemon-1].loadSprite("Z@", spot.xCoor,
            spot.yCoor, "Pikachu", yellow);
}

Graphics::~Graphics()
{
    ofstream outputSave;
    outputSave.open((name+"save.txt").c_str());

    //output room
    outputSave << room.getName() << endl;

    //output user sprite
    outputSave << man.getX() << " " << man.getY() << endl;

    //Save number of pokeballs
    outputSave << pokeballs << endl;

    //Save number of pokeman captured
    outputSave << numOfCaptured << endl;


    //Save pokemon
    for(int i = 0; i < numOfCaptured; i++)
    {
        outputSave << pokemonCaptured[i];
    }

    //close file
    outputSave.close();

    system("CLS");
}


void Graphics::move(Sprite& sprt, char direct)
{
    //Fill background
    room.rePlot(sprt);

    switch(direct)
    {
        case 'w':direct = TOP;break;
        case 's':direct = BOTTOM;break;
        case 'd':direct = RIGHT;break;
        case 'a':direct = LEFT;break;
    }

    if(!room.outOfBounds(sprt, direct))
    {
        sprt.move(direct);
    }

    sprt.draw();

    Sleep(50);
}






void Graphics::loadRoom(string name)
{
    //Load room
    room.loadFile(name);

    //Get number of wild pokemon
    numOfWildPokemon = room.getNumOfPoke();
}

void Graphics::draw()
{
    room.draw();
    man.draw();

    for(int i = 0; i < numOfWildPokemon; i++)
    {
        wildPokemon[i].draw();
    }
}

void Graphics::move(char direct)
{
    for(int i = 0; i < numOfWildPokemon; i++)
    {
        wildPokemon[i].draw();
    }

    move(man, direct);
}

void Graphics::movePokemon()
{
    char direction;
    static int count = 0;

    for(int i = 0; i < numOfWildPokemon; i++)
    {
        switch(rand()%4)
        {
            case 0: direction = TOP;break;
            case 1: direction = LEFT;break;
            case 2: direction = RIGHT;break;
            case 3: direction = BOTTOM;break;
        }


        if(rand()%3 == 0 || count == 3)
        {
            count = 0;
            move(wildPokemon[i], direction);
        }
        count ++;
    }

    man.draw();
}





bool Graphics::eventTriggered()
{
    bool triggered = false;

    for(int i = 0 ;i < numOfWildPokemon; i++)
    {
        if(!triggered)
        {
            triggered = man.getX() == wildPokemon[i].getX() &&
                man.getY() == wildPokemon[i].getY();
            pokemonCell = i;
        }
    }

    return triggered == wildPokemon[pokemonCell].getHide()
        && numOfCaptured < 10;
}

void Graphics::event()
{
    //Clear screen
    system("CLS");

    //Make battle event
    Event battle(wildPokemon[pokemonCell]);

    //Display sprite
    wildPokemon[pokemonCell].display();

    //If the battle is won
    if(battle.captureProcess(pokeballs))
    {
        //Remove pokemon from field of view
        wildPokemon[pokemonCell].setHide(true);

        //Increase capture count
        numOfCaptured++;

        //Add to captured pokemon
        pokemonCaptured[numOfCaptured] = wildPokemon[pokemonCell].getName();
    }

    //Clear screen
    system("CLS");
}
