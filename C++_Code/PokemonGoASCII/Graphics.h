#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <windows.h>
#include "Background.h"
#include "Sprite.h"
#include "Event.h"

class Graphics
{
    private:
        Background room;
        Sprite man;
        Sprite wildPokemon[10];
        string pokemonCaptured[10];
        int numOfWildPokemon;
        void loadRoom(string name);
        int pokeballs;
        int pokemonCell;
        int numOfCaptured;
        string name;

    public:
        Graphics(string name);
        ~Graphics();
        void draw();
        void move(Sprite& sprt, char direct);
        void move(char direct);
        void movePokemon();


        bool eventTriggered();
        void event();
};


#endif // GAME_H_INCLUDED
