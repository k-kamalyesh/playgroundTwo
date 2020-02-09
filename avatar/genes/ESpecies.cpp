#include <string>

#ifndef __E__SPECIES_H
#define __E__SPECIES_H

using namespace std;

enum eSpecies {
    SPECIES_NONE,
    SPECIES_HUMAN
};

class SCSpeciesInfo
{
public:
    static std::string getSpeciesName(eSpecies species)
    {
        std::string str;
        switch (species)
        {
        case SPECIES_NONE:
            str = std::string("NONE");
            return str;
        default:
        case SPECIES_HUMAN:
            str = std::string("HUMAN");
            return str;
        }
    }
};

#endif