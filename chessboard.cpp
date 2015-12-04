#include "chessboard.h"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"
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
    p = board[r][c];
    return p;
}

bool ChessBoard::Validate(Piece *p, string move) {
    int cf,rf; 
    Piece *pp=NULL;
    cf = (int) (move[0] - 'a'); // letters are the columns
    rf = (int) 8 - (move[1] - '0'); // num 
    pp=board[cf][rf];
    if(pp==NULL){
	cout<<"There is no piece in "<<move<<"\n";
	return false;
    }
    if (p->player!=turn){
        cout<<"not your piece!!\n";
        return false;
    }
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
    string origin = "b7";
    Rook *rk= new Rook(1, origin, board);
    board[1][1]=rk;

    Pawn *pw1= new Pawn(2, "a3", board);
    board[5][0]=pw1;

    Pawn *pw2= new Pawn(1, "h4", board);
    board[4][7]=pw2;

    Draw();


    // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "b7"<<"\n";
    p= GetPiece("b7");

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

    dest="c4";
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

void ChessBoard::TestPawn() {
    Piece *p;
    bool v;

    // Initialize Pawn
    CleanBoard();

    // Put only 2 pieces to test
    string origin = "b7";
    Pawn *rk= new Pawn(1, origin, board);
    board[1][1]=rk;

    Pawn *pw1= new Pawn(2, "a6", board);
    board[2][0]=pw1;

    Pawn *pw2= new Pawn(1, "c6", board);
    board[2][3]=pw2;

    Draw();
 // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "a4"<<"\n";
    p= GetPiece("b7");

    if (p!=NULL) {
        p->Draw();
        cout<<"\nplayer: "<< p->player<<endl;
    }
    else cout<<"null";

    string dest="b6";
    cout<<"trying to move one vertically "<<dest<<" \n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="b5";
    cout<<"trying to move two vertically to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="a6";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "d6";
    cout<<"trying to do an invalid move "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "c6";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

}

void ChessBoard::TestBishop() {
   Piece *p;
    bool v;

    // Initialize Bishop
    CleanBoard();

    // Put only 2 pieces to test
    string origin = "b7";
    Bishop *rk= new Bishop(1, origin, board);
    board[1][1]=rk;

    Pawn *pw1= new Pawn(2, "a6", board);
    board[2][0]=pw1;

    Pawn *pw2= new Pawn(1, "c6", board);
    board[2][3]=pw2;

    Draw();
 // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "a4"<<"\n";
    p= GetPiece("b7");

    if (p!=NULL) {
        p->Draw();
        cout<<"\nplayer: "<< p->player<<endl;
    }
    else cout<<"null";

    string dest="b6";
    cout<<"trying to move one vertically "<<dest<<" \n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="b5";
    cout<<"trying to move two vertically to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="a6";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h1";
    cout<<"trying to do an invalid move "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h1";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

}

void ChessBoard::TestKnight() {
   Piece *p;
    bool v;

    // Initialize Bishop
    CleanBoard();

    // Put only 2 pieces to test
    string origin = "e5";
    Knight *rk= new Knight(1, origin, board);
    board[3][4]=rk;

    Pawn *pw1= new Pawn(1, "c4", board);
    board[4][2]=pw1;

    Pawn *pw2= new Pawn(1, "c6", board);
    board[2][3]=pw2;

    Draw();
 // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "a4"<<"\n";
    p= GetPiece("e5");

    if (p!=NULL) {
        p->Draw();
        cout<<"\nplayer: "<< p->player<<endl;
    }
    else cout<<"null";

    string dest="g4";
    cout<<"trying to move to "<<dest<<" \n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="c6";
    cout<<"trying to move to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="c4";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h1";
    cout<<"trying to do an invalid move "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h1";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

}

void ChessBoard::TestQueen() {
   Piece *p;
    bool v;

    // Initialize Queen
    CleanBoard();

    // Put only 2 pieces to test
    string origin = "b7";
    Queen *rk= new Queen(1, origin, board);
    board[1][1]=rk;

    Pawn *pw1= new Pawn(2, "a6", board);
    board[2][0]=pw1;

    Pawn *pw2= new Pawn(1, "c6", board);
    board[2][3]=pw2;

    Draw();
 // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "b7"<<"\n";
    p= GetPiece("b7");

    if (p!=NULL) {
        p->Draw();
        cout<<"\nplayer: "<< p->player<<endl;
    }
    else cout<<"null";

    string dest="b6";
    cout<<"trying to move one vertically "<<dest<<" \n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="b1";
    cout<<"trying to move vertically to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="a6";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "c4";
    cout<<"trying to do an invalid move "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h1";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

}

void ChessBoard::TestKing() {
   Piece *p;
    bool v;

    // Initialize King
    CleanBoard();

    // Put only 2 pieces to test
    string origin = "b7";
    King *rk= new King(1, origin, board);
    board[1][1]=rk;

    Pawn *pw1= new Pawn(2, "a6", board);
    board[2][0]=pw1;

    Pawn *pw2= new Pawn(1, "c6", board);
    board[2][3]=pw2;

    Draw();
 // Testing movements
    cout<< "Putting a piece on the chessboard at "<< "b7"<<"\n";
    p= GetPiece("b7");

    if (p!=NULL) {
        p->Draw();
        cout<<"\nplayer: "<< p->player<<endl;
    }
    else cout<<"null";

    string dest="b6";
    cout<<"trying to move one vertically "<<dest<<" \n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");
    dest="b1";
    cout<<"trying to move vertically to "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest="a6";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "c4";
    cout<<"trying to do an invalid move "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

    dest= "h1";
    cout<<"trying to capture "<<dest<<"\n";
    v= Validate(p, dest);
    cout << (v ? "\tvalid\n" : "\tinvalid\n");

}

