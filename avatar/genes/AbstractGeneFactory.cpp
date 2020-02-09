#include "CGeneAdapter.cpp"

#ifndef __ABSTRACT_GENE_FACTORY_H
#define __ABSTRACT_GENE_FACTORY_H

class AbstractGeneFactory
{
private:
    static AbstractGeneFactory geneFactory;
    AbstractGeneFactory()
    {
        geneFactory = AbstractGeneFactory();
    }

public:
    static AbstractGeneFactory getInstance()
    {
        return geneFactory;
    }
    CGeneAdapter getHumanGene()
    {
        CGeneAdapter gene;
        gene.modify(SPECIES_HUMAN, LEVEL_BEGINNER);
        // gene.getInfo();
        return gene;
    }
};

#endif