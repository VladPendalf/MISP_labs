#include "slidingwindowmax.h"

SlidingWindowMax::SlidingWindowMax(const std::vector<int> v, const int k): //non-transformers
    _vectorOfValues(std::move(v)),
    _countElementsInWindow(k) {Result();};
//можно было бы и инициализурующим конструктором обойтись
//он, вроде, из коробки оптимизируется до семантики, ну да ладно и так сойдет :)

void SlidingWindowMax::Result()
{
    for(int i=0;i<_vectorOfValues.size();i++)
    {
        //Что не в окне, то за окно
        if(!_maxElements.empty() && _maxElements.front() == i-_countElementsInWindow) _maxElements.pop_front();

        //удаляем все меньшие индексы, до нового _vectorOfValues[i]
        while(!_maxElements.empty() && _vectorOfValues[_maxElements.back()] <= _vectorOfValues[i])
        {
            _maxElements.pop_back();
        }

        _maxElements.push_back(i);
        if(i >= _countElementsInWindow-1)
        {
            std::cout << _vectorOfValues[_maxElements.front()] << " ";
        }
    }
}
