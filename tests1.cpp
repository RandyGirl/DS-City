#include <iostream>

#include "crossroad.h"
#include "city.h"
#include <fstream>

int main()
{
    
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);
    bsfs.add("ndk", 1500);
    //bsfs.add("b", 300);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);
    //ndk.add("b", 800);

    //Crossroad b = Crossroad("b");

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);
    //sofia.add(b);

    std::cout << sofia.hasPath("popa", "bsfs") << std::endl;
    std::cout << sofia.hasPath("popa", "ndk") << std::endl;
    std::cout << sofia.hasPath("ndk", "bsfs") << std::endl;
    std::cout << sofia.hasPath("npk", "bsfs") << std::endl;
    std::cout << sofia.hasPath("bsfs", "5kesheta") << std::endl;


/*
    sofia.shortestPath("popa", "bsfs");
    sofia.shortestPath("popa", "ndk");
*/

/*
    std::vector<Crossroad> closedCrossroads;
    closedCrossroads.push_back(petkesheta);
    sofia.shortestPathAlternative("popa", "ndk", closedCrossroads);
*/

/*
    std::cout << sofia.hasCircleOverPartOfTheCity("ndk") << std::endl;//виж какво точни изписва
    std::cout << sofia.hasCircleOverPartOfTheCity("5kesheta") << std::endl;
*/


//sofia.hasFullCircleOftheCity();



/*
    std::cout << sofia.hasPathToAllCrossroads(popa) << std::endl;//по-хубав тест
    std::cout << sofia.hasPathToAllCrossroads(bsfs) << std::endl;
*/

//sofia.allDeadends();

//     std::ofstream myfile;
//     myfile.open ("example.txt");
//     myfile << sofia;
//     myfile.close();

//     City sofia2;
//     std::ifstream myfile2;
//     myfile2.open ("example.txt");
//     myfile2 >> sofia2;
//     myfile2.close();

//     std::cout << sofia2 << std::endl;
// 

}
