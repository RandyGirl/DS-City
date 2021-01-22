#ifndef __CITY_H
#define __CITY_H

#include "crossroad.h"
#include <vector>
#include <unordered_map>

class City
{
    private:
    std::string name;
    std::vector<Crossroad> map;
    std::unordered_map<std::string, bool> visited;

    void set_visitedToNormal();
    std::vector<std::pair<std::string, std::string>> allStreets();
    bool exists(const std::string& crossroad);

    public:
    City();
    City(const std::string& _name);
    City(const std::string& _name, const std::vector<Crossroad>& _map);
    void add(const Crossroad& newCrossroad);
    Crossroad& find(const std::string& name);
    int get_neededDistance(const std::string& start, const std::string& target);
    int shortestPathHelper(const std::string& start, const std::string& target, std::vector<std::string>& finalRes);
    bool hasFullCircleOftheCityHelper(Crossroad& currCrossroad, std::vector<std::pair<std::string, std::string>>& streets,
                                        std::vector<std::pair<std::string, std::string>>& theCircle);

    bool hasPath(const std::string& start, const std::string& target);
    void shortestPath(const std::string& start, const std::string& target);
    void shortestPathAlternative(const std::string& start, const std::string& target, const std::vector<Crossroad>& closedCrossroads);
    bool hasCircleOverPartOfTheCity(const std::string& startingPoint);
    void hasFullCircleOftheCity();
    bool hasPathToAllCrossroads(const Crossroad& crossroad);
    void allDeadends();

    std::vector<Crossroad> get_map()const;

};

std::ostream& operator<<(std::ostream& out, const City& city);
std::istream& operator>>(std::istream& in, City& city);

#endif