#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
#include "objPosArrayList.h"
class Food
{
    public:
        Food();
        ~Food();
        void generateFood(objPosArrayList* blockoff, int xRange,int yRange);
        void getFoodPos(objPos &returnPos);
    private:
        objPos foodPos;

};
#endif