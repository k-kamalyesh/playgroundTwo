#include <iostream>
#include <string>

#ifndef __C__GENE_ADAPTER_H
#define __C__GENE_ADAPTER_H

#include "./CGene.cpp"
using namespace std;

class CGeneAdapter : public CGene
{
private:
    float getAverageHeightOf(eSpecies species)
    {
        switch (species)
        {
        case eSpecies::SPECIES_NONE:
            return 0.0;
        case eSpecies::SPECIES_HUMAN:
        default:
            return 5.7f;
        }
    }

public:
    CGeneAdapter()
    {
        CGene();
    }
    void modify(eSpecies species = SPECIES_HUMAN, eLevel level = LEVEL_BEGINNER)
    {
        _species = species;
        _level = level;
        _height = getAverageHeightOf(_species);
        _points = SCPointsFactory::getMaximumPoints(_species, _level);
    }
    void getInfo()
    {
        std::cout << "----- GENE INFORMATION -----\n";
        std::cout << "----- Species: " << SCSpeciesInfo::getSpeciesName(_species) << "\n";
        std::cout << "----- Height: " << _height << "\n";
        std::cout << "----- Level: " << SLeveleFactory::getLevelName(_level) << "\n";
        std::cout << "----- Points(at current level): \n\tHP-" << _points.health_points << "\tMP-" << _points.magic_points << "\tIP-" << _points.intelligence_points << "\n";
        std::cout << "----- Minimum Points(at current level):\n\t HP-" << SCPointsFactory::getMinimumPoints(_species, _level).health_points << "\tMP-" << SCPointsFactory::getMinimumPoints(_species, _level).magic_points << "\tIP-" << SCPointsFactory::getMinimumPoints(_species, _level).intelligence_points << "\n";
        std::cout << "----- Maximum Points(at current level):\n\t HP-" << SCPointsFactory::getMaximumPoints(_species, _level).health_points << "\tMP-" << SCPointsFactory::getMaximumPoints(_species, _level).magic_points << "\tIP-" << SCPointsFactory::getMaximumPoints(_species, _level).intelligence_points << "\n";
        std::cout << std::endl;
    }
};
#endif