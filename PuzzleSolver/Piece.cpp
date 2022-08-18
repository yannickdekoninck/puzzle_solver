#include "Piece.h"

void Piece::add_piece_view(GridView &new_p)
{
    piece_views.push_back((GridView *)(&new_p));
    // Set the symbol to the piece symbol
    new_p.replace_symbol(id);
}