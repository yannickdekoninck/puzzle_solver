#include "common.h"
#include "Board.h"
#include "Utilities.h"

// Static members

int Board::tries = 0;

// Constructor

Board::Board(int width, int heigth, std::vector<Piece *> &pieces, const char *board) : Board(width, heigth, pieces)
{
    // copy content of board into our local view
    for (int i = 0; i < width * heigth; i++)
    {
        piece_description[i] = board[i];
    }
}

// Methods

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

bool Board::validate_board()
{
    // This method is not optimized for speed - this only runs once

    // Set all pieces to not placed
    for (int i = 0; i < pieces.size(); i++)
    {
        pieces[i]->placed = false;
    }
    // Set all symbols in board that are < A to empty symbol
    for (int i = 0; i < width * height; i++)
    {
        if (piece_description[i] < 'A')
        {
            piece_description[i] = empty_symbol;
        }
    }
    // Loop through the pieces

    int placed_items = 0;
    for (int i = 0; i < pieces.size(); i++)
    {
        Piece &p = *pieces[i];
        std::vector<Coord2> occurences;
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                if (get_description(x, y) == p.id)
                {
                    occurences.push_back(Coord2{x, y});
                }
            }
        }
        int symbol_occurences = occurences.size();
        if (symbol_occurences > 0)
        {
            // This symbol occurs
            unsigned int expected_symbol_occurences = p.get_view(0)->list_view.item_count();
            if (symbol_occurences != expected_symbol_occurences)
            {
                // This cannot be valid
                return false;
            }
            // The number of occurences makes sense, that's good!
            // Let's see if we can place it
            for (int j = 0; j < symbol_occurences; j++)
            {

                for (int k = 0; k < p.number_of_views(); k++)
                {
                    ListView &lv = p.get_view(k)->list_view;
                    bool all_match = true;
                    for (int l = 0; l < lv.item_count(); l++)
                    {
                        Coord2 c = lv.get_item(l).coords + occurences[j] - lv.get_item(0).coords;

                        if (get_description(c.x, c.y) != p.id)
                        {
                            all_match = false;
                            break;
                        }
                    }
                    if (all_match)
                    {
                        p.placed = true;
                        placed_items += expected_symbol_occurences;
                        break;
                    }
                }
                if (p.placed)
                {
                    break;
                }
            }
        }
    }

    int empty_symbol_count = 0;
    for (int i = 0; i < width * height; i++)
    {
        if (piece_description[i] == empty_symbol)
        {
            empty_symbol_count++;
        }
    }

    if ((width * height - placed_items - empty_symbol_count) != 0)
    {
        return false;
    }
    return true;
}

//     - count the number of this symbols occurs
//          should be 0 or the number of items in that piece
//      - If the number matches, try to fit any of the views

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
                            // Solved the board!
                            bool solution_exists = false;
                            for (int m = 0; m < solutions.size(); m++)
                            {
                                if (solutions[m].equals(*this))
                                {
                                    solution_exists = true;
                                    break;
                                }
                            }
                            if (solution_exists == false)
                            {
                                solutions.push_back((GridView) * this);
                            }
                            return true;
                        }

                        //  Check if we can solve the board
                        solve();

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