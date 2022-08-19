#include "common.h"
#include "Board.h"

bool Board::put_piece(const PieceView &piece_view, int x, int y)
{

    // Check if item can be placed
    ListItem li;
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        if (get_description(x + li.x, y + li.y) != empty_symbol)
        {
            return false;
        }
    }

    // Place items
    for (int i = 0; i < piece_view.list_view.item_count(); i++)
    {
        li = piece_view.list_view.get_item(i);
        set_description(x + li.x, y + li.y, li.symbol);
    }
    return true;
}
