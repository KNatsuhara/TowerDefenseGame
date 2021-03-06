
//Main Menu source File

#include "main_menu.h"
using namespace std;

//constructor for menu-  makes all the text and buttons
Menu::Menu(float width, float height)
{

	if (!font.loadFromFile("Resources/Chunk Five.otf"))	//this is just the text file im using we can change
	{
		std::cout << "Error Loading Font" << std::endl;
		return;
	}

	//set up for eack menu item
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::White);
	text[0].setString("Play Game");
	text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu_buttons[0].Shape.setSize(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu_buttons[0].Shape.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu_buttons[0].Shape.setFillColor(sf::Color::Black);


	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Instructions");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu_buttons[1].Shape.setSize(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu_buttons[1].Shape.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu_buttons[1].Shape.setFillColor(sf::Color::Black);


	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Exit");
	text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu_buttons[2].Shape.setSize(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu_buttons[2].Shape.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu_buttons[2].Shape.setFillColor(sf::Color::Black);

	//gets bounds of eack item for later use in mouse_place
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu_buttons[i].buttonW = menu_buttons[i].Shape.getGlobalBounds().width;
		menu_buttons[i].buttonH = menu_buttons[i].Shape.getGlobalBounds().height;
	}
    selectedItemIndex = NOTHING;
}

void Menu::display_main_menu(sf::RenderWindow& mainMenuWindow)
{
	sf::Event event;

	while (mainMenuWindow.pollEvent(event))
	{
		switch (event.type)
		{
        case sf::Event::Closed:
            mainMenuWindow.close();
            break;
		case sf::Event::MouseMoved:
			mousePlace(mainMenuWindow);
			break;
		case sf::Event::MouseButtonPressed:
			get_main_menu_option(mainMenuWindow);
			break;
		}

	}
	mainMenuWindow.clear();
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		mainMenuWindow.draw(menu_buttons[i].Shape);
		mainMenuWindow.draw(text[i]);
	}
	mainMenuWindow.display();
}

//this changes the color of the option near the players mouse
void Menu::mousePlace(sf::RenderWindow& mainMenuWindow)
{
	int mouseX = sf::Mouse::getPosition(mainMenuWindow).x;
	int mouseY = sf::Mouse::getPosition(mainMenuWindow).y;

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		int buttonX = (menu_buttons[i].Shape.getPosition().x);
		int buttonY = menu_buttons[i].Shape.getPosition().y;

		int buttonPosW = buttonX + menu_buttons[i].buttonW;
		int buttonPosH = buttonY + menu_buttons[i].buttonH;

		if (mouseX < buttonPosW && mouseX > buttonX&& mouseY < buttonPosH && mouseY > buttonY)
		{
			if (i == 0)
			{
				text[0].setFillColor(sf::Color::Green);
				text[1].setFillColor(sf::Color::White);
				text[2].setFillColor(sf::Color::White);
			}

			if (i == 1)
			{
				text[1].setFillColor(sf::Color::Green);
				text[0].setFillColor(sf::Color::White);
				text[2].setFillColor(sf::Color::White);
			}

			if (i == 2)
			{
				text[2].setFillColor(sf::Color::Green);
				text[0].setFillColor(sf::Color::White);
				text[1].setFillColor(sf::Color::White);
			}
		}//changes color of text based on which one mouse is near
	}

}

void Menu::get_main_menu_option(sf::RenderWindow& window)//called when clicked return choice mouse is near
{
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		int buttonX = (menu_buttons[i].Shape.getPosition().x);
		int buttonY = menu_buttons[i].Shape.getPosition().y;

		int buttonPosW = buttonX + menu_buttons[i].buttonW;
		int buttonPosH = buttonY + menu_buttons[i].buttonH;

		if (mouseX < buttonPosW && mouseX > buttonX && mouseY < buttonPosH && mouseY > buttonY)
		{
			if (i == 0)
			{
				selectedItemIndex = PLAY_GAME;
			}
			if (i == 1)
			{
				selectedItemIndex = INSTRUCTIONS;
			}
			if (i == 2)
			{
				selectedItemIndex = EXIT;
			}
		}
	}
}

MainMenuOption Menu::get_Selected_Index()
{
	return selectedItemIndex;
}

void Menu::set_Selected_Index(MainMenuOption option)
{
	selectedItemIndex = option;
}

void Menu::display_instructions(sf::RenderWindow& window)
{
    sf::Text text[5];	//a paragraph of text

    text[0].setString("How to play the Epic Tower Defense Game:");
    text[1].setString("Prevent Monsters from reaching your castle by placing");
    text[2].setString("towers along the path by clicking the button of the ");
    text[3].setString("tower you want and then clicking the space where you");
    text[4].setString("want it placed");

    for (int i = 0, h = 10; i < 5; i++)
    {
        text[i].setFont(font);
        text[i].setOutlineColor(sf::Color::Black);
        text[i].setOutlineThickness(2);
        text[i].setFillColor(sf::Color::White);
        text[i].setCharacterSize(25);
        text[i].setPosition(sf::Vector2f(50, h));
        h = h + 50;	//increments y value
    }

	sf::RectangleShape button;
	sf::Text back;
	button.setSize(sf::Vector2f(100, 100));
	button.setPosition(70, 450);
	button.setFillColor(sf::Color::Green);
    button.setOutlineColor(sf::Color::Green);
    button.setOutlineThickness(2);

    back.setString("BACK");	//back button set up 
	back.setCharacterSize(25);
	back.setFont(font);
	back.setFillColor(sf::Color::White);
	back.setOutlineColor(sf::Color::Black);
	back.setPosition(sf::Vector2f(70, 450));
	back.setOutlineThickness(2);

    bool exit = false;
    while (!exit && window.isOpen())	// when back is pressed it returns to menu, else displays instructions
    {
        window.clear();

        for (int i = 0; i < 5; i++)
            window.draw(text[i]);

        window.draw(button);
        window.draw(back);

        window.display();

        //Event handling
        sf::Event event;
        while (window.pollEvent(event))
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                exit = true;
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                    if (button.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        exit = true;
                break;
            case sf::Event::MouseMoved:
                if (button.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                    button.setOutlineColor(sf::Color::Red);
                else
                    button.setOutlineColor(sf::Color::Green);
                break;
            }
    }
}

//Creates the game object and runs it
void Menu::play_game(sf::RenderWindow& window)
{
    Game game(window); //Create the game

    game.run();

    if (window.isOpen())
    {
        Utility::delay(2);
        game.display_results();
    }
}


