#ifndef BOTANIST_CPP
#define BOTANIST_CPP

#include "Plantes.h"
#include "Botanist.h"
#include <string>
#include <iostream>

using namespace std;

Botanist::Botanist(std::vector<Plantes *> plantInventory) : _fertilizer(1), _money(100), _plantInventory(plantInventory)
{
}

void Botanist::sleep()
{
    vector<int> toRemove;
    for (int i = 0; i < _plantInventory.size(); i++)
    {
        _plantInventory[i]->beginningOfTheDay();

        if (_plantInventory[i]->death())
        {
            delete _plantInventory[i];
            toRemove.push_back(i);
        }
    }

    for (int i = 0; i < toRemove.size(); i++)
    {
        _plantInventory.erase(_plantInventory.begin() + toRemove[i] - 1);
    }
}

void Botanist::buyPlant()
{
    if (_money > 20)
    {
        cout << "Une plante coute 20 euro, donnez lui un nom :" << endl;
        string newName = "unnamed";
        cin >> newName;

        Plantes *plant = new Plantes(newName);
        _plantInventory.push_back(plant);
        _money -= 20;
    }
    else
    {
        cout << "Vous n'avez pas assez d'argent" << endl;
    }
}

void Botanist::sellPlant()
{
    cout << "Vous pouvez vendre :" << endl;
    for (int i = 0; i < _plantInventory.size(); i++)
    {
        if (_plantInventory[i]->getMaturity() > 10)
        {
            cout << i + 1 << " : " << _plantInventory[i]->getName() << endl;
        }
    }

    // int plant = 0;
    // cin >> plant;
    // delete _plantInventory[plant];
    // _plantInventory[plant].erase;
    // _money += 50;
}

void Botanist::buyFertilizer()
{
    if (_money > 10)
    {
        _money -= 10;
        _fertilizer++;
    }
    else
    {
        cout << "Vous n'avez pas assez d'argent." << endl;
    }
}

void Botanist::inspectPlant()
{
    for (int i = 0; i < _plantInventory.size(); i++)
    {
        cout << i + 1 << " : " << _plantInventory[i]->getName() << endl;
    }

    int rank = 0;
    cout << "Quelle plante voulez vous inspecter ?" << endl;
    cin >> rank;
    _plantInventory[rank - 1]->inspect();
}

void Botanist::takeCare()
{
    for (int i = 0; i < _plantInventory.size(); i++)
    {
        cout << i + 1 << " : " << _plantInventory[i]->getName() << endl;
    }

    int rank = 0;
    cout << "De quelle plantes voulez vous vous occupez ?" << endl;
    cin >> rank;

    bool endCare = false;
    while (!endCare)
    {
        int choice = 0;
        cout << "Voulez vous arroser(1), tailler(2), donner de l'engrais(3) ou inspecter(4) cette plante ?" << endl;
        cin >> choice;

        // if (choice == 1) {}

        int length = 0;
        switch (choice)
        {
        case 1:
            _plantInventory[rank]->sprinkle();
            break;
        case 2:

            cout << "De combien voulez vous coupez la plante ?" << endl;
            cin >> length;
            _plantInventory[rank]->cut(length);
            break;
        case 3:
            if (_fertilizer > 0)
            {
                _plantInventory[rank]->fertilize();
                _fertilizer--;
            }
            else
            {
                cout << " Vous n'avez pas d'engrais." << endl;
            }
            break;
        case 4:
            _plantInventory[rank]->inspect();
            break;
        default:
            break;
        }

        int answer = 0;
        cout << "faire autre chose avec cette plante ? (oui(1) ou non(2))" << endl;
        cin >> answer;

        switch (answer)
        {
        case 1:
            break;
        case 2:
            endCare = true;
            break;
        default:
            break;
        }
    }
}

#endif