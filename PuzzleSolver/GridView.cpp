#include "common.h"
#include "GridView.h"

GridView::GridView() : width(0), height(0)
{
    piece_description = nullptr;
}

GridView::GridView(int width, int height)
{
    piece_description = nullptr;
    initialize(width, height);
}

GridView::GridView(const GridView &other)
{
    width = other.width;
    height = other.height;
    piece_description = nullptr;
    if (other.piece_description == nullptr)
    {
        return;
    }
    initialize(width, height);
    copy_piece_description(other);
}

GridView::~GridView()
{
    free_piece_description();
}

GridView &GridView::operator=(const GridView &other)
{
    width = other.width;
    height = other.height;
    piece_description = nullptr;
    if (other.piece_description != nullptr)
    {
        initialize(width, height);
        copy_piece_description(other);
    }
    return *this;
}

void GridView::initialize(int width, int height)
{
    this->width = width;
    this->height = height;
    if (piece_description != nullptr)
    {
        free_piece_description();
    }
    // Create an empty piece description
    piece_description = new char *[height];
    for (int i = 0; i < height; i++)
    {
        piece_description[i] = new char[width];
        for (int j = 0; j < width; j++)
        {
            piece_description[i][j] = empty_symbol;
        }
    }
}

char GridView::get_description(int x, int y) const
{
    if ((x < 0) || (y < 0) || (x >= get_width()) || (y >= get_height()))
    {
        return border_symbol;
    }
    return piece_description[y][x];
}
void GridView::set_description(int x, int y, char descr)
{
    if ((x < 0) || (y < 0) || (x >= get_width()) || (y >= get_height()))
    {
        return;
    }
    piece_description[y][x] = descr;
}

void GridView::mirror_x()
{
    if (piece_description == nullptr)
    {
        return;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // Flipping values
            char temp = piece_description[i][j];
            piece_description[i][j] = piece_description[i][width - 1 - j];
            piece_description[i][width - 1 - j] = temp;
        }
    }
}
void GridView::mirror_y()
{
    if (piece_description == nullptr)
    {
        return;
    }
    for (int i = 0; i < height / 2; i++)
    {
        // Flipping pointers
        char *temp = piece_description[i];
        piece_description[i] = piece_description[height - 1 - i];
        piece_description[height - 1 - i] = temp;
    }
}

void GridView::mirror_diagonal()
{
    if (piece_description == nullptr)
    {
        return;
    }

    // This requires a new piece description

    char **old_piece_description = piece_description;
    piece_description = nullptr;

    int new_width = height;
    int new_heigth = width;

    initialize(new_width, new_heigth);

    for (int i = 0; i < new_width; i++)
    {
        for (int j = 0; j < new_heigth; j++)
        {
            set_description(i, j, old_piece_description[i][j]);
        }
    }

    // Freeing old description with old height (= current width)
    free_piece_description(old_piece_description, width);
}

void GridView::replace_symbol(const char new_symbol)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (get_description(i, j) != empty_symbol)
            {
                set_description(i, j, new_symbol);
            }
        }
    }
}

bool GridView::equals(const GridView &other)
{
    // Check if dimensions match
    if (width != other.width)
    {
        return false;
    }
    if (height != other.height)
    {
        return false;
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (get_description(i, j) != other.get_description(i, j))
            {
                return false;
            }
        }
    }

    return true;
}

std::string GridView::to_string()
{
    if (piece_description == nullptr)
    {
        // Return empty string if piece is not initialized
        return std::string();
    }
    std::string out;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            out.append(&(piece_description[i][j]), 1);
            out.append(" ");
        }
        out.append("\n");
    }
    return out;
}

void GridView::copy_piece_description(const GridView &other)
{
    // Check if piece description copy cannot be done
    if ((other.width != width) || (other.height != height) || (other.piece_description == nullptr) || (piece_description == nullptr))
    {
        return;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Copying values
            piece_description[i][j] = other.piece_description[i][j];
        }
    }
}

void GridView::free_piece_description()
{
    free_piece_description(piece_description, height);
}
void GridView::free_piece_description(char **piece_description, int height)
{
    if (piece_description != nullptr)
    {
        for (int i = 0; i < height; i++)
        {
            delete[] piece_description[i];
        }
        delete[] piece_description;
    }
}