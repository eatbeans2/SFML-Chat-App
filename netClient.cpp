//Testing SFML through Emacs

#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "netGUI.h"

int main(){

  sf::TcpSocket socket;
  
  sf::Socket::Status status = socket.connect("192.168.1.10", 23000);
  if(status != sf::Socket::Done){
    std::cout << "Problem" << std::endl;
  }

  socket.setBlocking(false);

  initializeGraphics();

  setUsername("Client");

  while(true){

    windowLoop(socket);

    char data[1000]= "";

    std::size_t received;

    if(socket.receive(data, 1000, received) != sf::Socket::Done){

    }
    if(strcmp(data, "")){
      addText(std::string(data));
    }


  }
}
