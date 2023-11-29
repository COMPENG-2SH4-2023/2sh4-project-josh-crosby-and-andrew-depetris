#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;
GameMechs *myGM;
Player* myPlayer;
Food* myFood;
#define DELAY_CONST 100000
char **gameboard;
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs();
    myPlayer = new Player(myGM);
    myFood = new Food();
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    int x = myGM->getBoardSizeX();
    int y = myGM->getBoardSizeY();
    myFood->generateFood(playerBody,x,y);
    gameboard = new char*[y];
    for(int i =0;i<y;i++)
    {
        gameboard[i] = new char[x];
    }

}

void GetInput(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();

}

void RunLogic(void)
{
    int x = myGM->getBoardSizeX();
    int y = myGM->getBoardSizeY();
    objPos tempBody;
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    bool playerElement;
    objPos temp;
    playerBody->getHeadElement(temp);
    objPos foody;
    myFood->getFoodPos(foody);
    int size = playerBody->getSize();
    for(int i = 1; i< size;i++)
    {
        objPos colPos;
        playerBody->getElement(colPos,i);
        if(temp.x == colPos.x && temp.y == colPos.y)
        {
            myGM->setExitTrue();
        }
        }
    if( temp.x == foody.x && temp.y == foody.y)
    {
        playerBody->insertTail(temp);
        myFood->generateFood(playerBody,x,y);
        myFood->getFoodPos(foody);
        myGM->incrementScore();

    }
   
    for(int i = 0;i<y;i++)
    {
        for(int j = 0;j<x;j++)
        {
            playerElement = false;
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody,k);
                if(tempBody.x == j && tempBody.y == i)
                {   gameboard[i][j] = tempBody.symbol;
                    playerElement = true;
                    break;
                }
            }
            if(playerElement == true)
            {
                continue;
            }
                
            
            if(i == 0 || j == (x-1) || j == 0 || i == (y-1))
            {
                gameboard[i][j] = 35;

            }
            else if(foody.y == i && foody.x == j)
            {
                gameboard[i][j] = foody.symbol;
            }else
            {
                gameboard[i][j] = 32;
            }
        }
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    for(int i =0;i < myGM->getBoardSizeY();i++)
    {
        for(int j=0;j<myGM->getBoardSizeX();j++)
        {
            MacUILib_printf("%c",gameboard[i][j]);
        }
        MacUILib_printf("\n");//change line
    }
    MacUILib_printf("Score: %d\n",myGM->getScore());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay

}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    MacUILib_uninit();
}
