#pragma once
#include <unordered_map>
#include <tuple>
#include "io.hpp"
#include "hash.hpp"

using std::tuple;
using std::make_tuple;
using std::unordered_map;

using Point = tuple<int, int>;
using HashPoint = hash_tuple::hash<Point>;

template <typename T>
using PointMap = unordered_map<Point, T, HashPoint>;

template <typename T>
struct Lattice
{
    PointMap<T> map;

    void add(int x, int y, T t)
    {
        auto index = make_tuple(x, y);
        auto lookup = map.find(index);
        if (lookup == map.end())
        {
            map[index] = t;
            print("Added successfully");
        }
        else
        {
            print("Insertion failed");
        }
    }

    void remove(int x, int y)
    {
        auto index = make_tuple(x, y);
        auto lookup = map.find(index);
        if (lookup != map.end())
        {
            map.erase(index);
        }
    }
};
