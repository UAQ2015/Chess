#include "knight.h"
#include <iostream>

Knight::Knight(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board)
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


Knight::Knight(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}
