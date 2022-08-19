#pragma once
#include <vector>
#include "common.h"
struct ListItem
{
    int x, y;
    char symbol;
    ListItem(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}
    ListItem() : ListItem(0, 0, empty_symbol) {}
};

class ListView
{
public:
    ListView() {}
    inline void add_item(ListItem new_item) { list_items.push_back(new_item); }
    inline size_t item_count() const { return list_items.size(); }
    inline ListItem get_item(int id) const { return list_items[id]; }
    void replace_symbol(const char new_symbol);

private:
    std::vector<ListItem> list_items;
};