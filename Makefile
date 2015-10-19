

objects=bishop.cpp  chessboard.cpp  king.cpp  knight.cpp  pawn.cpp  piece.cpp  queen.cpp  rook.cpp

all: chess


chess: main.cpp $(objects)
	g++ main.cpp $(objects) -o chess 

clean:
	rm chess 

