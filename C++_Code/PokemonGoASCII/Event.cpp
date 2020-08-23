#include "Event.h"

string stringToInt(int num)
{
    string result = "";
    char digit;

    while(num > 0)
    {
        switch(num%10)
        {
            case 1:digit = '1';break;
            case 2:digit = '2';break;
            case 3:digit = '3';break;
            case 4:digit = '4';break;
            case 5:digit = '5';break;
            case 6:digit = '6';break;
            case 7:digit = '7';break;
            case 8:digit = '8';break;
            case 9:digit = '9';break;
            case 0:digit = '0';break;
        }

        //Add digit
        result = digit + result;

        //Get rid of digit
        num /= 10;
    }

    return result;
}

Event::Event(Sprite toCatch)
{
    setLineW = 47;

    catching = toCatch;

    for(int i = 0; i < 5; i++)
    {
        eventBoxLines[i] = "";
    }

    //Open file
    fstream enterSentences;
    enterSentences.open("eventSentences.txt");

    for(int i = 0; i < 6; i++)
    {
        getline(enterSentences, eventSentences[i]);
    }

    //Close file
    enterSentences.close();

    //Add pokemon namn's to first sentence
    eventBoxLines[0] = eventSentences[0]+ " " + catching.getName();
}

void Event::draw()
{
    eventPlotter.setColor(white);

    int x, y = centerY;

    //Create top line of battle box
    for(int x = 0; x < 50; x++)
    {
        eventPlotter.plot(centerX+x, y, '_');
    }
    //Next line
    y++;

    //Write each line
    for(int i = 0; i < 5; i++)
    {
        x = 0;
        eventPlotter.plot(centerX+x++, y, '|');
        eventPlotter.plot(centerX+x++, y, ' ');

        //Write line
        for(unsigned int c = 0; c < eventBoxLines[i].length()
            && c < (unsigned)setLineW; c++)
        {
            eventPlotter.plot(centerX+c+x, y, eventBoxLines[i][c]);
        }

        //Ass spaces
        for(int s = x+eventBoxLines[i].length(); s <= setLineW; s++)
        {
            eventPlotter.plot(centerX+s, y, ' ');
        }

        //Add end
        x = setLineW+1;
        eventPlotter.plot(centerX+x++, y, ' ');
        eventPlotter.plot(centerX+x, y, '|');

      y++;
    }

    //Write bottom line
    eventPlotter.plot(centerX+0, y, '|');
    for(int x = 1; x < 49; x++)
    {
        eventPlotter.plot(centerX+x, y, '_');
    }
    eventPlotter.plot(centerX+49, y, '|');
}

bool Event::captureProcess(int& pokeballs)
{
    bool captured = false;

    //Draw screen
    draw();

    //Make some noise
    for(int i = 0; i < 2; i++)
    {
        Beep(500, 100);
        Beep(1000, 100);
        Beep(1000, 100);
    }
    Sleep(500);


    //Want to capture?
    char a = 'a';
    int capRunCell = 1;
    while(a != (char)13)
    {
        if(a == 'a')
        {
            capRunCell = 1;
        }
        else if(a == 'd')
        {
            capRunCell = 2;
        }

        eventBoxLines[1] = eventSentences[capRunCell];
        draw();

        a = getch();
    }

    //Are they capturing?
    if(capRunCell == 1)
    {
        eventBoxLines[2] = eventSentences[3];

        bool goodMove;
        do
        {
            eventBoxLines[3] = "Pokeballs: " + stringToInt(pokeballs);
            draw();
            a = getch();


            switch(a)
            {
                case '1':captured = 1 == rand()%5+1;goodMove = true;break;
                case '2':captured = 2 == rand()%5+1;goodMove = true;break;
                case '3':captured = 3 == rand()%5+1;goodMove = true;break;
                case '4':captured = 4 == rand()%5+1;goodMove = true;break;
                case '5':captured = 5 == rand()%5+1;goodMove = true;break;
                default:goodMove = false;
            }

            if(goodMove)
                pokeballs --;




        }while(a != 'r' && pokeballs > 0 && !captured);
    }

    if(captured)
    {
        eventBoxLines[4] = eventSentences[4]
            + " " + catching.getName() + "!!";
    }
    else
    {
        eventBoxLines[5] = eventSentences[5];
    }

    draw();

    if(captured)
        Sleep(1000);

    return captured;

}

