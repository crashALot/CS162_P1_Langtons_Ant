/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: Associated header file for antMenu.cpp. Includes 
*               header files for most every other code. 
*********************************************************************/
#ifndef ANTMENU_HPP
#define ANTMENU_HPP
#include "antBoard.hpp"
#include "ant.hpp"
#include "antValidate.hpp"

class antMenu
{
private:

    ant newAnt;
    antBoard newBoard;

public:

antMenu();
void mainMenu();
int gameInfo();
void endMenu();
int quitMenu(); 
~antMenu();

};
 
#endif