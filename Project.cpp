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
    gameboard = new char*[x];
    for(int i =0;i<x;i++)
    {
        gameboard[i] = new char[y];
    }
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    int x = myGM->getBoardSizeX();
    int y = myGM->getBoardSizeY();
    for(int i = 0;i<=x;i++)
    {
        for(int j = 0;j<=y;j++)
        {
            if(i == 0 || i == x || j == 0 || j == y)
            {
                gameboard[i][j] = '#';
            }else{
                gameboard[i][j] = ' ';
            }
        }
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    MacUILib_printf("%c",gameboard[0][0]);
    // for(int i =0;i <= myGM->getBoardSizeX();i++)
    // {
    //     for(int j=0;j<=myGM->getBoardSizeY();j++)
    //     {
    //         MacUILib_printf("%c",gameboard[i][j]);
    //     }
    // }

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
