
//Main File

#pragma once

//Included Project Files
#include "main_menu.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


//Main Window Dimensions
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH  800

//Frame Rate Limit
#define FR_LIMIT 60


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tower Defense"); //Create window
    window.setFramerateLimit(FR_LIMIT);

    Menu menu(WINDOW_WIDTH, WINDOW_HEIGHT);
    MainMenuOption option;
     
    do
    {
        menu.display_main_menu(window);
        option = menu.get_Selected_Index();

        if (option == INSTRUCTIONS) //Display instructions screen
        {
            menu.display_instructions(window);
            menu.set_Selected_Index(NOTHING);
        }
        else if (option == PLAY_GAME) //Begin game
        {
            menu.play_game(window);
            menu.set_Selected_Index(NOTHING);
        }
    } while (option != EXIT && window.isOpen()); //Continue until exit is selected or window is closed

    window.close();
    return 0;
}
