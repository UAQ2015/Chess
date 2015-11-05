#include "chessboard.h"

#include <iostream>

using namespace std;

ChessBoard::ChessBoard():
    board{ 0 }
{
    turn = 1;
    winner = 0;

    FillBoard();
    Draw();
}

ChessBoard::~ChessBoard()
{
	Piece *p=NULL;
	for(int i=0; i<8;i++){
		for(int j=0; j<8;j++){
			p= board[i][j];
			if (p!=NULL){
				delete p;
			}
		}
	}
}

void ChessBoard::FillBoard()
{
    int row;
    Pawn *p=NULL;
    for(int j=1;j<=2;j++)
        for(int i=0;i<8;i++)
        {
            row= 1+5*(j-1);
            p= new Pawn(j, row, i);
            board[row][i]= p;
        }

    Bishop *b=NULL;
      for(int j=1;j<=2;j++)
        for(int i=2;i<=5;i=i+3)
        {
            row=7*(j-1);
            b= new Bishop(j, row, i);
            board[row][i]= b;
        }

     Rook *r=NULL;
      for(int j=1;j<=2;j++)
        for(int i=0;i<=7;i=i+7)
        {
            row=7*(j-1);
            r= new Rook(j, row, i);
            board[row][i]= r;
        }
    Knight *c=NULL;
      for(int j=1;j<=2;j++)
        for(int i=1;i<=6;i=5+i)
        {
            row=7*(j-1);
            c= new Knight(j, row, i);
            board[row][i]= c;
        }
     Queen *q=NULL;
      for(int j=1;j<=2;j++)
        {
            row=7*(j-1);
            q= new Queen(j, row, 3);
            board[row][3]= q;
        }

     King *k=NULL;
      for(int j=1;j<=2;j++)
        {
            row=7*(j-1);
            k= new King(j, row, 4);
            board[row][4]= k;
        }

	Rook *rk= new Rook(1, 4, 0);
	board[4][0]=rk;

	Piece *piece= NULL;
    for(int j=0;j<8;j++)
        for(int i=0;i<8;i++){
			piece= board[i][j];
			if(piece!=NULL)
				piece->board= (Piece ***) board;
		}



}

void ChessBoard::Draw()
{
    Piece *p=NULL;
    char white= ' ';
    char black= '#';
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
        {
            p=board[i][j];
            if (p==NULL){
                if ((i+j)%2==0){
                    cout<<white;
                }else{
                    cout<<black;
                }
            }else{
                p->Draw();
            }

        }
        cout<<endl;
    }
}

/**
 * This method returns a piece pointer from a given string.
 * the string format follows the algebraic format, example
 * e2
 * @param origin string of the origin movement in algebraic format.
 * @returns a pointer to a piece
 */
Piece *ChessBoard::GetPiece(string origin){
	Piece *p=NULL;
	int r=0, c=0;

	// TODO: validate that the string is the correct format, regexp recommended

	c= (int) (origin[0]-'a'); // letters are the columns
	r= (int) 8- (origin[1]-'0'); // numbers are rows
	cout<<"row is: "<<r<<endl;
	cout<<"col is: "<<c<<endl;

	p= board[r][c];

	return p;
}

bool ChessBoard::Validate(Piece *p, string move){
	return p->Validate(move);
}













