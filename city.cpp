#ifndef __CITY_CPP
#define __CITY_CPP

#include "city.h"
#include "crossroad.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <limits>

void City::set_visitedToNormal()
{
    for(auto it: map){
        visited[it.get_name()] = false;
    }
}
std::vector<std::pair<std::string, std::string>> City::allStreets()
{
    std::vector<std::pair<std::string, std::string>> streets;
    for(int i = 0; i < map.size(); ++i){
        Crossroad curr = map[i];
        std::unordered_map<std::string, int> neib = curr.get_neighbours();
        for(auto it: neib){
            streets.push_back(std::make_pair(curr.get_name(), it.first));
        }
    }

    return streets;
}
bool City::exists(const std::string& crossroad)
{
    for(auto it: map){
        if(it.get_name() == crossroad){
            return true;
        }
    }

    return false;
}
City::City()
{

}
City::City(const std::string& _name)
{
    this->name = _name;
}
City::City(const std::string& _name, const std::vector<Crossroad>& _map)
{
    this->name = _name;
    this->map = _map;
    this->set_visitedToNormal();
}
void City::add(const Crossroad& newCrossroad)
{
    map.push_back(newCrossroad);
    visited[newCrossroad.get_name()] = false;
}
Crossroad& City::find(const std::string& name)
{
    for(int i = 0; i < map.size(); ++i){
        if(map[i].get_name() == name){
            return map[i];
        }
    }
}
int City::get_neededDistance(const std::string& start, const std::string& target)//проверка дали има път
{
    for(int i = 0; i < map.size(); ++i){
        if(map[i].get_name() == start){
            return map[i].get_neededDistance(target);
        }
    }
}
int City::shortestPathHelper(const std::string& start, const std::string& target, std::vector<std::string>& finalRes)
{
    std::vector<std::string> res;
    int currMinPath = INT_MAX;

    Crossroad curr = find(start);
    if(curr.hasNeighbourNamed(target)){
        currMinPath = curr.get_neededDistance(target);
        res.push_back(curr.get_name());
    }

    std::unordered_map<std::string, int> neib = curr.get_neighbours();

    int newMinPath = 0;

    visited.find(start)->second = true;

    for(auto it: neib)
    {
        if(visited.find(it.first)->second == false){
        if(hasPath(it.first, target)){
            int path = shortestPathHelper(it.first, target, finalRes);
            if(path != INT_MAX){
            
                newMinPath = it.second + path;
                if(newMinPath < currMinPath){
                    currMinPath = newMinPath;
                    res.clear();
                    res.push_back(start);
                    res.push_back(it.first);
                }
            }
        }}
        visited.find(it.first)->second = true;
    }

    finalRes = res;
    return currMinPath;
}
bool City::hasFullCircleOftheCityHelper(Crossroad& currCrossroad, std::vector<std::pair<std::string, std::string>>& streets,
                                        std::vector<std::pair<std::string, std::string>>& theCircle)
{
    if(streets.empty()){
        return true;
    }

    bool hasCircle = false;
    std::unordered_map<std::string, int> neib = currCrossroad.get_neighbours();

    for(auto it: neib){
        for(int p = 0; p < streets.size(); ++p){
            if(currCrossroad.get_name() == streets[p].first && it.first == streets[p].second){
                streets.erase(streets.begin() + p);
                theCircle.push_back(std::make_pair(currCrossroad.get_name(), it.first));
                if(hasFullCircleOftheCityHelper(find(it.first), streets, theCircle)){
                    hasCircle = true;
                    break;
                }
            }
        }
    }

    return hasCircle;
}


bool City::hasPath(const std::string& start, const std::string& target)
{
    if(!exists(start)){
        return false;
    }

    if(visited[start]){
        return false;
    }

    visited[start] = true;
    if(find(start).hasNeighbourNamed(target)){
        visited[start] = false;
        return true;
    }

    std::unordered_map<std::string, int> neib = find(start).get_neighbours();


    bool hasPathInTheNeighbours = false;
    for(auto it: neib){
        hasPathInTheNeighbours |= hasPath(it.first, target);
        visited[it.first] = false;
    }

    visited[start] = false;
    return hasPathInTheNeighbours;
}
void City::shortestPath(const std::string& start, const std::string& target)
{
    std::vector<std::string> finalRes;
    this->set_visitedToNormal();

    std::cout << "The shortest path from " << start << " to " << target << " is:" << this->shortestPathHelper(start, target, finalRes) <<
                "\n And the Hole Path is:" << std::endl;
    for(int i = 0; i < finalRes.size(); ++i){
        std::cout << finalRes[i] << " -> ";
    }
    std::cout << target << std::endl;
}
void City::shortestPathAlternative(const std::string& start, const std::string& target, const std::vector<Crossroad>& closedCrossroads)
{
    //merge with shortestPath
    City alternativeCity = City(this->name, this->map); 
    for(int i = 0; i < alternativeCity.map.size(); ++i){
        for(int j = 0; j < closedCrossroads.size(); ++j){
            if(alternativeCity.map[i] == closedCrossroads[j]){
                alternativeCity.map.erase(alternativeCity.map.begin() + i);
            }
        }
    }

    alternativeCity.shortestPath(start, target);
}
bool City::hasCircleOverPartOfTheCity(const std::string& startingPoint)
{
    return this->hasPath(startingPoint, startingPoint);
}
void City::hasFullCircleOftheCity()
{
    std::vector<std::pair<std::string, std::string>> streets = this->allStreets();

    std::vector<std::pair<std::string, std::string>> theCircle;
    std::vector<std::pair<std::string, std::string>> copyStreets = streets;

    for(int j = 0; j < this->map.size(); ++j){
        std::cout << map[j].get_name() << std::endl;
        if(hasFullCircleOftheCityHelper(map[j], copyStreets, theCircle)){
            break;
        }
        theCircle.clear();
        copyStreets = streets;
    }

    if(theCircle.empty()){
        std::cout << "It is not posible to do full circle over the city " << std::endl;
    }
    else{
        std::cout << "The path is: " << std::endl;
        for(int l = 0; l < theCircle.size(); ++l){
            std::cout << theCircle[l].first << "->" << theCircle[l].second << std::endl;
        }
    }
}
bool City::hasPathToAllCrossroads(const Crossroad& crossroad)
{
    int counter = 0;
    for(int i = 0; i < map.size(); ++i){
        if(crossroad.get_name() != map[i].get_name() && hasPath(crossroad.get_name(), map[i].get_name())){
            ++counter;
        }
    }

    return counter == map.size() - 1;
}
void City::allDeadends()
{
    std::vector<std::pair<std::string, std::string>> streets = this->allStreets();
    std::unordered_map<std::string, std::string> deadEnds;

    for(auto st: streets){
        if(find(st.second).hasNeighbours()){
            deadEnds[st.first] = st.second;
        }
    }

    if(deadEnds.empty()){
        std::cout << "There is no deadends" << std::endl;
    }
    else{
        std::cout << "ALL deadends are:" << std::endl;
        for(auto de: deadEnds){
            std::cout << de.first << "->" << de.second << std::endl;
        }
    }

}

std::vector<Crossroad> City::get_map()const
{
    return map;
}


std::ostream& operator<<(std::ostream& out, const City& city)
{
    std::vector<Crossroad> crossroads = city.get_map();
    for(auto it: crossroads){
        out << it;
    }
    return out;
}
std::istream& operator>>(std::istream& in, City& city)
{
    Crossroad crossroad;
    while(in >> crossroad)
    {
        city.add(crossroad);
    }

    return in;
}


#endif