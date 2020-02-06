#include <iostream>
#include <string>

#ifndef __C__GENE_H
#define __C__GENE_H

#include "./ESpecies.cpp"
#include "./SPoints.cpp"
#include "./ELevel.cpp"


using namespace std;

class CGene
{

private:
    struct sPoints _points;
    float _height;
    eSpecies _species;
    eLevel _level;
    float getAverageHeightOf(eSpecies species)
    {
        switch (species)
        {
        case eSpecies::NONE:
            return 1.0f;
        default:
        case eSpecies::HUMAN:
            return 5.7f;
        }
    }

public:
    CGene()
    {
        _species = eSpecies::HUMAN;
        _height = getAverageHeightOf(_species);
        _points = SCPointsFactory::getInitialPoints(_species);
        _level = eLevel::BEGINNER;
    }

    void getInfo()
    {
        std::cout << "----- GENE INFORMATION -----\n";
        std::cout << "----- Species: " << SCSpeciesInfo::getSpeciesName(_species) << "\n";
        std::cout << "----- Height: " << _height << "\n";
        std::cout << "----- Level: " << _level << "\n";
        std::cout << "----- Points(at current level): \n\tHP-" << _points.health_points << "\tMP-" << _points.magic_points << "\tIP-" << _points.intelligence_points << "\n";
        std::cout << "----- Minimum Points(at current level):\n\t HP-" << SCPointsFactory::getMinimumPoints(_species, _level).health_points << "\tMP-" << SCPointsFactory::getMinimumPoints(_species, _level).magic_points << "\tIP-" << SCPointsFactory::getMinimumPoints(_species, _level).intelligence_points << "\n";
        std::cout << "----- Maximum Points(at current level):\n\t HP-" << SCPointsFactory::getMaximumPoints(_species, _level).health_points << "\tMP-" << SCPointsFactory::getMaximumPoints(_species, _level).magic_points << "\tIP-" << SCPointsFactory::getMaximumPoints(_species, _level).intelligence_points << "\n";
        std::cout << std::endl;
    }
};

#endif

main()
{
    CGene newGene;
    newGene.getInfo();
}