#include "lattice.hpp"
#include "hash.hpp"
#include "choice.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

template <typename T>
struct Field
{
    Lattice<T> lattice;
    PointMap<string> task_point_map;
    unordered_map<string, unordered_set<Point, HashPoint>> task_map;

    int x_min = 0;
    int x_max = 0;
    int y_min = 0;
    int y_max = 0;

    Field()
    {}

    Field(int x, int y)
    {
        x_max = x;
        y_max = y;
    }

    Field(int set_x_min, int set_x_max, int set_y_min, int set_y_max)
    {
        x_min = set_x_min;
        x_max = set_x_max;
        y_min = set_y_min;
        y_max = set_y_max;
    }

    void add_task(string taskname, unordered_set<Point, HashPoint> points)
    {
        task_map[taskname] = points;
        for (auto& point : points)
        {
            task_point_map[point] = taskname;
        }
    }

    vector<Point> adjacent(int x, int y)
    {
        vector<Point> points;
        points.push_back(make_tuple(x, y + 1));
        points.push_back(make_tuple(x, y - 1));
        points.push_back(make_tuple(x + 1, y));
        points.push_back(make_tuple(x - 1, y));
        return points;
    }

    bool valid(int x, int y)
    {
        bool x_valid = (x >= x_min) and (x <= x_max);
        bool y_valid = (y >= y_min) and (y <= y_max);
        return x_valid and y_valid;
    }


    void add(int x, int y, T t)
    {
        if (valid(x, y))
        {
            lattice.add(x, y, t);
        }
    }

    void remove(int x, int y)
    {
        if (valid(x, y))
        {
            lattice.remove(x, y);
        }
    }

    void update()
    {
        for (auto& kv : lattice.map) // O(n)
        {
            Point location = kv.first;
            T& agent       = kv.second;
            int x = std::get<0>(location);
            int y = std::get<1>(location);
            auto points = adjacent(x, y);

            points.erase(std::remove_if(points.begin(), points.end(), 
                        [this](auto &p){return (not this->valid(std::get<0>(p), std::get<1>(p))) or 
                                                   (this->lattice.map.find(p) != this->lattice.map.end());}));
            if (not points.empty())
            {
                Point next = *choice(points.begin(), points.end());
                int px = std::get<0>(next);
                int py = std::get<1>(next);
                if (not valid(px, py))
                {
                    print("Invalid step taken:");
                    print(px, py);
                }
                add(px, py, agent);
                remove(x, y);
            }
        }
    }
};
