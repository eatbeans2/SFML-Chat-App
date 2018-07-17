//Outline for the GUI functions 
//Will have a linked list for displaying and saving messages
//Will input received strings and put them into this list
//Will probably handle all graphic functions

#ifndef __NETGUI_H__
#define __NETGUI_H__

#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

struct textLine{
  sf::Text curText;
  textLine* nextLine;
};

//Initailizes the graphics
void initializeGraphics();

//For inserting new text into the linked list
void addText(std::string newText);

//Prints to the screen
void updateText();

//Updates the window in the loop
void windowLoop(sf::TcpSocket &curSocket);

void sendText(char message[], sf::TcpSocket &curSocket);

void setUsername(std::string newName);

#endif
