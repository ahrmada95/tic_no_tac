/*
Ahnaf Ahmad
September 2020
Tic-Tac-Toe game developed with recursive win-check for scaleability past 3x3 grids
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Board{
    char myBoard[3][3];
};

void empty(Board& game_board){
    game_board.myBoard[0][0] = '1'; 
    game_board.myBoard[0][1] = '2'; 
    game_board.myBoard[0][2] = '3';

    game_board.myBoard[1][0] = '4'; 
    game_board.myBoard[1][1] = '5'; 
    game_board.myBoard[1][2] = '6';

    game_board.myBoard[2][0] = '7'; 
    game_board.myBoard[2][1] = '8'; 
    game_board.myBoard[2][2] = '9';
}

void draw(Board game_board){
    cout<<"       |     |     "<<endl;

    cout<<"    "<<
            game_board.myBoard[0][0]
        <<"  |  "<<
            game_board.myBoard[0][1]
        <<"  |  "<<
            game_board.myBoard[0][2]<<endl;

    cout<<"       |     |     "<<endl;

    cout<<"  -----------------"<<endl;

    cout<<"       |     |     "<<endl;

    cout<<"    "<<
            game_board.myBoard[1][0]
        <<"  |  "<<
            game_board.myBoard[1][1]
        <<"  |  "<<
            game_board.myBoard[1][2]<<endl;

    cout<<"       |     |     "<<endl;

    cout<<"  -----------------"<<endl;

    cout<<"       |     |     "<<endl;
    cout<<"    "<<
            game_board.myBoard[2][0]
        <<"  |  "<<
            game_board.myBoard[2][1]
        <<"  |  "<<
            game_board.myBoard[2][2]<<endl;

    cout<<"       |     |     "<<endl; 
};

bool player_x(Board& game_board, unsigned int row, unsigned int col){
    if(row > 2 or col > 2){
        return false;
    }

    else if(game_board.myBoard[row][col] == 'x' or game_board.myBoard[row][col] =='o'){
        return false;
    }
    
    else{
        game_board.myBoard[row][col] = 'x'; 
        return true;
    }
};


bool player_o(Board& game_board, unsigned int row, unsigned int col){
    if(row > 2 or col > 2){
        return false;
    }

    else if(game_board.myBoard[row][col] == 'o' or game_board.myBoard[row][col] =='x'){
        return false;
    }
    
    else{
        game_board.myBoard[row][col] = 'o'; 
        return true;
    }
};

bool checkRow(Board game_board, unsigned int row, unsigned int col, unsigned int total_row, unsigned int total_col){

    //Exit Condition #1
    //if current spot does not have the same mark as the last spot in row, return false
    if(game_board.myBoard[row][col] != game_board.myBoard[row][total_col-1]){
        return false;
    }

    //Exit Condition #2
    //if current spot is the last spot in the row, return true
    if(col == total_col-1){
        return true;
    }

    //recursively check next spot in row
    else{
        return checkRow(game_board,row,(col+1),total_row, total_col);
    }
}

bool checkCol(Board game_board, unsigned int row, unsigned int col, unsigned total_row, unsigned int total_col){

    //Exit Condition #1
    //if current spot does not have the same mark as the last spot in the col, return false
    if(game_board.myBoard[row][col] != game_board.myBoard[total_row-1][col]){
        return false;
    }

    //Exit Condition #2
    //if current spot is the last spot in the col, return true
    if(row == total_row-1){
        return true; 
    }

    //recursively check next spot in col
    else{
        return checkCol(game_board,(row+1),col,total_row,total_col);
    }
}

//top left to bottom right
bool checkDiag1(Board game_board, unsigned int row, unsigned int col, unsigned total_row, unsigned int total_col){

    //Exit Condition #1
    //if current spot does not have the same mark as the bottom right most spot return false
    if(game_board.myBoard[row][col] != game_board.myBoard[total_row-1][total_col-1]){
        return false;
    }

    //Exit Condition #2
    //if current spot is the bottom right most spot, return true
    if(row == total_row-1 && col == total_col-1){
        return true;
    }

    //recursively check next pot in diagnol
    else{
        return checkDiag1(game_board,(row+1),(col+1),total_row,total_col);
    }
}

bool checkDiag1(Board game_board, unsigned total_row, unsigned int total_col){
    return checkDiag1(game_board,0,0,total_col,total_row);
}

//bottom left to top right
bool checkDiag2(Board game_board,unsigned int row, unsigned int col, unsigned total_row,unsigned int total_col){

    //Exit Condition #1
    //if current spot does not have the same mark as the top right most spot return false
    if(game_board.myBoard[row][col] != game_board.myBoard[0][total_col-1]){
        return false;
    }

    //Exit Condition #2
    //if current spot is the top right most spot, returntrue
    if(row == 0 && col == total_col-1){
        return true;
    }

    //recursively check next pot in diagnol
    else{
        return checkDiag2(game_board,(row-1),(col+1),total_row,total_col);
    }
}

bool checkDiag2(Board game_board, unsigned total_row, unsigned total_col){
    return checkDiag2(game_board,(total_row-1),0,total_col,total_row);
}


bool checkWin(Board game_board, unsigned total_row, unsigned total_col){
    for(int r = 0; r <= total_row; r++){
        if(checkRow(game_board,r,0,total_row,total_col)){
            return true;
        }
    }

    for(int c = 0; c <= total_col; c++){
        if(checkCol(game_board,0,c,total_row,total_col)){
            return true;
        }
    }

    if(checkDiag1(game_board,total_row,total_col)){
        return true;
    }

    else if(checkDiag2(game_board,total_row,total_col)){
        return true;
    }

    else{
        return false;
    }
}

bool spot_convert(unsigned int spot, unsigned int& row, unsigned int& col){
    if(spot == 1){
        row = 0;
        col = 0;

        return true;
    }

    else if(spot == 2){
        row = 0;
        col = 1;

        return true;
    }

    else if(spot == 3){
        row = 0;
        col = 2; 

        return true;
    }

    else if(spot == 4){
        row = 1;
        col = 0;

        return true;
    }

    else if(spot == 5){
        row = 1;
        col = 1;

        return true;
    }

    else if(spot == 6){
        row = 1;
        col = 2;

        return true;
    }

    else if(spot == 7){
        row = 2;
        col = 0;

        return true;
    }

    else if(spot == 8){
        row = 2; 
        col = 1;

        return true;
    }

    else if(spot == 9){
        row = 2;
        col = 2;
         return true;
    }

    else{
        return false;
    }
}

int main(){

    Board curr_game;

    empty(curr_game);

    draw(curr_game);

    for(int turn = 0; turn <= 9; turn++){

        unsigned int spot, row, col;
        //if turn is even, player x makes a move
        if(turn%2 == 0){
            cout<<"Player X's turn: choose which spot you wish to mark."<<endl;
            cin>>spot;

            if(!spot_convert(spot,row,col) or !player_x(curr_game,row,col)){
                cout<<"This is not a valid move."<<endl;
                turn--;
            }
        }

        //if turn is odd, player o makes a move
        else{
            cout<<"Player O's turn: choose which spot you wish to mark."<<endl;
            cin>>spot;

            if(!spot_convert(spot,row,col) or !player_o(curr_game,row,col)){
                cout<<"This is not a valid move."<<endl;
                turn--;
            }
        }

        draw(curr_game);

        if(checkWin(curr_game,3,3)){
            if(turn%2 == 0){
                cout<<"Player X wins"<<endl;
                return 0;
            }

            else if(turn%2 == 1){
                cout<<"Player O wins"<<endl;
                return 0;
            }
        }
    }

return 0;
}

