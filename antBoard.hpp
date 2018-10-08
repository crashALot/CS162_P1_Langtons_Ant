/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: Associated header file for antBoard.cpp. Includes 
*               ant class for use with updating game board.
*********************************************************************/
#ifndef ANTBOARD_HPP
#define ANTBOARD_HPP
#include "ant.hpp"

class antBoard
{
private:
    
    int rows, cols;
    char** boardArray;
    
public:
    
    antBoard();
    void createBoard();
    void updateBoard(ant*);
    void moveAhead(ant*);
    void setRows(int);
    void setCols(int);
    int getRows();
    int getCols();
    void printBoard(ant*);
    ~antBoard();
    
};

#endif