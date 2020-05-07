#ifndef PLANTES_CPP
#define PLANTES_CPP

#include "Plantes.h"
#include <string>
#include <iostream>

using namespace std;

Plantes::Plantes(string name) : _maturity(1), _growSpeed(1), _size(5), _hydratation(100), _health(100), _fertilizer(false), _name(name)
{
}

Plantes::Plantes(float growSpeed, int size, string name) : _maturity(1), _growSpeed(growSpeed), _size(size), _hydratation(100), _health(100), _fertilizer(false), _name(name)
{
}

string Plantes::getName()
{
    return _name;
}

void Plantes::inspect()
{
    cout << "La plante est hydratee a " << _hydratation << "%, sa sante est de " << _health << " sur 100, son espece est : " << _name << "." << endl;
}

void Plantes::fertilize()
{
    if (!_fertilizer)
    {
        _growSpeed *= 2;
    }
    else
    {
        cout << "Vous avez deja donne de l'engrais a cette plante aujourd'hui." << endl;
    }
    
}

void Plantes::cut(int cutLength)
{
    _size -= cutLength;
    _health -= 10;
}

int Plantes::sprinkle()
{
    _hydratation += 20;
    if (_hydratation > 100)
    {
        cout << "Vous avez trop arroser la plante." << endl;
        _health -= 40;
    }
}

void Plantes::beginningOfTheDay()
{  
    if (_health < 50)
    {
        _growSpeed /=2;
    }
    else if (_health > 85)
    {
        _growSpeed /=2;
    }
    _maturity += 1;
    _size += 1*_growSpeed;
    _hydratation -= 25;
    if (_hydratation < 0)
    {
        _hydratation = 0;
    }
    if (_hydratation == 0)
    {
        cout << "La plante a soif." << endl;
        _health -= 40;
        if (_health < 0)
        {
            _health = 0;
        }
    }
    cout << "La plante " << _name << " a une sante de " << _health << "%, elle a grandit de " << _growSpeed << " cm." << endl;

    _growSpeed = 1;
    _fertilizer = false;
}

bool Plantes::death()
{
    if (_health <= 0 )
    {
        cout << "La plante "<< _name << " est morte." << endl;
        return true;
    }

    return false;
}

#endif