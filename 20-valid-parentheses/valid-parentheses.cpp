#include<bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
         stack<int>st;
         int len=s.length();
         for(int i=0;i<len;i++)
          {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                char x=s[i];
                st.push(x);
            }
            else{
                 if(st.empty())
                  return false;

                if(st.top()=='(' && s[i]==')')
                {
                   st.pop();
                }
                else if(st.top()=='{' && s[i]=='}')
                {
                   st.pop();
                }
                else if(st.top()=='[' && s[i]==']')
                {
                   st.pop();
                }
                else{
                    return false;
                }
               
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};