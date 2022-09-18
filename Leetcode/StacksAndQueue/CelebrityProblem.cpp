// The Celebrity Problem
// MediumAccuracy: 39.46%Submissions: 100k+Points: 4
// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)
// Example 1:
// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity. 
// Example 2:
// Input:
// N = 2
// M[][] = {{0 1},
//          {1 0}}
// Output: -1
 public:
    bool knows(int i,int j,vector<vector<int> >& M){
        return M[i][j];
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++) st.push(i);
        while(st.size()>1){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(knows(a,b,M)){
                st.push(b);
            }else st.push(a);
        }
        int ele=st.top();st.pop();
        for(int i=0;i<n;i++) {
            if(M[ele][i]!=0) return -1;
            if(i!=ele&&M[i][ele]==0) return -1;
        }
        return ele;
        
    }