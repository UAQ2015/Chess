#include "chessboard.h"

#include <iostream>

using namespace std;

ChessBoard::ChessBoard() :
        board{0} {
    turn = 1;
    winner = 0;

    FillBoard();
}

ChessBoard::~ChessBoard() {
    Piece *p = NULL;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            p = board[i][j];
            if (p != NULL) {
                delete p;
            }
        }
    }
}

void ChessBoard::FillBoard() {
    int row;
    Pawn *p = NULL;
    for (int j = 1; j <= 2; j++)
        for (int i = 0; i < 8; i++) {
            row = 1 + 5 * (j - 1);
            p = new Pawn(j, row, i, board);
            board[row][i] = p;
        }

    Bishop *b = NULL;
    for (int j = 1; j <= 2; j++)
        for (int i = 2; i <= 5; i = i + 3) {
            row = 7 * (j - 1);
            b = new Bishop(j, row, i, board);
            board[row][i] = b;
        }

    Rook *r = NULL;
    for (int j = 1; j <= 2; j++)
        for (int i = 0; i <= 7; i = i + 7) {
            row = 7 * (j - 1);
            r = new Rook(j, row, i, board);
            board[row][i] = r;
        }
    Knight *c = NULL;
    for (int j = 1; j <= 2; j++)
        for (int i = 1; i <= 6; i = 5 + i) {
            row = 7 * (j - 1);
            c = new Knight(j, row, i, board);
            board[row][i] = c;
        }
    Queen *q = NULL;
    for (int j = 1; j <= 2; j++) {
        row = 7 * (j - 1);
        q = new Queen(j, row, 3, board);
        board[row][3] = q;
    }

    King *k = NULL;
    for (int j = 1; j <= 2; j++) {
        row = 7 * (j - 1);
        k = new King(j, row, 4, board);
        board[row][4] = k;
    }
}

void ChessBoard::Draw() {
    Piece *p = NULL;
    char white = ' ';
    char black = '#';
    for (int i = 0; i < 8; i++) {
        cout<<8-i<<"| ";
        for (int j = 0; j < 8; j++) {
            p = board[i][j];
            if (p == NULL) {
                if ((i + j) % 2 == 0) {
                    cout << white;
                } else {
                    cout << black;
                }
            } else {
                p->Draw();
            }

        }
        cout << endl;
    }
    cout<<"   ";
    for (int i = 1; i <= 8; i++)
        cout<<"_";
    cout<<endl;
    cout<<"   ";
    for (int i = 0; i < 8; i++)
        cout<<(char)('A'+i);
    cout<<endl;
}

/**
 * This method returns a piece pointer from a given string.
 * the string format follows the algebraic format, example
 * e2
 * @param origin string of the origin movement in algebraic format.
 * @returns a pointer to a piece
 */
Piece *ChessBoard::GetPiece(string origin) {
    Piece *p = NULL;
    int r = 0, c = 0;

    // TODO: validate that the string is the correct format, regexp recommended

    c = (int) (origin[0] - 'a'); // letters are the columns
    r = (int) 8 - (origin[1] - '0'); // numbers are rows
    cout << "row is: " << r << endl;
    cout << "col is: " << c << endl;

    p = board[r][c];

    return p;
}

bool ChessBoard::Validate(Piece *p, string move) {
    return p->Validate(move);
}


void ChessBoard::CleanBoard() {
    Piece *p = NULL;
    for (int row = 0; row < 8; row++)
        for (int col = 0; col < 8; col++) {
            p= board[row][col];
            if(p){
                delete p;
                board[row][col]= NULL;
            }
        }
}

void ChessBoard::TestRook() {
    Piece *p;
    bool v;

    // Initialize Rook
    CleanBoard();

    // Put only 2 pieces to test
    string origin = "a4";
    Rook *rk= new Rook(1, origin, board);
    board[4][0]=rk;

    Pawn *pw1= new Pawn(2, "a3", board);
    board[5][0]=pw1;

    Pawn *pw2= new Pawn(1, "h4", board);
    board[4][7]=pw2;

    Draw();


    // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "a4"<<"\n";
    p= GetPiece("a4");

    if (p!=NULL) {
        p->Draw();
        cout<<"\nplayer: "<< p->player<<endl;
    }
    else cout<<"null";

    string dest="e4";
    cout<<"trying to move rook horizontally to "<<dest<<" \n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="a7";
    cout<<"trying to move rook vertically to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="d5";
    cout<<"trying to make an invalid rook move to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "a3";
    cout<<"trying to capture a piece at "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h4";
    cout<<"trying to capture a piece from the same player at "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

}
