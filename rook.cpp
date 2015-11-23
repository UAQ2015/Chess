#include "rook.h"
#include <iostream>

Rook::Rook(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}


Rook::Rook(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//	std::cout<<"Building a rook\n";
}

Rook::~Rook() {
//	std::cout<<"Destroying a rook *BOOM*\n";
}

void Rook::Draw() {
    std::cout << "R";
}

bool Rook::Validate(string dest) {
    bool v = false;
    int cd = (int) (dest[0] - 'a'); // letters are the columns
    int rd = (int) 8 - (dest[1] - '0'); // numbers are rows

    if (c == cd) {
        int direction;
        direction = rd - r > 0 ? 1 : -1;
        for (int i = r + direction; i < rd; i++) {
            // cout << "Getting piece " << i << " " << c << endl;
            Piece *p = board[i][c];

            if (p != NULL) {
                cout << "There is a piece in the path\n";
                p->Draw();
                cout << endl;
                return false;
            }
        }
        if (board[rd][cd] == NULL || board[rd][cd]->player != player)
            return true;
        // the destination is a piece from the same player
        return false;
    } else if (r == rd) {
        int direction = rd - c > 0 ? 1 : -1;
        for (int i = c + direction; i < cd; i++) {
            // cout << "Getting piece " << i << " " << c << endl;
            Piece *p = board[r][i];

            if (p != NULL) {
                cout << "There is a piece in the path\n";
                p->Draw();
                cout << endl;
                return false;
            }
        }
        if (board[rd][cd] == NULL || board[rd][cd]->player != player)
            return true;
        // the destination is a piece from the same player
        return false;
    }
    else {
        //cout << "invalid movement\n";
        return false;
    }

    return v;
}

