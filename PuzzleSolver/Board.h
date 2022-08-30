#pragma once
#include <vector>
#include "GridView.h"
#include "Piece.h"

class Board : public GridView
{
public:
    Board(int width, int heigth, std::vector<Piece *> &pieces, const char *board);
    Board(int width, int height, std::vector<Piece*>& pieces) : GridView(width, height), pieces(pieces), lowest_open_neighbour_count(9), lowest_open_neighbour_location{0,0} {}

    bool put_piece(const PieceView &piece_view, int x, int y);
    void remove_piece(const PieceView &piece_view, int x, int y);

    void update_open_neighbours();
    void update_open_neighbours(int xmin, int xmax, int ymin, int ymax);

    bool solve();
    bool validate_board();
    inline void clear_solutions() { solutions.clear(); }
    inline unsigned int solution_count() const { return (unsigned int)solutions.size(); }
    inline GridView *get_solution(unsigned int id) const
    {
        if (id < solution_count())
        {
            return (GridView *)(&(solutions[id]));
        }
        return nullptr;
    }

    static int tries;

private:
    // Variables
    std::vector<Piece *> pieces;
    int lowest_open_neighbour_count;
    Coord2 lowest_open_neighbour_location;
    std::vector<GridView> solutions;

    // Methods
};