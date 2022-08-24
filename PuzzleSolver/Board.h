#pragma once
#include <vector>
#include "GridView.h"
#include "Piece.h"

class Board : public GridView
{
public:
    Board(int width, int height, std::vector<Piece *> &pieces) : GridView(width, height), pieces(pieces), lowest_open_neighbour_count(9) {}

    bool put_piece(const PieceView &piece_view, int x, int y);
    void remove_piece(const PieceView &piece_view, int x, int y);

    void update_open_neighbours();
    void update_open_neighbours(int xmin, int xmax, int ymin, int ymax);

    bool solve();

    static int tries;

private:
    std::vector<Piece *> pieces;
    int lowest_open_neighbour_count;
    Coord2 lowest_open_neighbour_location;
};