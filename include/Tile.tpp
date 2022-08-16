#ifndef TILE_TPP
#define TILE_TPP

#include <utility>
#include <cmath>
#include <map>

template<class T>
using positionsList = std::map<T, double>;

template<class T>
Tile<T>::Tile(positionsList& pos) : positions{pos} {
    calculate_entropy();
}

template<class T>
void Tile<T>::calculate_entropy() {
    double sumWeight{};
    double sumLogWeight{};

    for (auto p : positions) {
        sumWeight += p.second;
        sumLogWeight += p.second * log(p.second);
    }

    entropy = log(sumWeight) - (sumLogWeight / sumWeight);
}

#endif
