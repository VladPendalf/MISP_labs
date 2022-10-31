#ifndef SLIDINGWINDOWMAX_H
#define SLIDINGWINDOWMAX_H
#include <deque>
#include <vector>
#include <iostream>
class SlidingWindowMax
{
public:
    explicit SlidingWindowMax(const std::vector<int> v, const int k = 1); //non-transformers

    void Result(); //finished output;
private:
    int              _countElementsInWindow;
    std::deque<int>  _maxElements;
    std::vector<int> _vectorOfValues;
};

#endif // SLIDINGWINDOWMAX_H
