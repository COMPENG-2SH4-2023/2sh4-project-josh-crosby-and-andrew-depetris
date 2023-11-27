#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;
GameMechs *myGM;
Player* myPlayer;
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
    int x = myGM->getBoardSizeX();
    int y = myGM->getBoardSizeY();
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
    objPos temp;
    myPlayer->getPlayerPos(temp);
    
    for(int i = 0;i<y;i++)
    {
        for(int j = 0;j<x;j++)
        {
            
            if(i == 0 || j == (x-1) || j == 0 || i == (y-1))
            {
                gameboard[i][j] = 35;

            }else if(temp.x == i && temp.y == j)
            {
                gameboard[i][j] = temp.symbol;   
            }else{
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
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay

}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    MacUILib_uninit();
    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {   
        delete(gameboard[i]);
    }  
    delete gameboard;
    delete myGM;
    delete myPlayer;

    
}
