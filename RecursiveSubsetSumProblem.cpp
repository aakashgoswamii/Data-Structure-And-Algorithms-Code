#include<bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>&set,int target,int n)
    {
        if(target==0)
            return true;
        if(target<0)
            return false;
        if(n<0)
            return false;
            
        return isSubset(set,target-set[n],n-1)|| isSubset(set,target,n-1);
    }
    
int main()
    {
        vector<int>set = {4,12,2,5};
        int target = 9;
        isSubset(set,target,set.size()-1)==true?cout<<"true":cout<<"false";
        return 0;
    }
