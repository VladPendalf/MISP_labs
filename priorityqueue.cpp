#include "priorityqueue.h"

///    PriorityQueue();

//void Insert(int Info, int priority);
//void Pop();
//void Show();
//void isEmpty();
//Node* getHighestPriority();

PriorityQueue::PriorityQueue() : head(nullptr) {}

PriorityQueue::~PriorityQueue()
{
    if (head)
    {
        Node* temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
}

void PriorityQueue::Insert(int Info, int priority)
{
    Node *temp, *quickNode;
    temp = new Node;
    temp->info = Info;
    temp->priority = priority;
    if (!head || priority < head->priority)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        quickNode = head;
        while (quickNode->next && quickNode->next->priority <= priority)
            quickNode = quickNode->next;
        temp->next = quickNode->next;
        quickNode->next = temp;
    }
}

void PriorityQueue::Pop()
{
    Node *temp;
    if (!head) std::cout << "Empty\n";
    else
    {
        temp = head;
        std::cout << "Node info -> " << temp->info << std::endl;
        head = head->next;
        delete temp;
    }
}

int PriorityQueue::getHighestPriority() {return head->info;}

bool PriorityQueue::isEmpty() {return (head) ? false : true;}

void PriorityQueue::Show()
{
    Node* temp;
    temp = head;
    if (!temp) {std::cout <<"Empty\n";}
    else
    {
        while (temp)
        {
            std::cout << "Priority = "<<temp->priority << "\tInfo = " << temp->info << std::endl;
            temp=temp->next;
        }
    }
}
