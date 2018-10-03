#include "lattice.hpp"

template <typename T>
void update(Lattice<T> lattice)
{
    int i = 0;
    for (auto& kv : lattice.map)
    {
        i++;
    }
    print(i);
}
