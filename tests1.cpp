#include <iostream>

#include "crossroad.h"
#include "city.h"
#include <fstream>

void test_hasPath()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);

    std::cout << sofia.hasPath("popa", "bsfs") << std::endl;
    std::cout << sofia.hasPath("popa", "ndk") << std::endl;
    std::cout << sofia.hasPath("ndk", "bsfs") << std::endl;
    std::cout << sofia.hasPath("npk", "bsfs") << std::endl;
    std::cout << sofia.hasPath("bsfs", "5kesheta") << std::endl;
}
void test_shortestPath()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);
    bsfs.add("ndk", 1500);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);

    sofia.shortestPath("popa", "bsfs");
    sofia.shortestPath("popa", "ndk");

    std::vector<Crossroad> closedCrossroads;
    closedCrossroads.push_back(petkesheta);
    sofia.shortestPathAlternative("popa", "ndk", closedCrossroads);
}
void test_hasCircleOverPartOfTheCity()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);

    std::cout << sofia.hasCircleOverPartOfTheCity("ndk") << std::endl;
    std::cout << sofia.hasCircleOverPartOfTheCity("5kesheta") << std::endl;
}
void test_hasFullCircleOftheCity()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);


    sofia.hasFullCircleOftheCity();
}
void test_hasPathToAllCrossroads()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);

    std::cout << sofia.hasPathToAllCrossroads(popa) << std::endl;
    std::cout << sofia.hasPathToAllCrossroads(bsfs) << std::endl;
}
void test_deadend()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);
    bsfs.add("b", 300);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);
    ndk.add("b", 800);

    Crossroad b = Crossroad("b");

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);
    sofia.add(b);

    sofia.allDeadends();
}
void test_file()
{
    Crossroad popa = Crossroad("popa");
    popa.add("bsfs", 150);
    popa.add("5kesheta", 1000);

    Crossroad bsfs = Crossroad("bsfs");
    bsfs.add("popa", 150);

    Crossroad petkesheta = Crossroad("5kesheta");
    petkesheta.add("ndk", 400);

    Crossroad ndk = Crossroad("ndk");
    ndk.add("popa", 800);

    City sofia = City("Sofia");
    sofia.add(popa);
    sofia.add(bsfs);
    sofia.add(petkesheta);
    sofia.add(ndk);

    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile << sofia;
    myfile.close();

    City sofia2;
    std::ifstream myfile2;
    myfile2.open ("example.txt");
    myfile2 >> sofia2;
    myfile2.close();

    std::cout << sofia2 << std::endl;
}

int main()
{
    //test_hasPath();
    //test_shortestPath();
    //test_hasCircleOverPartOfTheCity();
    test_hasFullCircleOftheCity();
    //test_hasPathToAllCrossroads();
    //test_deadend();
    //test_file();

}
