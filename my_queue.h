//Created by Hana Elazzazi 900222935
#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Q
{
private:
    queue<T> q;
public:
    Q()
    {
        
    }
    void push(T t)
    {
        q.push(t);
    }
    T pop()
    {
        T t = q.front();
        q.pop();
        return t;
    }
    bool empty()
    {
        return q.empty();
    }
};

#endif 

