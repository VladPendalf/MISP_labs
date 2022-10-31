#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>
#include <iostream>

struct Node
{
    int   priority; //чем больше, тем выше приоритет
    int   info;  //значение в индексе
    Node* next;
};

class PriorityQueue
{
public:
    PriorityQueue();

    void Insert(int Info, int index);
    void Pop();
    void Show();
    bool isEmpty();
    int getHighestPriority();

    ~PriorityQueue();

private:
    Node* head;
};

#endif // PRIORITYQUEUE_H
