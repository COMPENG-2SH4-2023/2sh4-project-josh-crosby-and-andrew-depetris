#include "food.h"

Food::Food(objPos)
{
    foodPos.setObjPos(100,100,'@');
}
void food::generateFood(objPos BlockOff)
{

}
void food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}