#pragma once
#include <vector>
#include "common.h"
#include "GridView.h"

class Piece
{
public:
    Piece() : id(piece_symbol){};
    Piece(const char symbol) : id(symbol){};
    char id;
    void add_piece_view(GridView &new_p);

private:
    std::vector<GridView *> piece_views;
};
