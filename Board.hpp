#pragma once
#include <string>
#include <map>
#include "Direction.hpp"

namespace ariel{

    class Board{

    private:

        std::map<unsigned int, std::map<unsigned int, char>> board;

        bool init_flag = false;

        unsigned int min_row = 0;
        unsigned int max_row = 0;
        unsigned int min_col = 0;
        unsigned int max_col = 0;
    
    public:

        void post(unsigned int row, unsigned int col, Direction d, const std::string &message);

        std::string read(unsigned int row, unsigned int col, Direction d, unsigned int len);

        void show();
    };
}