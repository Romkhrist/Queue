#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

template<typename T>
class Queue
{
    public:
        Queue();
        ~Queue();

        void enqueue(const T& value);
        T    dequeue();

        inline T    peek()  const;
        inline bool empty() const;
        
        void clear();
        Queue& operator=(const Queue& q) = delete;

    private:
        Queue(const Queue& q);

        struct node
        {
            T value;
            node *next;
        } *head, *tail;

    template<typename T1>
    friend std::ostream& operator<<(std::ostream& os, const Queue<T1>& queue);
};

template<typename T>
Queue<T>::Queue():head(nullptr), tail(nullptr)
{}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

template<typename T>
void Queue<T>::enqueue(const T& value)
{
    node *tmp  = new node;
    tmp->value = value;
    tmp->next  = nullptr;
    
    if(empty())
    {
        head = tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}

template<typename T>
T Queue<T>::dequeue()
{
    if(empty())
    {
        throw "Queue is empty";
    }
    
    node *tmp  = head;
    int  value = head->value;

    head = head->next;
    
    delete tmp;
    return value;
}

template<typename T>
inline T Queue<T>::peek() const
{
    if(empty())
    {
        throw "Queue is empty";
    }
    
    return head->value;
}

template<typename T>
inline bool Queue<T>::empty() const
{
    return !head;
}

template<typename T>
void Queue<T>::clear()
{
    while(!empty())
    {
        node *tmp = head;
        head      = head->next;
        
        delete tmp;
    }
    
    head = nullptr;
}

template<typename T1>
std::ostream& operator<<(std::ostream& os, const Queue<T1>& q)
{
    typename Queue<T1>::node *tmp = q.head;
    
    while(tmp)
    {
        os << tmp->value << " ";
        tmp = tmp->next;
    }
    
    return os;
}

#endif
