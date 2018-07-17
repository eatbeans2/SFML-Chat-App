#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "netGUI.h"

int main(){
  sf::TcpListener listener;

  if(listener.listen(23000) != sf::Socket::Done){

  }

  sf::TcpSocket client;

  if(listener.accept(client) != sf::Socket::Done){

  }
  client.setBlocking(false);
  //Maybe set listener false too?


  initializeGraphics();

  setUsername("Host");

  while(true){
    
    windowLoop(client);
    
    char data[1000]= "";

    std::size_t received;

    if(client.receive(data, 1000, received) != sf::Socket::Done){

    }
    if(strcmp(data, "")){
      addText(std::string(data));
    }


  
  }
}
