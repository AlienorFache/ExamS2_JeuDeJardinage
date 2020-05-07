#include <iostream>
#include <vector>
#include <string>

#include "Plantes.h"

using namespace std;
        
int main()
{
    int day = 1;
    bool start = true;

    Plantes * cactus = new Plantes ("Cactus");

    while (day < 7)
    {
        cout << "Debut du jour " << day << endl;

        cactus->beginningOfTheDay();
        if (cactus->death())
        {
            delete cactus;
        }

        day ++;
    }

    return 0;
}