#include<bits/stdc++.h>
class MyQueue {
     stack<int>s1;
     stack<int>s2;
public:
    MyQueue() {
       
    }
    
    void push(int x) {
     s1.push(x);
    }
    
    int pop() {
    if(s2.empty())
    {
       if(s1.empty()) return -1;
        while(!s1.empty())
        {
             int z=s1.top();
              s2.push(z);
              s1.pop();
        }
       int y=s2.top();
       s2.pop();
       return y;
       
    }
    else{
       int y=s2.top();
       s2.pop();
       return y;
    }     
    }
    
    int peek() {
     if(s2.empty())
    {
       if(s1.empty()) return -1;
        while(!s1.empty())
        {
              int z=s1.top();
              s2.push(z);
              s1.pop();
        }
       int y=s2.top();
       return y;
       
    }
    else{
       int y=s2.top();
         return y;
    }    
    }
    
    bool empty() {
       if(s1.empty()&& s2.empty()) return true;
       return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */