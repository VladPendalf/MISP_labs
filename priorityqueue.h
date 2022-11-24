#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>
#include <iostream>

template <class T, class Container = std::vector<T>>
class MyPriorQueue
{
public:
    T    top()   const { return _array[0];            }
    bool empty() const { return (_array.size() == 0); }

    void push(const T& newValue);
    void pop();

private:
    Container _array;

    void _defragFrom  (std::size_t id);
    void _fixAfterPush(std::size_t id);

    std::size_t _getParentId    (std::size_t id) const { return ((id - 1)/2); }
    std::size_t _getLeftChildId (std::size_t id) const { return (2 * id + 1); }
    std::size_t _getRightChildId(std::size_t id) const { return (2 * id + 2); }
};

template <class T, class Container>
void MyPriorQueue<T, Container>::_defragFrom(std::size_t id)
{
    std::size_t leftId       = _getLeftChildId(id);
    std::size_t rightId      = _getRightChildId(id);
    std::size_t theBiggestId = id;

    if (leftId < _array.size() && _array[leftId] > _array[id])
    {
        theBiggestId = leftId;
    }
    if (rightId < _array.size() && _array[rightId] > _array[theBiggestId])
    {
        theBiggestId = rightId;
    }
    if (theBiggestId != id)
    {
        std::swap(_array[theBiggestId], _array[id]);
        _defragFrom(theBiggestId);
    }
}

template <class T, class Container>
void MyPriorQueue<T, Container>::_fixAfterPush(std::size_t id)
{
    if (id == 0) return;

    if (_array[_getParentId(id)] < _array[id])
    {
        std::swap(_array[_getParentId(id)], _array[id]);
        _fixAfterPush(_getParentId(id));
    }
}

template <class T, class Container>
void MyPriorQueue<T, Container>::push(const T& newValue)
{
    _array.push_back(newValue);
    _fixAfterPush(_array.size() - 1);
}

template <class T, class Container> void MyPriorQueue<T, Container>::pop()
{
    _array[0] = _array[_array.size() - 1];
    _array.pop_back();
    _defragFrom(0);
}

#endif // PRIORITYQUEUE_H
