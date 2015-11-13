#include "bishop.h"
#include <iostream>

Bishop::Bishop(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board)
{
//        std::cout<<"Creating a Bishop\n";
}

Bishop::~Bishop()
{
//        std::cout<<"Killing a Bishop\n";
}

void Bishop::Draw()
{
        std::cout<<"B";
}

Bishop::Bishop(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}
