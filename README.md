## Puzzle solver

Hello brave explorer of the interwebs! On this page you find a small program that finds solutions to the fun colorful puzzles like [these](https://www.smartgames.eu/uk/one-player-games/iq-puzzler-pro) (only the traditional 2D version).

### Using the program

You can download the latest release for Windows (as an exe file) and use the program as is, no need to install anything. 

The program accepts the following command line arguments:

- `-c <count>` where `<count>` is an integer number. This will set the maximum number of solutions to be found to `<count>`. If `<count>` is negative, all solutions will be found.
- `-i <filename>` where `<filename>` is the path to a `.txt` file containing the starting position of the puzzle. The `.txt` file should containt 5 lines of 11 characters each (there can be whitespaces, they are discarded). An empty position is marked by the `#` character and all puzzle piece positions should have the correct capital letter to them. You can find 2 examples of valid `.txt` files. To find the correct character symbols for each puzzle piece, run `PuzzleSolver.exe -c 1`.

### Build it yourself!

The program should compile without dependencies using cmake (I've used both vscode with the C/C++ cmake plug-in and Visual Studio 2022). In principle the code should compile on platforms other than Windows except that the [`print_board` function](https://github.com/yannickdekoninck/puzzle_solver/blob/5a7d1d31f18caa6ed5c7b8b4e53cc9bf770a7fd1/PuzzleSolver/Utilities.cpp#L24) uses a Windows specific API call to set the color of the different pieces. 