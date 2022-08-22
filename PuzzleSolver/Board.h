#pragma once

#include "GridView.h"
#include "Piece.h"

class Board : public GridView
{
public:
    Board(int width, int height) : GridView(width, height) {}

    bool put_piece(const PieceView &piece_view, int x, int y);
};