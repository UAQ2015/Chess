

objects=bishop.o  chessboard.o  king.o  knight.o  pawn.o  piece.o  queen.o  rook.o

all: chess

%.o: %.cpp
	   g++ -c -o $@ $<
	

chess: main.cpp $(objects)
	g++ main.cpp $(objects) -o chess 

clean:
	rm chess *.o

