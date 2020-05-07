#ifndef PLANTES_H
#define PLANTES_H

#include <string>

class Plantes{
    protected :
        int _maturity;
        float _growSpeed;
        int _size;
        int _hydratation;
        int _health;
        bool _fertilizer;
        std::string _name;

    public :
        Plantes(float growSpeed, int size, std::string name);
        Plantes(std::string name);
        void inspect();
        void fertilize();
        void cut(int cutLength);
        int sprinkle();
        void beginningOfTheDay();
        bool death();

        
};

#endif