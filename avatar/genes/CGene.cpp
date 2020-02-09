#ifndef __C__GENE_H
#define __C__GENE_H

#include "./ESpecies.cpp"
#include "./SPoints.cpp"
#include "./ELevel.cpp"

class CGene
{

protected:
    struct sPoints _points;
    float _height;
    eSpecies _species;
    eLevel _level;

public:
    CGene()
    {
        _species = eSpecies::SPECIES_NONE;
        _level = eLevel::LEVEL_NONE;
        _height = 0.0f;
        _points = SCPointsFactory::getInitialPoints(_species);
    }
    void modify(eSpecies, eLevel) {}
    void getInfo() {}
};

#endif
