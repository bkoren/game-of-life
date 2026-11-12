#include <iostream>
#include <thread>
#include <chrono>
#include "Game.h"

using namespace std;

int main()
{
    RenderWindow window(VideoMode(1000, 800), "Game Of Life");

    Game game;
    game.set_Coordinates();
    game.set_numberOfCells(550);
    game.set_startCells();
    game.set_color(0, 255, 0);
    
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        //game.net(window);
        game.generate(window);
        game.checkStatus();
        game.swap();
        window.display();

        //this_thread::sleep_for(chrono::seconds(2));

    }
	return 0;
}