#include <cmath>
#include "Piece.h"
#include "Utilities.h"

void PieceView::calculate_neighbours()
{
    ListItem current_li;
    ListItem test_li;
    for (int i = 0; i < list_view.item_count(); i++)
    {
        int neighbour_count = 0;
        current_li = list_view.get_item(i);
        for (int j = 0; j < list_view.item_count(); j++)
        {
            if (i != j)
            {
                test_li = list_view.get_item(j);
                if ((abs(test_li.coords.x - current_li.coords.x) < 2) & (abs(test_li.coords.y - current_li.coords.y) < 2))
                {
                    neighbour_count++;
                }
            }
        }

        neighbours[neighbour_count].push_back(current_li.coords);
    }
}

void Piece::add_piece_view_based_on_grid_view(const GridView &grid_view)
{
    ListView lv;
    PieceView pv;

    grid_view_to_list_view(grid_view, lv);
    pv.grid_view = grid_view;
    pv.list_view = lv;
    pv.calculate_neighbours();
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
Piece::Piece(const char symbol, const GridView &grid_view) : id(symbol), placed(false)
{
    initialize_with_grid_view(grid_view);
}

void Piece::initialize_with_grid_view(const GridView &grid_view)
{
    // Try x/y/xy mirror variants
    add_mirror_variant_pieceviews(grid_view);

    // Diagonal mirror
    GridView gv_diag(grid_view);
    gv_diag.mirror_diagonal();

    add_mirror_variant_pieceviews(gv_diag);

    // Set the correct symbol
    for (int i = 0; i < number_of_views(); i++)
    {
        get_view(i)->grid_view.replace_symbol(id);
        get_view(i)->list_view.replace_symbol(id);
    }
}