#ifndef RULES_H
#define RULES_H

#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using rule = std::tuple<char, char, std::string>;
/* using rulesMap = std::map<char, std::vector<std::tuple<char, char, std::string>>>; */
using weightsMap = std::map<char, double>;
using rulesMap = std::map<char, std::map<std::string, std::set<char>>>;

const int SRC_X = 3;
const int SRC_Y = 3;

class Rules {
    public:
        rulesMap rules;
        weightsMap weights;

        Rules(char src[SRC_Y][SRC_X]);

        void print_rules();
        void print_weights();
    private:
        rulesMap generate_rules(char src[SRC_Y][SRC_X]);
        weightsMap generate_weights(char src[SRC_Y][SRC_X]);
};

#endif
