#pragma once

#include "GridView.h"
#include "ListView.h"
#include "Board.h"

void grid_view_to_list_view(const GridView &grid_view, ListView &list_view);

void print_board(const GridView &grid_view);

Board *load_board_from_file(const char *filename);