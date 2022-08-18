# CMakeList.txt : CMake project for PuzzleSolver, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (PuzzleSolver "PuzzleSolver.cpp" "PuzzleSolver.h" "Pieces.h" "Pieces.cpp" "GridView.h" "GridView.cpp" "Piece.h" "Piece.cpp" "ListView.h")

# TODO: Add tests and install targets if needed.
