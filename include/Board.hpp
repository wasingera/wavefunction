#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <limits>

#include "Tile.hpp"
#include "utility.h"

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
                    // load in the default positions to each tile
                    tile.set_positions(positions);
                }
            }
        }

        void solve_board() {
            int total {OUTPUT_WIDTH * OUTPUT_HEIGHT};
            int solved {0};

            // while not fully solved find lowest entropy and pick random tile

            while (solved < total) {
                // find lowest tile
                Tile<T>& t = find_lowest_tile();

                // pick random state
                int pos = rand() % t.positions.size();
                std::vector<T> keys;
                for (auto e : t.positions) keys.push_back(e.first);
                t.state = keys[pos];
                t.entropy = std::numeric_limits<double>::max();

                // update positions lists based on rules

                // increment solved
                solved++;
            }

        }

        Tile<T>& find_lowest_tile() {
            Tile<T> *low = &board[0][0];

            for (auto& row : board) {
                for (auto& tile : row) {
                    // skip if tile has already been determined
                    // add some randomness to selection if there are tile with same entropy
                    int breaker {rand() % 100};

                    if (tile.entropy < low->entropy)
                        low = &tile;
                    else if (tile.entropy == low->entropy) {
                        if (breaker < 50) low = &tile;
                    }
                }
            }
            return *low;
        }

        void print_board() {
            std::cout << '\n';
            for (auto& row : board) {
                for (auto& tile : row) {
                    print_character(tile.state);
                }
                std::cout << std::endl;
            }
        }

};

#endif
