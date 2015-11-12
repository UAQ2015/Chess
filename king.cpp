#include "king.h"
#include <iostream>

King::King(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board)
{
//        std::cout<<"Creating a King\n";
}

King::~King()
{
//        std::cout<<"Killing a King?\n";
}

void King::Draw()
{
        std::cout<<"K";
}


King::King(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}
