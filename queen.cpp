#include "queen.h"
#include <iostream>

Queen::Queen(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//    std::cout << "Creating a Queen\n";
}

Queen::~Queen() {
//    std::cout << "Killing a Queen :s\n";
}

void Queen::Draw() {
    std::cout << "Q";
}


Queen::Queen(int _player, string _position, PiecesArray &_board) : Piece(_player, _position, _board) {

}
