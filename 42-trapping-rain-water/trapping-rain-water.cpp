vector<int>prifix_max(vector<int>& arr)
{
    
    
    int n=arr.size();
    vector<int>prifix(n);
    prifix[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prifix[i]=max(prifix[i-1],arr[i]);
    }
    return prifix;
}

vector<int>suffix_max(vector<int>& arr)
{
  
    
     int n=arr.size();
   vector<int>suffix(n);
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=max(suffix[i+1],arr[i]);
    }
    return suffix;
}

class Solution {
public:
    int trap(vector<int>& height) {
     int total=0;
      vector<int>prifixx_max=prifix_max(height);
      vector<int>suffixx_max=suffix_max(height);
      int n=height.size();
     for(int i=0;i<n;i++) 
     {
        int left_max=prifixx_max[i];
        int right_max=suffixx_max[i];
        if(height[i]<left_max && height[i]<right_max)
        {
            total+=(min(left_max,right_max)-height[i]);
        }
     }
     return total;    
    }
};