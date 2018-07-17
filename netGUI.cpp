#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "netGUI.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "Chat Window");
sf::Event event;
sf::Font font;

//Text to be sent
std::string text;

//Username
std::string username;

textLine* root = NULL;

void initializeGraphics(){

  if(!font.loadFromFile("arial.ttf")){

  }
  
  username = "";

}

void addText(std::string newStr){
  if(root == NULL){
    root = new textLine;
    root->curText.setFont(font);
    root->curText.setString(newStr);
    root->curText.setCharacterSize(24);
    root->curText.setFillColor(sf::Color::White);
    root->nextLine = NULL;
  }
  else{    
    textLine* cur = new textLine;
    cur->curText.setFont(font);
    cur->curText.setString(newStr);
    cur->curText.setCharacterSize(24);
    cur->curText.setFillColor(sf::Color::White);
    
    cur->nextLine = root;
    root = cur;
    
  }
}

void updateText(){
  textLine* cur = root;
  int location = 600-48;
  while(cur != NULL){
    cur->curText.setPosition(0, location);
    location = location-24;
    
    window.draw(cur->curText);
    cur = cur->nextLine;
  }
}

void windowLoop(sf::TcpSocket &curSocket){

  window.clear();

  sf::Text currentWriting;
  currentWriting.setFont(font);
  currentWriting.setString(text);
  currentWriting.setCharacterSize(24);
  currentWriting.setPosition(0, 600-24);
  currentWriting.setFillColor(sf::Color::White);
  window.draw(currentWriting);

  updateText();
  window.display();
  

  while (window.pollEvent(event)){

    if(event.type == sf::Event::TextEntered){
      if (event.text.unicode < 128 && event.text.unicode != '\n' && event.text.unicode != '\b')
	text += static_cast<char>(event.text.unicode);
    }
    if (event.type == sf::Event::KeyPressed){
      if (event.key.code == sf::Keyboard::Backspace){
	text.erase(text.length()-1, std::string::npos);                                   
      }
      if (event.key.code == sf::Keyboard::Enter){
	char charArray[1000];

	strcpy(charArray, (username+text).c_str());

	sendText(charArray, curSocket);
	addText("You: " + text);
	text = "";
      }

    }

  }

}

void sendText(char message[], sf::TcpSocket &curSocket){
  if(curSocket.send(message, 1000) != sf::Socket::Done){
  }
}

void setUsername(std::string newName){
  
  username = newName + ": ";
}
