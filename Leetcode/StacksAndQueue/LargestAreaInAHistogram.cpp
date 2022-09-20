// Maximum Rectangular Area in a Histogram
// MediumAccuracy: 47.42%Submissions: 77290Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.  
// Find the largest rectangular area possible in a given histogram where the largest 
// rectangle can be made of a number of contiguous bars. For simplicity, assume that 
// all bars have the same width and the width is 1 unit, there will be N bars height 
// of each bar will be given by the array arr.
// Example 1:
// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12
// Explanation: 
// Example 2:
// Input:
// N = 8
// arr[] = {7 2 8 9 1 3 6 5}
// Output: 16
// Explanation: Maximum size of the histogram 
// will be 8  and there will be 2 consecutive 
// histogram. And hence the area of the 
// histogram will be 8x2 = 16.
// Your Task:
// The task is to complete the function getMaxArea() which takes the array arr[] and 
// its size N as inputs and finds the largest rectangular area possible and returns the 
// answer.
// Expected Time Complxity : O(N)
// Expected Auxilliary Space : O(N)
// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ arr[i] ≤ 1012

vector<int> leftSmall(long long arr[],int &n){
        stack<int> st;
        vector<int> left(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> rightSmall(long long arr[],int &n){
        stack<int> st;
        vector<int> right(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) right[i]=st.top();
            st.push(i);
        }
        return right;
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long area=LONG_MIN;
        vector<int> left=leftSmall(arr,n);
        vector<int> right=rightSmall(arr,n);
        for(int i=0;i<n;i++){
            long long height=arr[i];
            long long breadth=right[i]-left[i]-1;
            area=max(area,(height*breadth));
        }
        return area;
    }