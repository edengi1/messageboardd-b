#include "Direction.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Board.hpp"

using namespace ariel;
using namespace std;

void Board::post(unsigned int row, unsigned int col, Direction d, const string &message){

    unsigned int len = message.size();

    if(!init_flag && len != 0){

        min_row = row;
        max_row = row;
        min_col = col;
        max_col = col;

        init_flag = true;
    }

    else{

        if (min_row > row){

            min_row = row;
        }

        if(min_col > col){

            min_col = col;
        }
    }

    if(d == Direction::Vertical){

        if (max_row < row + len){

            max_row = row + len - 1;
        }

        for (unsigned long i = 0; i < len; i++){

            board[row++][col] = message.at(i);
        }
    }
    else{

        if (max_col < col + len){

            max_col = col + len - 1;
        }
        for (unsigned long i = 0; i < len; i++){

            board[row][col++] = message.at(i);
        }
    }
}

string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int len){

    string ans;

    for (unsigned int i = 0; i < len; i++){

        if(board[row][col] != 0){

            ans += board[row][col];
        }

        else{

            ans += '_';
        }

        if(d == Direction::Horizontal) {

            col++;
        }

        else{

            row++;
        }
    }
    return ans; 
}

void Board::show()
{
    for (unsigned int i = min_row; i <= max_row; i++){

        cout << i << ":\t";

        for (unsigned int j = min_col; j <= max_col; j++){

            if(board[i][j] != 0){
                
                cout << board[i][j];
            }
            else{
                cout << '_';
            }
        }
        cout << endl;
    }
}