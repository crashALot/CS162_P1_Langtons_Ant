/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: Associated header file for ant class. All variables
*               are private members only
*********************************************************************/
#ifndef ANT_HPP // Include guards
#define ANT_HPP

class ant
{
private:
    
    int rowPosit, colPosit, steps;
    char direction;
    
public:
    
    ant();
    void setSteps(int);
    void setRow(int);
    void setCol(int);
    void setDirection(char);
    int getRow();
    int getCol();
    int getSteps();
    char getDirection();
    ~ant();
    
};

#endif