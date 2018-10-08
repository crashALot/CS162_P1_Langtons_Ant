/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: The antMenu file is used as the direct interface with
*               users. Input data is completed through here.
*********************************************************************/
#include <iostream>
#include <string>
#include "antMenu.hpp"

/********************************************************************* 
** Description: antMenu::antMenu()
*               Default constructor. Automatically calls the main menu.
*********************************************************************/
antMenu::antMenu()
{
    mainMenu();
}

/********************************************************************* 
** Description: void antMenu::mainMenu()
*               Allows the user to either play a game or quit the game.
*********************************************************************/
void antMenu::mainMenu()
{
        int userChoice;
        std::cout << "****************** Welcome to Langton's Ant! ******************" << std::endl;
        std::cout << "Would you like to: " << std::endl;
        std::cout << "Play a game (1) or Quit the game (2)? " << std::endl;
        userChoice=mainMenuValidate();
        if (userChoice==1)
        {
            gameInfo();
        }
        else
        {
            quitMenu();
        }
}

/********************************************************************* 
** Description: int antMenu::gameInfo()
*               Prompts the user to answer some questions about how 
*               the game will be played. After retrieving the required
*               information this function puts the game in motion by
*               calling the required functions to start.
*********************************************************************/
int antMenu::gameInfo()
{
        int boardRows, boardCols, startRow, startCol, userSteps;
        std::cout << "Let's get started with some information about the game:" << std::endl;
        std::cout << "How many rows will the board have?" << std::endl;
        boardRows=boardInfoValidate();
        newBoard.setRows(boardRows);
        std::cout << "How many columns will the board have?" << std::endl;
        boardCols=boardInfoValidate();
        newBoard.setCols(boardCols);
        std::cout << "How many steps will the ant take?" << std::endl;
        userSteps=boardInfoValidate();
        newAnt.setSteps(userSteps-1);
        std::cout << "What column will the ant start its journey?" << std::endl;
        startCol=antColInfoValidate(&newBoard);
        newAnt.setCol(startCol-1);
        std::cout << "What row will the ant start its journey?" << std::endl;
        startRow=antRowInfoValidate(&newBoard);
        newAnt.setRow(startRow-1);
        
        newBoard.createBoard();
        newBoard.updateBoard(&newAnt);
        newBoard.moveAhead(&newAnt);
        endMenu();
        return 0;
}

/********************************************************************* 
** Description: void antMenu::endMenu()
*               Appears at the end of a game. Prompts the user to 
*               either play another game or quit.
*********************************************************************/
void antMenu::endMenu()
{
        int userInput;
        std::cout << std::endl << "Congratulations you've reached the end of Langton's Ant!" << std::endl;
        std::cout << "Would you like to play again (1) or quit the program (2)?" << std::endl;
        userInput=mainMenuValidate();
        if (userInput==1)
            gameInfo();
        else
            quitMenu();
        
}

/********************************************************************* 
** Description: int antMenu::quitMenu()
*               When called thanks the user for playing prior to exit.    
*********************************************************************/
int antMenu::quitMenu()
{
    std::cout << "Thank you for playing! See you again soon!" << std::endl;
    return 0;
}

/********************************************************************* 
** Description: antMenu::~antMenu()
*               antMenu destructor
*********************************************************************/
antMenu::~antMenu()
{
}