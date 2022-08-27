#include <iostream>
#include <map>
#include "common.h"
#include "Utilities.h"
#include "GridView.h"
#include "Windows.h"

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

void print_board(const GridView &grid_view)
{
    // color mapping for the different pieces
    std::map<char, int> color_map{
        {'A', 2}, {'B', 7}, {'C', 9}, {'D', 6}, {'E', 12}, {'F', 10}, {'G', 4}, {'H', 9}, {'I', 13}, {'J', 5}, {'K', 7}, {'L', 3}, {empty_symbol, 0}};

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 15);
    std::cout << std::endl;
    // Draw top border
    int width = grid_view.get_width();
    int height = grid_view.get_height();
    int draw_width = 2 * width + 3;
    for (int i = 0; i < draw_width; i++)
    {
        std::cout << border_symbol;
    }

    std::cout << std::endl;

    for (int j = 0; j < height; j++)
    {
        std::cout << border_symbol << " ";

        for (int i = 0; i < width; i++)
        {
            char current_symbol = grid_view.get_description(i, j);
            char current_symbol_color = current_symbol;
            if (current_symbol <= empty_symbol)
            {
                current_symbol_color = empty_symbol;
            }
            if (current_symbol < 10)
            {
                current_symbol += '0';
            }
            int color = color_map[current_symbol_color];
            SetConsoleTextAttribute(hConsole, color);
            std::cout << current_symbol << " ";
        }
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << border_symbol << std::endl;
    }

    for (int i = 0; i < draw_width; i++)
    {
        std::cout << border_symbol;
    }
    std::cout << std::endl;
}

/*
    load_board_from_file

    Load a board from file defined by path in filename
    Returns nullptr if board could not be loaded
    Caller is responsible for freeing created Board

*/

Board *load_board_from_file(const char *filename)
{
    // Load file to string

    // Get rid of spaces and newlines

    // Check if the length makes sense

    // Load the char* into a new board

    // Return the board

    return nullptr;
}