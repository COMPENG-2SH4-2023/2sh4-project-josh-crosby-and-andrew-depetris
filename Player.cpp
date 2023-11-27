#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(5,5,'@');

}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

    // need to fix input

    char input = mainGameMechsRef->getInput();

    switch(input)
        {                      
            case 'w':
                if(myDir != DOWN)
                    myDir = UP;
                break;
            case 's':
                if(myDir != UP)
                    myDir = DOWN;
                break;
            case 'a':
                if(myDir != RIGHT)
                    myDir = LEFT;
                break;
            case 'd':
                if(myDir != LEFT)
                    myDir = RIGHT;
                break;    
            default:
                break;
        }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

