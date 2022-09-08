#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int lengthOfLongestSubstring(string s) {
    vector<char> lsubstr;
    vector<int> counts;
    vector<char> letters_till_now;
    for (int i=0; i<s.size(); i++)
    {
        int ctr=1;
        char ch = s[i];
        int j = i+1;
        char chr = s[j];
        if(ch==chr)
        {
            counts.push_back(1);
            continue;
        }
        letters_till_now.clear();
        while((chr!=ch)&&(find(letters_till_now.begin(),letters_till_now.end(),chr)==letters_till_now.end()))
        {
            letters_till_now.push_back(chr);   
            ctr++;
            j++;
            chr = s[j];
        }
        counts.push_back(ctr);
    }
    int index=0;
    int max = counts[0];
    for(int i=0;i<counts.size();i++)
    {
        if(max<counts[i])
        {
            max=counts[i];
            index =i;
        }
    }
    for(int i= index;i<index+max;i++)
    {
        lsubstr.push_back(s[i]);
    }
    int size_of_substr=0;
    for(auto it=lsubstr.begin();it!=lsubstr.end(); it++)
    {
        cout<<*it;
        //cout<<size_of_substr<<"\n";
        //size_of_substr++;
    }
    cout<<"\n";
    return lsubstr.size();
}
int main()
{
    string s;
    s="abcabcbb";
    int res=lengthOfLongestSubstring(s);
    cout<<res;
    return 0;
}