#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "Tile.hpp"

const int OUTPUT_WIDTH  {10};
const int OUTPUT_HEIGHT {10};

template<class T>
class Board {
    using positionsList = std::map<T, double>;
    using boardArray = std::array<std::array<T, OUTPUT_HEIGHT>, OUTPUT_WIDTH>;

    boardArray board;
    positionsList positions;
    
    Board(positionsList& pos) : positions{pos} {
        for (auto& row : board) {
            for (auto& col : row) {

            }
        }
    }

};

#endif
