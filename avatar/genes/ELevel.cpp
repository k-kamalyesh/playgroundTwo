#include <string>

#ifndef __E__LEVEL_H
#define __E__LEVEL_H

enum eLevel
{
    LEVEL_NONE,
    LEVEL_BEGINNER,
    LEVEL_INTERMEDIATE,
    LEVEL_ADVANCED
};

class SLeveleFactory
{
public:
    static std::string getLevelName(eLevel level)
    {
        switch (level)
        {
        case LEVEL_BEGINNER:
            return "BEGINNER";
        case LEVEL_INTERMEDIATE:
            return "INTERMEDIATE";
        case LEVEL_ADVANCED:
            return "ADVANCED";
        case LEVEL_NONE:
        default:
            return "NONE";
        }
    }
};

#endif