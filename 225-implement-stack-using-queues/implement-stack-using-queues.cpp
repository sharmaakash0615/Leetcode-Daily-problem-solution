#include<bits/stdc++.h>
class MyStack {
public:

  queue<int>q1; 
  queue<int>q2; 
    MyStack() {
    
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() 
    {
    int len1=q1.size();
    for(int i=0;i<len1-1;i++)
    {
        int y=q1.front();
        q2.push(y);
        q1.pop();
    }
    int z=q1.front();
    q1.pop();

     int len2=q2.size();
     for(int i=0;i<len2;i++)
    {
        int y=q2.front();
        q1.push(y);
        q2.pop();
    }

    return z;
    }
    
    int top()
     {
    int len1=q1.size();
    for(int i=0;i<len1-1;i++)
    {
        int y=q1.front();
        q2.push(y);
        q1.pop();
    }
    int z=q1.front();
    q1.pop();
    q2.push(z);
     int len2=q2.size();
     for(int i=0;i<len2;i++)
    {
        int y=q2.front();
        q1.push(y);
        q2.pop();
    }

    return z;
        
    }
    
    bool empty() {
      if(q1.empty()) return true;
      else return false; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */