/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: This file is used to validate all the types of inputs
*               required when using the menus. 
*********************************************************************/
#include "antValidate.hpp"
#include <iostream>
#include <string>
#include <cmath> // Used for pow function

/********************************************************************* 
** Description: int mainMenuValidate()
*               Ensures only the integers 1 or 2 can be input into 
*               any needed menu. Currently used with the main menu
*               and end menu.
*********************************************************************/
int mainMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (Play a game) or 2 (Quit the game): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int boardInfoValidate()
*               Ensures only positive integers>0 can be input into 
*               any required menu. Is used to validate input for antBoard
*               inputs and ant class inputs.
*********************************************************************/
int boardInfoValidate()
{
    int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)
                    go=0;
                if (!runTotal)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    return runTotal;
}

/********************************************************************* 
** Description: int antColInfoValidate(antBoard* newBoard)
*               Ensures only positive integers>0 can be input into 
*               the required menus. Is used to validate input for
*               initial ant column locations 
*********************************************************************/
int antColInfoValidate(antBoard* newBoard)
{
    int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)
                    go=0;
                if ((runTotal)>newBoard->getCols() || (runTotal)<0)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) between 1 and " << newBoard->getCols() << ":" << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods) between 1 and " << newBoard->getCols() << ":" << std::endl;
                runTotal=0;
                break;
            }
        }
    } while (go);
    return runTotal;
}

/********************************************************************* 
** Description: int antRowInfoValidate(antBoard* newBoard)
*               Ensures only positive integers can be input into 
*               the required menus. Is used to validate input for
*               initial ant row location
*********************************************************************/
int antRowInfoValidate(antBoard* newBoard)
{
    int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)// && (runTotal-1)<newBoard->getRows() && (runTotal-1)>0)
                    go=0;
                if ((runTotal)>newBoard->getRows() || (runTotal)<0)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) between 1 and " << newBoard->getRows() << ":" << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods): " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    return runTotal;
}