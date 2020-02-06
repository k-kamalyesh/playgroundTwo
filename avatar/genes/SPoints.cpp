#include "./ESpecies.cpp"
#include "./ELevel.cpp"

#ifndef __S__POINTS_H
#define __S__POINTS_H
struct sPoints
{
    float health_points;
    float magic_points;
    float intelligence_points;
};

class SCPointsFactory
{
public:
    static struct sPoints getInitialPoints(eSpecies species)
    {
        struct sPoints _initial_points;
        switch (species)
        {
        case NONE:
            _initial_points.magic_points = 0;
            _initial_points.health_points = 0;
            _initial_points.intelligence_points = 0;
            break;

        case HUMAN:
        default:
            _initial_points.magic_points = 0;
            _initial_points.health_points = 0;
            _initial_points.intelligence_points = 0;
            break;
        }
        return _initial_points;
    }

    static struct sPoints getMinimumPoints(eSpecies species, eLevel level)
    {
        struct sPoints _minimum_points;
        switch (species)
        {
        case NONE:
            switch (level)
            {
            case BEGINNER:
            case INTERMEDIATE:
            case ADVANCED:
            default:
                _minimum_points.magic_points = 0;
                _minimum_points.health_points = 0;
                _minimum_points.intelligence_points = 0;
            }
            break;

        case HUMAN:
        default:
            switch (level)
            {
            case BEGINNER:
                _minimum_points.magic_points = 10;
                _minimum_points.health_points = 10;
                _minimum_points.intelligence_points = 10;
                break;
            case INTERMEDIATE:
                _minimum_points.magic_points = 100;
                _minimum_points.health_points = 100;
                _minimum_points.intelligence_points = 100;
                break;
            case ADVANCED:
            default:
                _minimum_points.magic_points = 1000;
                _minimum_points.health_points = 1000;
                _minimum_points.intelligence_points = 1000;
            }
            break;
        }
        return _minimum_points;
    }

    static struct sPoints getMaximumPoints(eSpecies species, eLevel level)
    {
        struct sPoints _maximum_points;
        switch (species)
        {
        case NONE:
            switch (level)
            {
            case BEGINNER:
            case INTERMEDIATE:
            case ADVANCED:
            default:
                _maximum_points.magic_points = 0;
                _maximum_points.health_points = 0;
                _maximum_points.intelligence_points = 0;
            }
            break;

        case HUMAN:
        default:
            switch (level)
            {
            case BEGINNER:
                _maximum_points.magic_points = 99;
                _maximum_points.health_points = 99;
                _maximum_points.intelligence_points = 99;
                break;
            case INTERMEDIATE:
                _maximum_points.magic_points = 999;
                _maximum_points.health_points = 999;
                _maximum_points.intelligence_points = 999;
                break;
            case ADVANCED:
            default:
                _maximum_points.magic_points = 9999;
                _maximum_points.health_points = 9999;
                _maximum_points.intelligence_points = 9999;
            }
            break;
        }
        return _maximum_points;
    }
};

#endif