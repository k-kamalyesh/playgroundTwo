#include <malloc.h>

#ifndef __C_POSITION_H__
#define __C_POSITION_H__

class CPosition
{
private:
    int x;
    int y;
    int z;

public:
    CPosition()
    {
        x=0;
        y=0;
        z=0;
    }
    int goFront()
    {
        return x++;
    }
    int goBack()
    {
        return x--;
    }
    int goRight()
    {
        return y++;
    }
    int goLeft()
    {
        return y--;
    }
    int goUp()
    {
        return z++;
    }
    int goDown()
    {
        return z--;
    }
    int *getPosition()
    {
        int *pos = (int *)malloc(sizeof(int) * 3);
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        return pos;
    }
};
#endif