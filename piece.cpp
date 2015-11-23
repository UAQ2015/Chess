#include "piece.h"
#include <iostream>
#include <array>
//using namespace std;

Piece::Piece(int _player, int _row, int _col, PiecesArray &_board): board(_board)
{
	player = _player;
	first_move=true;
	r = _row;
	c = _col;
//	std::cout<<"Calling constructor\n";
}

Piece::Piece(int _player, string position, PiecesArray &_board): board(_board) {
	player = _player;

	c = (int) (position[0] - 'a'); // letters are the columns
	r = (int) 8 - (position[1] - '0'); // numbers are rows
}


void Piece::Draw()
{
    std::cout<< "X\n";
}

//	desctructor
Piece::~Piece()
{
//	std::cout<<"Calling destructor\n";
}


bool Piece::Validate(string ){
}

void Piece::Move(int rd, int cd) {
	r= rd;
	c= cd;
	first_move=false;
}
