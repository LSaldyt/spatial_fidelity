/// Copyright 2018 Lucas Saldyt
#include <vector>
#include <string>

#include "io.hpp"

using std::vector;
using std::string;

/**
 * Demonstration of very high-level compiler usage
 */
int main(int argc, char* argv[])
{

    vector<string> args;
    for (int i = 1; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    print("Compilation finished");
}

