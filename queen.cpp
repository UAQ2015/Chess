#include "queen.h"
#include <iostream>

Queen::Queen(int _player, int _x, int _y)
        :Piece(_player, _x, _y)
{
	std::cout<<"Creating a Queen\n";
}

Queen::~Queen()
{
	std::cout<<"Killing a Queen :s\n";
}

void Queen::Draw()
{
        std::cout<<"Q";
}


