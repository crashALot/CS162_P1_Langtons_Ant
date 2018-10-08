/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: The ant class is created to store and edit critical
*               information regarding the ant object used by the 
*               program. This includes direction, position, and number
*               of steps remaining. 
*********************************************************************/
#include "ant.hpp"

/********************************************************************* 
** Description: ant::ant()
*               Default constructor. Creates an ant at a 0,0 position
*               on the board, sets steps to 1 and direction to North.
*********************************************************************/
ant::ant()
{
    rowPosit=0;
    colPosit=0;
    steps=1;
    direction='N';
}

/********************************************************************* 
** Description: void ant::setDirection(char blockColor)
*               The ant class determines how the ant will change
*               direction depending on the block color it currently
*               resides on. A blank space will change the direction
*               to the right while a filled space means a turn to the
*               left. The blockColor argument makes this happen
*********************************************************************/
void ant::setDirection(char blockColor)
{
    if (blockColor==' ')
    {
        switch (direction)
        {
            case 'N':
                direction='E';
                break;
            case 'E':
                direction='S';
                break;
            case 'S':
                direction='W';
                break;
            case 'W':
                direction='N';
                break;
        }
    }
    else if (blockColor=='#')
    {
        switch (direction)
        {
            case 'N':
                direction='W';
                break;
            case 'E':
                direction='N';
                break;
            case 'S':
                direction='E';
                break;
            case 'W':
                direction='S';
                break;
        }
    }
}

/********************************************************************* 
** Description: Set and get functions
*               These functions allow outside programs to edit or call
*               specific information regarding ant objects
*********************************************************************/
void ant::setSteps(int userSteps)
{
    steps=userSteps;
}

void ant::setRow(int rowIn)
{
    rowPosit=rowIn;
}

void ant::setCol(int colIn)
{
    colPosit=colIn;
}

int ant::getRow()
{
    return rowPosit;
}

int ant::getCol()
{
    return colPosit;
}

int ant::getSteps()
{
    return steps;
}

char ant::getDirection()
{
    return direction;
}

/********************************************************************* 
** Description: ant::~ant()
*               ant class destructor
*********************************************************************/
ant::~ant()
{
}