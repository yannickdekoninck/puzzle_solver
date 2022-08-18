#include "common.h"
#include "Utilities.h"

void grid_view_to_list_view(const GridView &grid_view, ListView &list_view)
{
    char current_item;
    for (int i = 0; i < grid_view.get_width(); i++)
    {
        for (int j = 0; j < grid_view.get_height(); j++)
        {
            current_item = grid_view.get_description(i, j);
            if (current_item != empty_symbol)
            {
                list_view.add_item(ListItem(i, j, current_item));
            }
        }
    }
}