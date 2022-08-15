#include "utility.h"
#include "colors.h"

void print_tuple(rule r) {
    std::cout << std::get<0>(r) << " " << std::get<1>(r) << " " << std::get<2>(r);
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
