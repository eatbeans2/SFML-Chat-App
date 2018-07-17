all: NetClient NetHost

NetClient: netClient.o netGUI.o
	g++ netClient.o netGUI.o -o NetClient -L/Users/CaptainOfTheDishwasher/Desktop/Coding/CppLibraries/SFML-2.5.0-macOS-clang/lib -lsfml-network -lsfml-system -lsfml-window -lsfml-graphics

netClient.o: netClient.cpp
	g++ -c netClient.cpp -I/Users/CaptainOfTheDishwasher/Desktop/Coding/CppLibraries/SFML-2.5.0-macOS-clang/include

NetHost: netHost.o netGUI.o
	g++ netHost.o netGUI.o -o NetHost -L/Users/CaptainOfTheDishwasher/Desktop/Coding/CppLibraries/SFML-2.5.0-macOS-clang/lib -lsfml-network -lsfml-system -lsfml-window -lsfml-graphics

netHost.o: netHost.cpp
	g++ -c netHost.cpp -I/Users/CaptainOfTheDishwasher/Desktop/Coding/CppLibraries/SFML-2.5.0-macOS-clang/include

netGUI.o: netGUI.cpp netGUI.h
	g++ -c netGUI.cpp -I/Users/CaptainOfTheDishwasher/Desktop/Coding/CppLibraries/SFML-2.5.0-macOS-clang/include

clean:
	rm *.o output