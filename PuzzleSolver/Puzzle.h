#pragma once
#include <vector>
#include <string>

class PieceView {
public: 
	PieceView(int width, int height) : width(width), height(height) {
		// Create an empty piece description
		piece_description = new int* [height];
		for (int i = 0; i < height; i++) {
			piece_description[i] = new int[width];
			for (int j = 0; j < width; j++) {
				piece_description[i][j] = 0;
			}
		}
	}
	int width;
	int height;
	int** piece_description;
};

class Piece {
public:
	int id;
	std::vector<PieceView*> piece_views;
};

class Board {
public:
	int* width;
	int heigth;
	int** board_content;
};