// 997. Find the Town Judge
// Easy
// In a town, there are n people labeled from 1 to n.
//  There is a rumor that one of these people is secretly 
//  the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town 
// judge.
// There is exactly one person that satisfies properties 1 
// and 2.
// You are given an array trust where trust[i] = [ai, bi] 
// representing that the person labeled ai trusts the person 
// labeled bi.

// Return the label of the town judge if the town judge 
// exists and can be identified, or return -1 otherwise.

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2
// Example 2:

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3


class Solution {
public:
  //so why this failed is because i thought i guy can only trust
  //one person ,but seems like they can trust multiple people
  //but they will definitely trust town judge
  //4
  // [[1,3],[1,4],[2,3],[2,4],[4,3]]
  //op is -1 Expected op is 3
    // int findJudge(int n, vector<vector<int>>& trust) {
    //    vector<int> hash(n+1,0);
    //   int size=trust.size();
    //     int pos,count=0;
    //     for(int i=0;i<size;i++)
    //         hash[trust[i][1]]++;
    //     for(int i=1;i<=n;i++)
    //     {
    //         if(hash[i]!=0) {
    //             pos=i;
    //             count++;
    //         }
    //     }
    //     if(count==1) return pos;
    //     return -1;
    // }
  /* So the correct logic is imagine this as graph indegree and outdegree
  of a node ,like a person who obviously trusts someone else is not the judge  but the judge has trust of all people except himself that is n-1 indegree and 0 outdegree for town judge and we need to find that value*/
  int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> hash(n+1,0);
       vector<int> in(n+1,0);
       vector<int> out(n+1,0);
       int size=trust.size();
       for(int i=0;i<size;i++){
          //like said earlier if someone trusts other so they are not
          //town judge ,this for outdgree calculation
          out[trust[i][0]]++;
         //indgree calculation
          in[trust[i][1]]++;
           }
       for(int i=1;i<=n;i++){
         //now if indgree is n-1 ,that means all people trust that guy
         //except himself and outdgree 0 means he doesn't trust anyone
         //so hes the town judge
          if(in[i]==n-1&&out[i]==0) return i;
        }
    return -1;
    }
  
};