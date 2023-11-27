#include "objPos.h"
class Food
{
    public:
        Food(objPos);
        void generateFood(objPos BlockOff);
        void getFoodPos(objPos &returnPos);
    private:
        objPos foodPos;
};

