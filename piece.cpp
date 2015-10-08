#include "piece.h"
#include <iostream>
//using namespace std;

Piece::Piece(int _player, int _x, int _y)
{
	player = _player;
	x = _x;
	y = _y;
	std::cout<<"Calling constructor\n";
}

void Piece::Draw()
{
	std::cout<< "piece\n";
}

//	desctructor
	Piece::~Piece()
{
	std::cout<<"Calling destructor\n";
}
