#include "knight.h"
#include <iostream>

Knight::Knight(int _player, int _x, int _y)
        :Piece(_player, _x, _y)
{
//        std::cout<<"Creating a knight\n";
}

Knight::~Knight()
{
//        std::cout<<"Killing a knight\n";
}

void Knight::Draw()
{
        std::cout<<"C";
}


