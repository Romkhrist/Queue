#include <iostream>
#include "Queue.h"

int main()
{
    using std::cout;
    using std::endl;

    try
    {
        Queue<int> q;

        for(int i = 0; i < 9; i++)
        {
            q.enqueue(i);
        }

        cout << "current queue: "  << endl << q << endl << endl;

        q.dequeue();
        q.dequeue();

        cout << "queue after dequeueing two elements: " << endl << q << endl << endl;
        
        q.clear();
        
        cout << "queue after cleaning: " << endl << q << endl << endl;
        
        q.enqueue(777);
        cout << "queue after insertion of one element: " << q << endl;
    }
    catch(const char *msg)
    {
        cout << msg << endl;
    }
    
    return 0;
}
