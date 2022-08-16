#ifndef TILE_H
#define TILE_H

#include <map>
#include <utility>
#include <cmath>
#include <iostream>

template<class T>
class Tile {
    using positionsList = std::map<T, double>;
    public:
        positionsList positions;
        double entropy;

        Tile() : positions{} {}

        Tile(positionsList& pos) : positions{pos} {
            calculate_entropy();
        }

        void calculate_entropy() {
            double sumWeight{};
            double sumLogWeight{};

            for (auto p : positions) {
                sumWeight += p.second;
                sumLogWeight += p.second * log(p.second);
            }

            entropy = log(sumWeight) - (sumLogWeight / sumWeight);
        }

        void remove_position(T&& pos) {
            positions.erase(pos);
            calculate_entropy();
        }

        void set_positions(positionsList& pos) {
            positions = pos;
            calculate_entropy();
        }

        void print_entropy() {
            std::cout << "Entropy: " << entropy;
        }
};

#endif
