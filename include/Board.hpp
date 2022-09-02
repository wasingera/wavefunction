#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <cstdlib>
#include <tuple>
#include <vector>
#include <iostream>
#include <limits>

#include "Tile.hpp"
#include "utility.h"
#include "Rules.hpp"

const int OUTPUT_WIDTH  {10};
const int OUTPUT_HEIGHT {10};

template<class T>
class Board {
    using positionsList = std::map<T, double>;
    using boardArray = std::array<std::array<Tile<T>, OUTPUT_HEIGHT>, OUTPUT_WIDTH>;

    public:

        boardArray board;
        positionsList positions;
        Rules rules;

        Board(char src[SRC_Y][SRC_X]) : rules{src} {
            positions = rules.weights;
            for (auto& row : board) {
                for (auto& tile : row) {
                    // load in the default positions to each tile
                    tile.set_positions(positions);
                }
            }
        }
        
        bool solve_board() {
            int total {OUTPUT_WIDTH * OUTPUT_HEIGHT};
            int solved {0};

            // while not fully solved find lowest entropy and pick random tile

            while (solved < total) {
                // find lowest tile
                Tile<T>& t = find_lowest_tile();

                // pick random state
                /* int pos = rand() % t.positions.size(); */
                std::vector<T> keys;
                std::vector<double> weights;
                for (auto e : t.positions) {
                    keys.push_back(e.first);
                    weights.push_back(e.second);
                }

                if (!keys.size()) return false;

                t.state = keys[weighted_random_index(weights)];
                /* std::cout << "ASSIGNED: " << t.state << " for " << solved << std::endl; */
                // set to max entropy so tile isn't chosen again
                t.entropy = std::numeric_limits<double>::max();

                // update positions lists based on rules
                /* std::cout << "POSITIO: " << vect_to_string(keys) << std::endl; */
                update_tile_positions();

                // increment solved
                solved++;
            }
            return true;
        }

        void update_tile_positions() {
            rulesMap r = rules.rules;

            for (int i = 0; i < OUTPUT_HEIGHT; i++) {
                for (int j = 0; j < OUTPUT_WIDTH; j++) {

                    auto& curr = board[i][j];

                    // if we are next to determined state and we aren't determined, we need to check the rules
                    // check to the left -- look for CURR COMPARE LEFT
                    if (j > 0 && board[i][j - 1].state && !curr.state) {
                        // check what states are allowed compared to left side
                        // so look at left tile, then what can be on its right?
                        auto& left = board[i][j - 1];
                        curr.update_positions(r[left.state]["RIGHT"]);
                    }

                    // check right
                    if (j < (OUTPUT_WIDTH - 1) && board[i][j + 1].state && !curr.state) {
                        auto& right = board[i][j + 1];
                        curr.update_positions(r[right.state]["LEFT"]);
                    }

                    // check up
                    if (i > 0 && board[i - 1][j].state && !curr.state) {
                        auto& up = board[i - 1][j];
                        curr.update_positions(r[up.state]["DOWN"]);
                    }

                    // check down
                    if (i < (OUTPUT_HEIGHT  - 1) && board[i + 1][j].state && !curr.state) {
                        auto& down = board[i + 1][j];
                        curr.update_positions(r[down.state]["UP"]);
                    }
                    /* std::cout << "ALLOWED: "; */
                    /* for (auto e : curr.positions) */
                    /*     std::cout << e.first << ' '; */
                    /* std::cout << std::endl; */
                    // don't want to reset a determined tile so put in if statement
                    if (!curr.state) curr.calculate_entropy();
                }
            }
        }

        Tile<T>& find_lowest_tile() {
            /* Tile<T> *low = &board[0][0]; */
            std::vector<Tile<T> *> low;

            for (auto& row : board) {
                for (auto& tile : row) {
                    // add some randomness to selection if there are tiles with same entropy
                    if (!low.size()) {
                        low.push_back(&tile);
                        continue;
                    }

                    if (tile.entropy < low[0]->entropy) {
                        low.erase(low.begin(), low.end());
                        low.push_back(&tile);
                    }
                    else if (tile.entropy == low[0]->entropy) {
                        low.push_back(&tile);
                    }
                }
            }

            int random_index = rand() % low.size();

            return *(low[random_index]);
        }

        void print_board() {
            std::cout << '\n';
            std::cout << "OUTPUT:\n";
            for (auto& row : board) {
                std::cout << "    ";
                for (auto& tile : row) {
                    /* std::cout << tile.entropy << ' '; */
                    print_character(tile.state);
                }
                std::cout << std::endl;
            }
        }

        void print_board_entropy() {
            std::cout << '\n';
            std::cout << "ENTROPY:\n";
            for (auto& row : board) {
                std::cout << "    ";
                for (auto& tile : row) {
                    std::cout << tile.entropy << ' ';
                }
                std::cout << std::endl;
            }
        }

        void reset_board() {
            positions = rules.weights;
            for (auto& row : board) {
                for (auto& tile : row) {
                    // load in the default positions to each tile
                    tile.set_positions(positions);
                    tile.state = '\0';
                }
            }
        }

};

#endif
