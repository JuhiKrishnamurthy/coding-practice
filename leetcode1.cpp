#include<iostream>
#include<cstring>
using namespace std;

struct val_and_next{
    int val;
    int next_used;
};
class Solution {
public:
    string real_str;
    string str;
    Solution()
    {
        real_str="";
        str=real_str;
    }
    Solution(string S)
    {
        real_str=S;
        str=real_str;
    }
    string remove_two()
    {
        int s_new = str.size()-2;
        string s;
        for(int i=2;i<s_new;i++)
        {
            s[i-2]=str[i];     
        }
        return s;
    }
    val_and_next find_val()
    {
        val_and_next ret_val;
        if((str[0]=='I')&&(str[1]!='V')&&(str[1]!='X'))
        {
            ret_val.val=1;
            ret_val.next_used=0;
        }
        else if((str[0]=='I')&&(str[1]=='V'))
        {
            ret_val.val=4;
            ret_val.next_used=1;
        }
        else if((str[0]=='I')&&(str[1]=='X'))
        {
            ret_val.val=9;
            ret_val.next_used=1;
        }
        else if((str[0]=='X')&&(str[1]!='L')&&(str[1]!='C'))
        {
            ret_val.val=10;
            ret_val.next_used=0;
        }
        else if((str[0]=='X')&&(str[1]=='L'))
        {
            ret_val.val=40;
            ret_val.next_used=1;
        }
        else if((str[0]=='X')&&(str[1]=='C'))
        {
            ret_val.val=90;
            ret_val.next_used=1;
        }
        else if((str[0]=='C')&&(str[1]!='D')&&(str[1]!='M'))
        {
            ret_val.val=100;
            ret_val.next_used=0;
        }
        else if((str[0]=='C')&&(str[1]=='D'))
        {
            ret_val.val=400;
            ret_val.next_used=1;
        }
        else if((str[0]=='C')&&(str[1]=='M'))
        {
            ret_val.val=900;
            ret_val.next_used=1;
        }
        else if(str[0]=='D')
        {
            ret_val.val=500;
            ret_val.next_used=0;
        }
        else if(str[0]=='M')
        {
            ret_val.val=1000;
            ret_val.next_used=0;
        }  
        return ret_val;
    }
    int romanToInt()
    {
        int len = str.size();
        int sum=0;
        while(str.size()>0)
        {
            val_and_next cur_val;
              cur_val=find_val();
            if(cur_val.next_used==1)
            {
                str=remove_two();
            }
            sum+=cur_val.val;
        }
        return sum;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution S(s);
    int value;
    value = S.romanToInt();
    cout<<value;
    return 0;
}