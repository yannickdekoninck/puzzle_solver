#include "common.h"
#include "Board.h"

bool Board::put_piece(const PieceView &piece_view, int x, int y)
{

    // Check if item can be placed
    ListItem li;
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        if (get_description(x + li.coords.x, y + li.coords.y) != empty_symbol)
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

bool Board::solve()
{
    // Step 1 find the most difficult position to place

    // Step 2 loop through the pieces that can sattisfy this placement

    // Step 2.1 loop through the piece views of the selected piece

    // Step 2.2 try to place every piece view

    // Step 2.3 if piece view fits -> recursively solve again but this piece removed from the list

    // How to keep track of which pieces can still be used and which ones can't?

    return true;
}