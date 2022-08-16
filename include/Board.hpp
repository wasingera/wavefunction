#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "Tile.hpp"

const int OUTPUT_WIDTH  {10};
const int OUTPUT_HEIGHT {10};

template<class T>
class Board {
    using positionsList = std::map<T, double>;
    using boardArray = std::array<std::array<Tile<T>, OUTPUT_HEIGHT>, OUTPUT_WIDTH>;

    public:
        boardArray board;
        positionsList positions;
        
        Board(positionsList& pos) : positions{pos} {
            for (auto& row : board) {
                for (auto& tile : row) {
                    tile.set_positions(positions);
                }
            }
        }

        void solve_board() {
            int total {OUTPUT_WIDTH * OUTPUT_HEIGHT};
            int solved {0};

            // while not fully solved find lowest entropy and pick random tile

        }

};

#endif
