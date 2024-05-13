battleship: main.o helpers.o ship.o cell.o board.o user.o player.o ai.o
	g++ -o battleship main.o helpers.o ship.o cell.o board.o user.o player.o ai.o -g

main.o: helpers.h ship.h cell.h board.h user.h main.cpp
	g++ -c main.cpp -g

helpers.o: helpers.h helpers.cpp ship.h cell.h board.h user.h 
	g++ -c helpers.cpp -g

player.o: player.h player.cpp user.h user.cpp ship.h cell.h board.h
	g++ -c player.cpp -g

ai.o: ai.h ai.cpp user.h user.cpp ship.h cell.h board.h
	g++ -c ai.cpp -g

user.o: user.h user.cpp ship.h cell.h board.h
	g++ -c user.cpp -g

board.o: board.h board.cpp ship.h cell.h
	g++ -c board.cpp -g

ship.o: ship.h ship.cpp cell.h
	g++ -c ship.cpp -g

cell.o: cell.h cell.cpp
	g++ -c cell.cpp -g

clean:
	rm *.o battleship