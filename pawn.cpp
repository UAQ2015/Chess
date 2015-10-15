#include "pawn.h"
#include <iostream>

Pawn::Pawn(int _player, int _x, int _y)
        :Piece(_player, _x, _y)
{
        std::cout<<"Creating a pawn :p\n";
}

Pawn::~Pawn()
{
        std::cout<<"Killing a pawn Meh!\n";
}

void Pawn::Draw()
{
        std::cout<<"Pawn\n";
}

