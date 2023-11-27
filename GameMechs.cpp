#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = NULL;
    exitFlag = false;
    score = 0;
    loseFlag = 0;
    boardSizeX = 20;
    boardSizeY = 10;    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = NULL;
    exitFlag = false;
    score = 0;
    loseFlag = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;  
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {       
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = NULL;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

