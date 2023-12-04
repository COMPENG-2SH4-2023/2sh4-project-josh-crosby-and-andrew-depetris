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
void Food::generateFood(objPosArrayList* blockoff,int xRange,int yRange)
{
    srand(time(NULL));
    int size = blockoff->getSize();
    bool loop = true;
    while(loop)
    {
                
        int xcord = (rand()% (xRange-2))+1;
        int ycord = (rand()% (yRange-2))+1;
        int count = 0;
        for(int i = 0;i<size;i++)
        {
            objPos temp;
            blockoff->getElement(temp,i);
            if(xcord != temp.x && ycord != temp.y)
            {
                count++;
                continue;
            }else{
                break;
            }

        }
        if(count == size){
            foodPos.x = xcord;
            foodPos.y = ycord;
            loop = false;
        }
    }

}
void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}