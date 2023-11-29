#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    playerPosList = new objPosArrayList();

    objPos tempPos;
    tempPos.setObjPos((mainGameMechsRef->getBoardSizeX() / 2),(mainGameMechsRef->getBoardSizeY() / 2),'@');
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;

}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  

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
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    switch (myDir)
    {
    case UP:
        if(currentHead.y == 1){
            currentHead.y = mainGameMechsRef->getBoardSizeY() -2;
        }else{
            currentHead.y--;
        }
        break;
    case DOWN:
        if(currentHead.y == mainGameMechsRef->getBoardSizeY() -2){
            currentHead.y = 1;
        }else{
            currentHead.y++;
        }
        break;
    case LEFT:
        if(currentHead.x == 1){
            currentHead.x = mainGameMechsRef->getBoardSizeX()-2;
        }else{
            currentHead.x--;
        }
        break;
    case RIGHT:
        if(currentHead.x == mainGameMechsRef->getBoardSizeX()-2){
            currentHead.x = 1;
        }else{
            currentHead.x++;
        }
    default:
        break;
    }
    playerPosList->insertHead(currentHead);
    playerPosList->removeTail();
}

