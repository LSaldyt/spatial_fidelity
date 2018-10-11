// From https://stackoverflow.com/questions/6942273/how-to-get-a-random-element-from-a-c-container
// Uses mersenne twister, and std::uniform_.., so it should be reliable/efficient.

#include  <random>
#include  <iterator>

template<typename Iter, typename RandomGenerator>
Iter choice(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter choice(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return choice(start, end, gen);
}
