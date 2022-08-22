#pragma once
#include <vector>
#include "GridView.h"
#include "Piece.h"

class Board : public GridView
{
public:
    Board(int width, int height, std::vector<Piece *> &pieces) : GridView(width, height), pieces(pieces) {}

    bool put_piece(const PieceView &piece_view, int x, int y);

    bool solve();

private:
    std::vector<Piece *> pieces;
};