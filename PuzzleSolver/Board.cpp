#include "common.h"
#include "Board.h"
#include "Utilities.h"

bool Board::put_piece(const PieceView &piece_view, int x, int y)
{

    // Check if item can be placed
    ListItem li;
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        if (get_description(x + li.coords.x, y + li.coords.y) > empty_symbol)
        {
            return false;
        }
    }

    // Place items
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        set_description(x + li.coords.x, y + li.coords.y, li.symbol);
    }
    return true;
}

void Board::remove_piece(const PieceView &piece_view, int x, int y)
{

    // Check if item can be removed
    ListItem li;
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        if (get_description(x + li.coords.x, y + li.coords.y) != li.symbol)
        {
            // This is not a valid remove operation
            return;
        }
    }

    // Remove items
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        set_description(x + li.coords.x, y + li.coords.y, empty_symbol);
    }
    return;
}

void Board::update_open_neighbours()
{
    update_open_neighbours(0, get_width() - 1, 0, get_height() - 1);
}

void Board::update_open_neighbours(int xmin, int xmax, int ymin, int ymax)
{
    lowest_open_neighbour_count = 9;
    for (int i = xmin; i <= xmax; i++)
    {
        for (int j = ymin; j <= ymax; j++)
        {
            char current_symbol = get_description(i, j);
            if (current_symbol <= empty_symbol)
            {
                int empty_neighbour_count = 0;
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if ((l == 0) && (k == 0))
                        {
                            // Don't check the symbol itself
                            continue;
                        }
                        if (get_description(i + k, j + l) <= empty_symbol)
                        {
                            // This is an empty spot
                            empty_neighbour_count++;
                        }
                    }
                }
                if (empty_neighbour_count < lowest_open_neighbour_count)
                {
                    lowest_open_neighbour_count = empty_neighbour_count;
                    lowest_open_neighbour_location = Coord2{i, j};
                }
                set_description(i, j, empty_neighbour_count);
            }
        }
    }
}

int Board::tries = 0;

bool Board::solve()
{
    tries++;
    // Loop through all pieces
    for (int i = 0; i < pieces.size(); i++)
    {
        Piece &p = *pieces[i];
        // Check if piece is already placed
        if (p.placed)
        {
            continue;
        }
        // Loop over the different views
        for (int j = 0; j < p.number_of_views(); j++)
        {
            PieceView &pv = *p.get_view(j);
            // Loop over the placements that would work for this # of meighbours
            for (int k = lowest_open_neighbour_count; k > 0; k--)
            {

                for (int l = 0; l < pv.neighbours[k].size(); l++)
                {
                    Coord2 offset = pv.neighbours[k][l];
                    Coord2 placement{lowest_open_neighbour_location.x - offset.x, lowest_open_neighbour_location.y - offset.y};
                    if (put_piece(pv, placement.x, placement.y))
                    {
                        // We were able to place the piece
                        p.placed = true;
                        update_open_neighbours();

                        // Check if all pieces are placed

                        bool all_placed = true;
                        for (int m = 0; m < pieces.size(); m++)
                        {
                            if (pieces[m]->placed == false)
                            {
                                all_placed = false;
                                break;
                            }
                        }
                        if (all_placed)
                        {
                            return true;
                        }

                        //  Check if we can solve the board
                        if (solve())
                        {
                            return true;
                        }
                        // We couldn't solve the board with this placement
                        // Romve the pieceview again
                        remove_piece(pv, placement.x, placement.y);
                        p.placed = false;
                        // Make sure the open neighbours are consistent again
                        update_open_neighbours();
                    }
                }
            }
        }
    }

    return false;
}