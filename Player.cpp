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
    switch (myDir)
    {
    case UP:
        if(playerPos.y == 1){
            playerPos.y = mainGameMechsRef->getBoardSizeY() -2;
        }else{
            playerPos.y--;
        }
        break;
    case DOWN:
        if(playerPos.y == mainGameMechsRef->getBoardSizeY() -2){
            playerPos.y = 1;
        }else{
            playerPos.y++;
        }
        break;
    case LEFT:
        if(playerPos.x == 1){
            playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
        }else{
            playerPos.x--;
        }
        break;
    case RIGHT:
        if(playerPos.x == mainGameMechsRef->getBoardSizeX()-2){
            playerPos.x = 1;
        }else{
            playerPos.x++;
        }
    default:
        break;
    }
}

