#pragma once
#include <vector>
#include "common.h"
#include "GridView.h"
#include "ListView.h"

// A pieceview has a grid and list view
struct PieceView
{
    GridView grid_view;
    ListView list_view;
};

class Piece
{
public:
    Piece(const GridView &grid_view) : Piece(piece_symbol, grid_view){};
    Piece(const char symbol, const GridView &grid_view);
    char id;

    inline size_t number_of_views() const { return piece_views.size(); }
    inline PieceView *get_view(int id) const { return (PieceView *)&(piece_views[id]); }

private:
    std::vector<PieceView> piece_views;
    void add_piece_view_based_on_grid_view(const GridView &grid_view);
};
