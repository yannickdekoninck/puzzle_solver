#include "ListView.h"

void ListView::replace_symbol(const char new_symbol)
{
    for (int i = 0; i < this->list_items.size(); i++)
    {
        list_items[i].symbol = new_symbol;
    }
}