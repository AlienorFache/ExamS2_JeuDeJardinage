#ifndef BOTANIST_H
#define BOTANIST_H

#include <string>
#include <vector>

#include "Plantes.h"

class Botanist{
    protected :
        int _money;
        int _fertilizer;
        std::vector<Plantes*> _plantInventory;

    public :
        Botanist(std::vector<Plantes*> plantInventory);
        
        void sleep();
        void buyPlant();
        void sellPlant();
        void buyFertilizer();
        void inspectPlant();
        void takeCare();
            
};

#endif