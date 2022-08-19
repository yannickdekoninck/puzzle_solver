#include "Piece.h"
#include "Utilities.h"

void Piece::add_piece_view_based_on_grid_view(const GridView &grid_view)
{
    ListView lv;
    PieceView pv;

    grid_view_to_list_view(grid_view, lv);
    pv.grid_view = grid_view;
    pv.list_view = lv;
    piece_views.push_back(pv);
}

// Main piece constructor
Piece::Piece(const char symbol, const GridView &grid_view) : id(symbol)
{
    // Start by setting the grid view as the first piece view
    add_piece_view_based_on_grid_view(grid_view);
}