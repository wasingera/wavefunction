#ifndef TILE_H
#define TILE_H

#include <map>
#include <utility>
#include <cmath>
#include <iostream>
#include <set>
#include <iterator>

template<class T>
class Tile {
    using positionsList = std::map<T, double>;
    public:
        positionsList positions;
        T state;
        double entropy;

        Tile() : positions{}, state{} {}

        Tile(positionsList& pos) : positions{pos}, state{} {
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

        void update_positions(std::set<T>& allowed) {
            for (auto it = positions.begin(); it != positions.end();) {
                if (allowed.find(it->first) == allowed.end())
                    it = positions.erase(it);
                else
                    it++;
            }

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
