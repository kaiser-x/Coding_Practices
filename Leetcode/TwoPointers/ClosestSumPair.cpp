#include<bits/stdc++.h>
int closest3Sum(vector<int> &arr, int n, int target)
{
    // Write your code here
    sort(arr.begin(),arr.end());
    int mi=INT_MAX,ma=INT_MIN,sum=0,i=0;
    while(i<n-2){
        int l=i+1,h=n-1;
//         int t1=target-arr[i];
        while(l<h){
            sum=arr[i]+arr[l]+arr[h];
            if(sum==target) return sum;
           else if(sum>target) {mi=min(mi,sum); h--;}
            else if(sum<target) {ma=max(ma,sum);l++;}
        }
        i++;while(i<n-2&&arr[i]==arr[i-1]) i++;
    }
    return (abs(mi-target)<abs(ma-target))? mi:ma;
}
