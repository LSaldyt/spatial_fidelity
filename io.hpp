/// Copyright 2017 Lucas Saldyt
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

/// Abstract IO
template <typename T>
void print(T t) {
    std::cout << t << "\n";
}

/// Abstract IO
template <typename T, typename... Args>
void print(T first, Args... args) {
    print(first);
    print(args...);
    std::cout << "\n";
}
