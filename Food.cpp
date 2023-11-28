#include "food.h"
#include <stdlib.h>
#include <time.h>
Food::Food()
{
    foodPos.setObjPos(0,0,'@');
}
Food::~Food()
{
    
}
void Food::generateFood(objPos BlockOff,int xRange,int yRange)
{
    bool loop = true;
    while(loop)
    {
        srand(time(NULL));
        int xcord = (rand()% (xRange-2))+1;
        int ycord = (rand()% (yRange-2))+1;
        if(xcord != BlockOff.x && ycord != BlockOff.y)
        {
            foodPos.y = ycord;
            foodPos.x = xcord;
            loop = false;
        }
    }
}
void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}