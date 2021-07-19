#include<bits/stdc++.h>
using namespace std;

bool anagram(string str1,string str2){
    
    if(str1.size()!=str2.size())
        return false;
    unordered_map<char,int>ump;
    
    for(int i=0;i<str1.size();i++){
        ump[str1[i]]++;
    } 
    
    for(auto u:ump){
        cout<<u.first<<" "<<u.second<<endl;
    }
    
    for(int i=0;i<str2.size();i++){
        if((ump.find(str2[i])!=ump.end()) &&ump[str2[i]]>0)
            ump[str2[i]]--;
        else
            return false;
    }
    return true;
}

int main()
    {
        string str1 = "aakash";
        string str2 = "kashaa";
        if(anagram(str1,str2)==true)
            cout<<"true";
        else
            cout<<"false";
        return 0;
    }
