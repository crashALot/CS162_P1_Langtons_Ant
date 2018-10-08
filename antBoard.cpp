/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: The ant board acts as the focal point for the 
*               Langton's ant program. The board is updated constantly
*               to reflect where the ant is located, where it will move
*               next, and output such details to consol.
*********************************************************************/
#include <iostream>
#include "antBoard.hpp"

/********************************************************************* 
** Description: antBoard::antBoard()
*               Default constructor sets private member variables to
*               0 and NULL.
*********************************************************************/
antBoard::antBoard()
{
    rows=0;
    cols=0;
    boardArray=NULL;
}

/********************************************************************* 
** Description: void antBoard::createBoard()
*               Creates blank game board that can be filled in at a
*               later time.
*********************************************************************/
void antBoard::createBoard()
{
    boardArray=new char* [getRows()];
    for (int i=0; i<getRows(); i++)
        boardArray[i]=new char[getCols()];
    
    for (int i=0; i<getRows(); i++)
    {
        for (int j=0; j<getCols(); j++)
        {
            boardArray[i][j]=' ';
        }
    }
}

/********************************************************************* 
** Description: void antBoard::updateBoard(ant* newAnt)
*               Uses ant object argument to locate where on the board
*               the ant is, retrieve the direction the ant is facing,
                and change the color of the corresponding square. 
*********************************************************************/
void antBoard::updateBoard(ant* newAnt)
{
    printBoard(newAnt);
    newAnt->setDirection(boardArray[newAnt->getRow()][newAnt->getCol()]);
    if (boardArray[newAnt->getRow()][newAnt->getCol()]=='#')
        boardArray[newAnt->getRow()][newAnt->getCol()]=' ';
    else
        boardArray[newAnt->getRow()][newAnt->getCol()]='#';
}

/********************************************************************* 
** Description: void antBoard::moveAhead(ant* newAnt)
*               Determines where the ant will move next based on current
*               ant object direction. Also considers edge cases by
*               moving ant to opposite side of board as needed. Decrements
*               number of steps remaining and deletes dynamic array
*               when needed.
*********************************************************************/
void antBoard::moveAhead(ant* newAnt)
{

    // Check for edges, check for color, update direction, call update function, call print function
    while ((newAnt->getSteps())>=0)
    {
        switch (newAnt->getDirection())
        {
            case 'N':
                if (((newAnt->getRow())-1)<0)
                {
                        newAnt->setRow(rows-1);
                }
                else
                    newAnt->setRow((newAnt->getRow())-1);
                break;
            case 'E':
                if (((newAnt->getCol())+1)>cols-1)
                {
                    newAnt->setCol(0);
                }
                else
                    newAnt->setCol((newAnt->getCol())+1);
                break;
            case 'S':
                if (((newAnt->getRow())+1)>rows-1)
                {
                    newAnt->setRow(0);
                }
                else
                    newAnt->setRow((newAnt->getRow())+1);
                break;
            case 'W':
                if (((newAnt->getCol())-1)<0)
                {
                    newAnt->setCol(cols-1);
                }
                else
                    newAnt->setCol((newAnt->getCol())-1);
                break;
        }
        newAnt->setSteps((newAnt->getSteps())-1);
        updateBoard(newAnt);
    }
    // Deallocate dynamic arrays 
    for (int i=0; i<rows; i++) // Start with the columns of dynamic arrays
        delete [] boardArray[i];
        
    delete [] boardArray; // Finally delete base dyanmic array
    boardArray=NULL; // Set pointer to NULL
}

/********************************************************************* 
** Description: get and set fucnctions
*               Allows functions to edit and retrieve information 
*               regarding the game board.
*********************************************************************/
void antBoard::setRows(int boardHeight)
{
    rows=boardHeight;
}

void antBoard::setCols(int boardWidth)
{
    cols=boardWidth;
}

int antBoard::getRows()
{
    return rows;
}

int antBoard::getCols()
{
    return cols;
}

/********************************************************************* 
** Description: void antBoard::printBoard(ant* newAnt)
*               Outputs game board to consol
*********************************************************************/
void antBoard::printBoard(ant* newAnt)
{
    std::cout << std::endl;
    std::cout << "The ant has " << newAnt->getSteps()+1<< " steps remaining." << std::endl;
    for (int i=0; i<getRows(); i++)
    {
        std::cout << '|' << " ";
        for (int j=0; j<getCols(); j++)
        {
            if (i==newAnt->getRow() && j==newAnt->getCol())
                std::cout << '*' << " ";                
            else            
                std::cout << boardArray[i][j] << ' ' ;
        }
    std::cout << '|' << " " << i+1 << std::endl;
    }
}

/********************************************************************* 
** Description: antBoard::~antBoard()
*               antBoard class destructor
*********************************************************************/
antBoard::~antBoard()
{
}