#include <string>

#ifndef __E__SPECIES_H
#define __E__SPECIES_H

using namespace std;

enum eSpecies {
    NONE,
    HUMAN
};

class SCSpeciesInfo
{
public:
    static std::string getSpeciesName(eSpecies species)
    {
        std::string str;
        switch (species)
        {
        case eSpecies::NONE:
            str = std::string("NONE");
            return str;
        default:
        case eSpecies::HUMAN:
            str = std::string("HUMAN");
            return str;
        }
    }
};

#endif