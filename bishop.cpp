#include "bishop.h"
#include <iostream>

Bishop::Bishop(int _player, int _x, int _y)
        :Piece(_player, _x, _y)
{
        std::cout<<"Creating a Bishop\n";
}

Bishop::~Bishop()
{
        std::cout<<"Killing a Bishop\n";
}

void Bishop::Draw()
{
        std::cout<<"B";
}

