#pragma once
#include <unordered_map>
#include <tuple>
#include "io.hpp"
#include "hash.hpp"

using std::tuple;
using std::make_tuple;
using std::unordered_map;

using LocationKey = tuple<int, int>;

template <typename T>
struct Lattice
{
    unordered_map<LocationKey, T, hash_tuple::hash<LocationKey>> map;

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
};
