#include<iostream>
#include<vector>
using namespace std;
int hourglassSum(vector<vector<int> > arr) {
    int curhoursum=0;
    int maxhoursum=0;
    
    for(int i=1;i<arr.size()-1;i++)
    {
        for(int j=1;j<arr[i].size()-1;j++)
        {
            curhoursum=0;
            int d= arr[i][j];
            cout<<i<<" "<<j<<" "<<arr[i][j]<<"\n";
            curhoursum+=arr[i][j];
            cout<<i-1<<" "<<j-1<<" "<<arr[i-1][j-1]<<"\n";
            curhoursum+=arr[i-1][j-1];
            cout<<i-1<<" "<<j<<" "<<arr[i-1][j]<<"\n";
            curhoursum+=arr[i-1][j];
            cout<<i-1<<" "<<j+1<<" "<<arr[i-1][j+1]<<"\n";
            curhoursum+=arr[i-1][j+1];
            cout<<i+1<<" "<<j-1<<" "<<arr[i+1][j-1]<<"\n";
            curhoursum+=arr[i+1][j-1];
            cout<<i+1<<" "<<j<<" "<<arr[i+1][j]<<"\n";
            curhoursum+=arr[i+1][j];
            cout<<i+1<<" "<<j+1<<" "<<arr[i+1][j+1]<<"\n";
            curhoursum+=arr[i+1][j+1];

            cout<<curhoursum<<"\n"<<"\n";
            curhoursum=arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+d+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
            if(curhoursum>=maxhoursum)
            {
                maxhoursum=curhoursum;
            }    
        }
    }
    return maxhoursum;
}
int main()
{
    int num=0;
    vector<vector<int> > arr;
    for(int i=0;i<6;i++)
    {
        arr.push_back(vector<int>());
        for(int j=0;j<6;j++)
        {
            cin>>num;
            arr[i].push_back(num);
        }
    }
    int res=hourglassSum(arr);
    cout<<res<<"\n";
    return 0;
}