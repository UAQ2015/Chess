#include "pawn.h"
#include <iostream>

Pawn::Pawn(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//        std::cout<<"Creating a pawn :p\n";
}

Pawn::~Pawn() {
    //       std::cout<<"Killing a pawn Meh!\n";
}

void Pawn::Draw() {
    std::cout << "p";
}

Pawn::Pawn(int _player, string _position, PiecesArray &_board) : Piece(_player, _position, _board) {

}