void ChessBoard::Move(Piece *p, string dest) {
    int choice;
    int ro= p->r;
    int co= p->c;
    int cd = (int) (dest[0] - 'a'); // letters are the columns
    int rd = (int) 8 - (dest[1] - '0'); // numbers are rows

    if(board[rd][cd]!=NULL){
        delete board[rd][cd];
        board[rd][cd]= NULL;
    }
    board[rd][cd]=p;
    board[ro][co]=NULL;
    p->Move(rd,cd);
    if( p->pawn_type == true && p->player == 1 && rd == 7){
	cout<<"Choose your piece:\n1.-Queen\n2.-Rook\n3.-Knight\n4.-Bishop";
	cin>>choice;
	delete p;
	switch (choice)
	{
		case 1:
			Queen *qn = new Queen(1,dest,board); 
			board[rd][cd]=qn;
			break;
		case 2:
			Rook *rk = new Rook(1,dest,board);
			board[rd][cd]=rk;
			break;
		case 3: 
			Knight *kn = new Knight(1,dest,board);
			board[rd][cd]=kn;
			break;
		case 4: 
			Bishop *Bh = new Bishop(1,dest,board);
			board[rd][cd]=Bh;
			break;
		default:
			cout<<"F*ck you, stay with your f*cking pawn";
			break;
	}
    }
    if( p->pawn_type == true && p->player == 2 && rd == 0){
        cout<<"Choose your piece:\n1.-Queen\n2.-Rook\n3.-Knight\n4.-Bishop";
        cin>>choice;
        delete p;
        switch (choice)
        {
                case 1:
                        Queen *nq = new Queen(2,dest,board);
			board[rd][cd]=nq;
			break;
                case 2:
                        Rook *kr = new Rook(2,dest,board);
			board[rd][cd]=kr;
			break;
                case 3:
                        Knight *nk = new Knight(2,dest,board);
			board[rd][cd]=nk;
			break;
                case 4:
                        Bishop *hb = new Bishop(2,dest,board);
			board[rd][cd]=hb;
			break;
                default:
                        cout<<"F*ck you, stay with your f*cking pawn";
			break;
        }
    }

}
void ChessBoard::ChangeTurn() {
    if(turn==1)
        turn= 2;
    else
        turn=1;
    int kings = 0;
    Piece *p;
    for (int tr = 0; tr < 8; tr++)
	for(int tc = 0; tc < 8; tc++){
		if (board[tr][tc] != NULL)
		{
			p=board[tr][tc];
			if ((p -> king_type) == true)
				kings++;
		}
	}
    if (kings != 2)
	winner = 1;
}
