#include <ctime>
#include <stdio.h>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "colors.h"
#include "utility.h"
#include "Rules.hpp"
#include "Tile.hpp"
#include "Board.hpp"
/* const int SRC_X = 3; */
/* const int SRC_Y = 3; */

int main() {
    // Create rule list
    // eg superposition restrictions
    // superposition = what tiles can go where
    // basically every tile in image starts out as being "all" possible options

    // collapse function for every tile -> randomly assign out of possible options
    // this affects remaining tile placement -> leads to other constraints

    // ALG
    // teach rules (use input image)
    // initalize wavefuction
    // collapse on element
    // propagate consequences of element to rest of function
    // repeat until complete or contradiction reached

    // record frequency of each tile in source image
    // record adjecency rules from source image

    // pick lowest entropy spots first -- low entropy means less choices

    srand(time(0));

    // source tileset
    /* char src[SRC_X][SRC_Y]  {{'S', 'S', 'S'}, */
    /*                          {'C', 'C', 'S'}, */
    /*                          {'L', 'L', 'C'}}; */
    char src[SRC_X][SRC_Y]  {{'L', 'C', 'L'},
                             {'C', 'S', 'C'},
                             {'L', 'C', 'L'}};
    /* char src[SRC_X][SRC_Y]  {{'S', 'C', 'S'}, */
    /*                          {'C', 'L', 'C'}, */
    /*                          {'L', 'L', 'C'}}; */

    /* Rules r(src); */
    /* r.print_rules(); */
    /* r.print_weights(); */

    std::cout << "SOURCE:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "    ";
        for (int j = 0; j < 3; j++) {
            print_character(src[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    Board<char> board(src);
    board.rules.print_rules();
    board.rules.print_weights();
    board.solve_board();
    board.print_board();


    // output tileset
    char out[10][10] {};


    /* generate_rules(src); */
    
    return 0;
}
