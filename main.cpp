#include "./avatar/genes/CGene.cpp"
#include "./avatar/genes/AbstractGeneFactory.cpp"

main()
{
    CGene gene;
    gene.getInfo();
    CGeneAdapter adpater;
    adpater.modify(SPECIES_HUMAN, LEVEL_INTERMEDIATE);
    adpater.getInfo();
    AbstractGeneFactory geneFactory = AbstractGeneFactory::getInstance();
    CGeneAdapter newGene;
    newGene = geneFactory.getHumanGene();
    newGene.modify(SPECIES_HUMAN, LEVEL_ADVANCED);
    newGene.getInfo();
}