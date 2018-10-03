/// Copyright 2018 Lucas Saldyt
#include <vector>
#include <string>

#include "io.hpp"
#include "lattice.hpp"
#include "agent.hpp"

using std::vector;
using std::string;

int main(int argc, char* argv[])
{
    vector<string> args;
    for (int i = 1; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    auto lattice = Lattice<Agent>();
    lattice.add(1, 1, Agent());
}

