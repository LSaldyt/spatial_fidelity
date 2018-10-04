#include "lattice.hpp"
#include "hash.hpp"
#include <string>
#include <unordered_map>
#include <unordered_set>

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

    void add(int x, int y, T t)
    {
        bool x_valid = (x >= x_min) and (x <= x_max);
        bool y_valid = (y >= y_min) and (y <= y_max);
        if (x_valid and y_valid)
        {
            lattice.add(x, y, t);
        }
    }

    void update()
    {
        int i = 0;
        for (auto& kv : lattice.map)
        {
            i++;
        }
        print(i);
    }
};
