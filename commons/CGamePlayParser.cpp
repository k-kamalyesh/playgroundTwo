#include <iostream>
#include <string>
#include "CPosition.cpp"

using namespace std;

#ifndef __C_GAME_PLAY_PARSER_H__
#define __C_GAME_PLAY_PARSER_H__

class CGamePlayParser
{
private:
    CPosition position;
    bool verticle;
    bool attack;
    bool defense;

protected:
    bool selectPlay(char c)
    {
        if (verticle)
        {
            switch (c)
            {
            case 'W':
            case 'w':
                position.goUp();
                verticle = false;
                return true;
            case 'S':
            case 's':
                position.goDown();
                verticle = false;
                return true;
            default:
                verticle = false;
                return true;
            }
        }
        else
        {
            switch (c)
            {
            case '^':
                verticle = true;
                return true;
            case 'W':
            case 'w':
                position.goFront();
                return true;
            case 'S':
            case 's':
                position.goBack();
                return true;
            case 'A':
            case 'a':
                position.goLeft();
                return true;
            case 'D':
            case 'd':
                position.goRight();
                return true;
            default:
                return false;
            }
        }
    }

public:
    CGamePlayParser()
    {
        verticle = false;
    }
    bool process(std::string input)
    {
        int *pos;
        for (int i = 0; i < input.length(); i++)
        {
            selectPlay(input.at(i));
            pos = position.getPosition();
            std::cout << pos[0] << "," << pos[1] << "," << pos[2] << std::endl
                      << pos[3] << "," << pos[4] << std::endl;
        }
        return true;
    }
};
#endif