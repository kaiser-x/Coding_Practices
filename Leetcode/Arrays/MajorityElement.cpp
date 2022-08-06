#include <bits/stdc++.h> 
//NOTE: How many numbers can occur more than n/2 times in an array? 
//Only one. Either its there or not, that is number of majority element is
//either min:0 or max:1 .
// moore's algorithm, we see a element as the candidate and havee a count 
//variable that counts its freq, and iterate further and check if elements are 
//same as candidate or not, if they are then increase count if not the decreasse
//count, if count becomes 0 then take the incoming element as the candiate and
//continue the process,it works because if we mark all the place where the count 
//becomes 0, if we see those subarrays, the number of majority elements and 
//minority elements are same, so for example let;s say bcs of count 0 we have 
//4 subarrays, if in the question its given that there will be mandatory majority element then att the ened of the iteration the candidate will have the majority element, bcs 3 of 4 subarrays will have majority=minority, and if there
//is for sure a majority element then it must be the majority element in tha last
// subarray that is 4th subarray, but in question its given there can be 0
//majority element too, then at the end of the iteration we need to iterate
//arraay again and see if that candidate occurs more than n/2 times or not.
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    //you can set the first element as the candiate and iterate from 1 index,
    //and also have count set to 1, or have both as 0 and start from 0 index,
    //but what's important is that condition to check if count is 0 need to be
    //first code inside theloop for iteration, because we should consider the 
    //first element in the next subarray as the candidate and not the last 
    //element of the previous subarray(i.e the element where count became 0)
    int candidate=arr[0],count=1;
    for(int i=1;i<n;i++){
        if(count==0) candidate=arr[i];
        if(arr[i]==candidate) count++;
        else count--;
    }
    //in leetcode this thing is not required as it's mentioned that the majority
    //element is definitely present in the array, but in other places it might
    //not be, like codestudio. we have to check if candidate count > then n/2 or
    //not
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==candidate) count++;
    }
    if(count>(n/2)) return candidate;
    return -1;
}