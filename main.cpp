/// Copyright 2018 Lucas Saldyt
#include <vector>
#include <string>

#include "io.hpp"
#include "lattice.hpp"
#include "agent.hpp"
#include "field.hpp"

using std::vector;
using std::string;

int main(int argc, char* argv[])
{
    vector<string> args;
    for (int i = 1; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    auto field = Field<Agent>(0, 100, 0, 100);
    field.add(1, 1, Agent(0, 0, 0));
    int i = 0;
    while(true)
    {
        field.update();
        if (i == 10000)
        {
            break;
        }
        i++;
    }
}

