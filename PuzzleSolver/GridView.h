#include <string>

class GridView
{
public:
    // Constructors / destructor
    GridView();
    GridView(const GridView &other);
    GridView(int width, int height);
    ~GridView();

    GridView &operator=(const GridView &other);

    // Methods
    void initialize(int width, int height);
    void mirror_x();
    void mirror_y();
    void mirror_diagonal();
    std::string to_string();

    void replace_symbol(const char new_symbol);

    inline char get_description(int x, int y) const { return piece_description[y][x]; }
    inline void set_description(int x, int y, char descr) { piece_description[y][x] = descr; }
    inline int get_width() const { return width; }
    inline int get_height() const { return height; }

private:
    char **piece_description;
    // Variables
    int width;
    int height;

private:
    // Methods
    void free_piece_description();
    void free_piece_description(char **piece_description);
    void copy_piece_description(const GridView &other);
};