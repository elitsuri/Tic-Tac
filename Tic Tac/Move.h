#pragma once

class Move
{
public:
	Move(int i, int j, int piece) : i(i), j(j), piece(piece) {}
	int getI(void) { return i; }
	int getJ(void) { return j; }
	int getPiece(void) { return piece; }
private:
	int i;
	int j;
	int piece;
};
