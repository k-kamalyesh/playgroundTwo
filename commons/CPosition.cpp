#include <malloc.h>

#ifndef __C_POSITION_H__
#define __C_POSITION_H__

class CPosition
{
private:
    int x;
    int y;
    int z;
    double theta;
    double alpha;
    const double turnFactor = 0.001;

public:
    CPosition()
    {
        x = 0;
        y = 0;
        z = 0;
        theta = 0;
        alpha = 0;
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
    double turnLeft()
    {
        return theta += turnFactor;
    }
    double turnRight()
    {
        return theta -= turnFactor;
    }
    double turnUp()
    {
        return alpha += turnFactor;
    }
    double turnDown()
    {
        return alpha -= turnFactor;
    }
    int *getPosition()
    {
        int *pos = (int *)malloc(sizeof(int) * 5);
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        pos[3] = theta;
        pos[4] = alpha;
        return pos;
    }
};
#endif