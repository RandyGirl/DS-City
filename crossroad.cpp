#ifndef __CROSSROAD_CPP
#define __CROSSROAD_CPP

#include "crossroad.h"
#include <iostream>
#include <sstream>

Crossroad::Crossroad()
{
    this->name = "random";
}
Crossroad::Crossroad(const std::string& _name)
{
    this->name = _name;
}
void Crossroad::copy(const Crossroad& other)
{
    this->name = other.name;
    this->neighbours = other.neighbours;
}
void Crossroad::add(const std::string& _name, int _distance)
{
    neighbours[_name] = _distance;
}
std::string Crossroad::get_name()const 
{
    return this->name;
}
void Crossroad::set_name(std::string _name)
{
    this->name = _name;
}
int Crossroad::get_neededDistance(const std::string& target)
{
    for(auto it: neighbours){
        if(it.first == target){
            return it.second;
        }
    }
}
bool Crossroad::hasNeighbourNamed(const std::string& target)
{
    return !(neighbours.find(target) == neighbours.end());
}
std::unordered_map<std::string, int> Crossroad::get_neighbours()const
{
    return neighbours;
}
bool Crossroad::hasNeighbours()const
{
    //returns true if it is empty
    return this->neighbours.empty();
}
bool Crossroad::operator==(const Crossroad& other)
{
    return this->name == other.name && this->neighbours == other.neighbours;
}
Crossroad& Crossroad::operator=(const Crossroad& other)
{
    if(this != &other){
        this->copy(other);
    }

    return *this;
}

void Crossroad::print()
{
    for(auto it: neighbours){
        std::cout << it.first << " " << it.second << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Crossroad& crossroad)
{
    out << crossroad.get_name();
    std::unordered_map<std::string, int> neib = crossroad.get_neighbours();

    for(auto it: neib){
        out << ' ' << it.first << ' ' << it.second;
    }
    out << '\n';

    return out;
}
std::istream& operator>>(std::istream& in, Crossroad& crossroad)
{
    Crossroad newCrossroad;
    std::string line;
    std::getline(in, line); 

    std::stringstream ss(line);
    std::string name;
    ss >> name;
    newCrossroad.set_name(name);
    std::string key;
    int value;
    while(ss >> key  >> value)
    {
        newCrossroad.add(key, value);
    }
    crossroad = newCrossroad;

    return in;
}

#endif