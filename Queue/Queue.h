#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

template<typename T>
class Queue;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& d);

template<typename T>
class Queue
{
    public:
        Queue();
        ~Queue();

        void enqueue(const T& value);
        T    dequeue();

        inline T    peek() const;
        inline bool is_empty() const;
        inline std::size_t size() const;
        
        void clear();
        
        Queue& operator=(const Queue& q) = delete;
        Queue(const Queue& q) = delete;
    private:
        struct node
        {
            T value;
            node *next;
        } *head, *tail;
        
        std::size_t _size;

    friend std::ostream& operator<<<>(std::ostream& os, const Queue<T>& q);
};

template<typename T>
Queue<T>::Queue():head(nullptr), tail(nullptr), _size(0)
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
    
    if(is_empty())
    {
        head = tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail       = tmp;
    }
    
    ++_size;
}

template<typename T>
T Queue<T>::dequeue()
{
    if(is_empty())
    {
        throw "Queue is empty";
    }
    
    node *tmp  = head;
    int  value = head->value;

    head = head->next;
    
    delete tmp;
    
    --_size;
    
    return value;
}

template<typename T>
inline T Queue<T>::peek() const
{
    if(is_empty())
    {
        throw "Queue is empty";
    }
    
    return head->value;
}

template<typename T>
inline bool Queue<T>::is_empty() const
{
    return !head;
}

template<typename T>
void Queue<T>::clear()
{
    while(!is_empty())
    {
        node *tmp = head;
        head      = head->next;
        
        delete tmp;
    }
    
    head = nullptr;
}

template<typename T>
inline std::size_t Queue<T>::size() const
{
	return _size;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q)
{
    auto tmp = q.head;
    
    while(tmp)
    {
        os << tmp->value << " ";
        tmp = tmp->next;
    }
    
    return os;
}

#endif
