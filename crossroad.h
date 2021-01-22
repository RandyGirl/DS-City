#ifndef __CROSSROAD_H
#define __CROSSROAD_H

#include <string>
#include <unordered_map>


class Crossroad
{
    private:
    std::string name;
    std::unordered_map<std::string, int> neighbours;

    void copy(const Crossroad& other);

    public:
    Crossroad();
    Crossroad(const std::string& _name);
    void add(const std::string& _name, int _distance);
    std::string get_name()const;
    void set_name(std::string _name);
    int get_neededDistance(const std::string& target);
    bool hasNeighbourNamed(const std::string& target);
    std::unordered_map<std::string, int> get_neighbours()const;
    bool hasNeighbours()const;//////////
    bool operator==(const Crossroad& other);
    Crossroad& operator=(const Crossroad& other);
    void print();

};

std::ostream& operator<<(std::ostream& out, const Crossroad& crossroad);
std::istream& operator>>(std::istream& in, Crossroad& crossroad);


#endif