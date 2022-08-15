#include <stdio.h>

#include "colors.h"

void print_character(char c);
void generate_rules(char src[3][3]);

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

    // source tileset
    char src[3][3]  {{'S', 'S', 'S'},
                     {'C', 'C', 'S'},
                     {'L', 'L', 'C'}};

    // output tileset
    char out[10][10]  {};

    generate_rules(src);
    
    return 0;
}

void generate_rules(char src[3][3]) {
    print_character(src[0][0]);
}

void print_character(char c) {
    switch (c) {
        case 'S':
            printf(CYN " %c" NC, c);
            break;
        case 'C':
            printf(YLW " %c" NC, c);
            break;
        case 'L':
            printf(GRN " %c" NC, c);
            break;
    }
}
