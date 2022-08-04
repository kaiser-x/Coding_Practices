#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    //this one is same as all too, imagine y xor k = x (given xor value),
    //then as for like sum ques, we would store freq of all the xor value
    //and check if there a xor value in map which is equal to k^x==y ,if it 
    //is then account all its occurence;
    int n=arr.size(),xo=0,count=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        xo^=arr[i];
        if(xo==x) count++;
        if(mp.find(xo^x)!=mp.end()) count+=mp[xo^x];
        mp[xo]++;
    }
    return count;
}