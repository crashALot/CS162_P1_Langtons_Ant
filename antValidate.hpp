/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/08/2018
** Description: Associated header file for antValidate.cpp file.
*               Includes antBoard.hpp to update member variables.
*********************************************************************/
#ifndef ANTVALIDATE_HPP
#define ANTVALIDATE_HPP
#include "antBoard.hpp"
    
int mainMenuValidate();
int boardInfoValidate();
int antRowInfoValidate(antBoard*);
int antColInfoValidate(antBoard*);

#endif