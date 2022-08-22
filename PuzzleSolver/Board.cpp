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