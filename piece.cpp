#include "piece.h"
#include <iostream>
//using namespace std;

Piece::Piece(int _player, int _r, int _c)
{
	player = _player;
	r = _r;
	c = _c;
//	std::cout<<"Calling constructor\n";
}

void Piece::Draw()
{
    std::cout<< "X\n";
}

//	desctructor
Piece::~Piece()
{
//	std::cout<<"Calling destructor\n";
}


bool Piece::Validate(string ){
}

