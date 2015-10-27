#include "king.h"
#include <iostream>

King::King(int _player, int _x, int _y)
        :Piece(_player, _x, _y)
{
        std::cout<<"Creating a King\n";
}

King::~King()
{
        std::cout<<"Killing a King?\n";
}

void King::Draw()
{
        std::cout<<"K";
}


