#include<unordered_map>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	vector<int> res;
    int n=arr.size();
    int i=0,j=0;
    int count=0;
    /* So the Idea is to maintain a map that stores freuqence of that k size window
    elements, we check if the current element is already present in the map or not,is its
    not then count inc, then we are incresing the freq of all curr elements, then while 
    answer derivation and sliding, we just push count,then reduce the freq of i element by
    1 and checking if that elements freq became 0 ,if so that means we need to reduce the 
    count,then slide the window*/
    unordered_map<int,int> mp;
    while(j<n){
        //here we are cheking if the arr[j] is present in map or not,
        //the mp[arr[j]]==0 , is because we only reduce the count of numbers
        //inserted into map and noot erase it,for eg if freq of 1 became 0 at one point,
        //after some time if it appears again in another window we need to consider it
        //as a distinct element in that window
        if(mp.find(arr[j])==mp.end()||mp[arr[j]]==0) count++;
        mp[arr[j]]++;
        if(j-i+1<k) j++;
        else if(j-i+1==k){
            res.push_back(count);
            mp[arr[i]]--;
            //if leaving element freq became 0,then no of distinct elements
            //is reduced by 1,and for checking of future element at j+1 pos
            //will be taken care by calculation part.
            if(mp[arr[i]]==0) count--;
            i++;j++;
        }
    }
    return res;
}
