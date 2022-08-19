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

bool Piece::check_if_grid_view_exists(const GridView &grid_view)
{
    for (int i = 0; i < number_of_views(); i++)
    {
        if (get_view(i)->grid_view.equals(grid_view))
        {
            return true;
        }
    }
    return false;
}

void Piece::add_mirror_variant_pieceviews(const GridView &grid_view)
{
    if (!check_if_grid_view_exists(grid_view))
    {
        add_piece_view_based_on_grid_view(grid_view);
    }

    // Add x-mirrored version if unique
    GridView gv_mx(grid_view);
    gv_mx.mirror_x();
    if (!check_if_grid_view_exists(gv_mx))
    {
        add_piece_view_based_on_grid_view(gv_mx);
    }

    // Add y-mirrored version if unique
    GridView gv_my(grid_view);
    gv_my.mirror_y();
    if (!check_if_grid_view_exists(gv_my))
    {
        add_piece_view_based_on_grid_view(gv_my);
    }

    // Add xy-mirrored version if unique
    GridView gv_mxy(grid_view);
    gv_mxy.mirror_x();
    gv_mxy.mirror_y();
    if (!check_if_grid_view_exists(gv_mxy))
    {
        add_piece_view_based_on_grid_view(gv_mxy);
    }
}

// Main piece constructor
Piece::Piece(const char symbol, const GridView &grid_view) : id(symbol)
{

    // Try x/y/xy mirror variants
    add_mirror_variant_pieceviews(grid_view);

    // Diagonal mirror
    GridView gv_diag(grid_view);
    gv_diag.mirror_diagonal();

    add_mirror_variant_pieceviews(gv_diag);
}