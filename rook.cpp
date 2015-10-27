#include "rook.h"
#include <iostream>

Rook::Rook(int _player, int _x, int _y)
	:Piece(_player, _x, _y)
{	
	std::cout<<"Building a rook\n";
}

Rook::~Rook()
{
	std::cout<<"Destroying a rook *BOOM*\n";
}

void Rook::Draw()
{
	std::cout<<"R";
}
