// // 290. Word Pattern
// // Easy
// // Given a pattern and a string s, find if s 
// // follows the same pattern.

// // Here follow means a full match, such that there 
// // is a bijection between a letter in pattern and 
// // a non-empty word in s.

// // Example 1:

// // Input: pattern = "abba", s = "dog cat cat dog"
// // Output: true
// // Example 2:

// // Input: pattern = "abba", s = "dog cat cat fish"
// // Output: false
// // Example 3:

// // Input: pattern = "aaaa", s = "dog cat cat dog"
// // Output: false

// // now the code is pretty simple we are pointing pattern to its
// // corresponding word in s, but problem come for input like
// // Your input
// // "abba"
// // "dog dog dog dog"
// // Output
// // false
// // Expected
// // false
// // a point to dog and so does b ,so to avoid it we put the words
// // from s in a set and if set already contains the word then 
// // a alphabet from pattern is already pointing throwthat word so we
// // return false;
// class Solution {
// public:
//     bool wordPattern(string p, string s) {
//         map<char,string> mp;
//         vector<string> str;
//         stringstream ss(s);
//         string t;
//         while(ss>>t){
//             str.push_back(t);
//         }
//         if(str.size()!=p.size()) return false;
//         int n=p.size();
//         set<string> st;
//         for(int i=0;i<n;i++){
//             if(mp.find(p[i])!=mp.end()){
//                 if(mp[p[i]]!=str[i]) return false;
//             }
//             else{
//                     if(st.find(str[i])!=st.end()) return false;
//                 // mp.insert(pair<char,string>{p[i],str[i]});
//                 mp[p[i]]=str[i];
//                 st.insert(str[i]);
//             }
//         }
//         return true;
//     }
// };
/* strtok example */
#include <bits/stdc++.h>
using namespace std;

// int main ()
// {
//   char str[] ="- This, a sample string.";
//   char * pch;
//   printf ("Splitting string \"%s\" into tokens:\n",str);
//   pch = strtok (str," ,.-");
//   vector<string>str;
//   while (pch != NULL)
//   {
//     // printf ("%s\n",pch);
//     string s(pch);
//     str.push_back(s);
//     s="";
//     pch = strtok (NULL, " ,.-");
//   }
//   return 0;
// }
int dfs1(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis,int n){
        if(i<0||i>=n||j<0||j>=n||vis[i][j]||grid[i][j]==-1) return INT_MIN;
        if(i==n-1&&j==n-1){
            int x=grid[i][j];
            grid[0][0]=0;
            grid[i][j]=0;
            if(x==1) return 1;
            else if(x==0) return 0;
        }
        vis[i][j]=true;
        int right=dfs1(grid,i,j+1,vis,n);
        int down=dfs1(grid,i+1,j,vis,n);
        vis[i][j]=false;
        int f=(grid[i][j]==1)?1:0;
        if(right>=down&&right>0){
            grid[i][j+1]=0;
        }else if(right<down&&down>0){
            grid[i+1][j]=0;
        }
        return f+max(right,down);
    }
     int dfs2(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis,int n){
        if(i<0||i>=n||j<0||j>=n||vis[i][j]||grid[i][j]==-1) return INT_MIN;
        if(i==0&&j==0){
            int x=grid[i][j];
            grid[i][j]=0;
            if(x==1) return 1;
            else if(x==0) return 0;
        }
        vis[i][j]=true;
        int left=dfs2(grid,i,j-1,vis,n);
        int up=dfs2(grid,i-1,j,vis,n);
        vis[i][j]=false;
        int f=(grid[i][j]==1)?1:0;
        if(left>=up&&left>0){
            grid[i][j+1]=0;
        }else if(left<up&&up>0){
            grid[i+1][j]=0;
        }
        return f+max(left,up);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        int res1=dfs1(grid,0,0,vis,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<< " ";
            cout<<endl;
        }
        int res2=dfs2(grid,0,0,vis,n);
        int one=(res1==INT_MIN)?0:res1;
        int two=(res2==INT_MIN)?0:res2;
        return one+two;
    }
int main(){
    vector<vector<int>>grid{{0,1,-1},{1,0,-1},{1,1,1}};
    cout<<cherryPickup(grid);
}

