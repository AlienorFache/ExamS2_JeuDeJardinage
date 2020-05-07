#include <iostream>
#include <vector>
#include <string>

#include "Plantes.h"
#include "Botanist.h"

using namespace std;

int main()
{
    int day = 1;
    bool play = true;

    Plantes *cactus = new Plantes("Cactus");
    Botanist bernard(vector<Plantes *>(1, cactus));

    while (play)
    {
        cout << "Debut du jour " << day << endl;

        if (day > 1)
        {
            bernard.sleep();
        }

        bool sleeping = false;

        while (!sleeping)
        {
            int choice = 0;
            cout << "Voulez vous dormir(1), acheter une plante(2), acheter de l'angrais(3), vendre une plante(4), inspecter une plante(5) ou s'occuper des plantes(6) ?" << endl;
            cin >> choice;
            
            switch (choice)
            {
            case 1:
                sleeping = true;
                break;
            case 2:
                bernard.buyPlant();
                break;
            case 3:
                bernard.buyFertilizer();
                break;
            case 4:
                bernard.sellPlant();
                break;
            case 5:
                bernard.inspectPlant();
                break;
            case 6:
                bernard.takeCare();
                break;
            default:
                break;
            }
        }
        day++;
    }

    return 0;
}