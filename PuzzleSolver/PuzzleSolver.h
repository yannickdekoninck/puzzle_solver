// PuzzleSolver.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "Board.h"
#include "Pieces.h"

class PuzzleSolverApp
{

public:
    // Constructor taking app arguments
    PuzzleSolverApp(int argc, char **argv);
    ~PuzzleSolverApp();

    void run();
    bool initialized();

private:
    // UI settings

    int max_solutions;

    int board_width;
    int board_height;
    // The board to play
    Board *board;

    // The pieces we use
    Pieces p;
};