class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //this map ways is not working dont know why
        //i found out why,becuase there are let's say 3 distinct character is
        //pattern string,but there are 4 distinct characters in given string s
        //for example s = "cbaebabacd", p = "abc" ,,the op is[0,61]
        //at 1(op-0),2,3,4,5,6 window no problem, but 7th window where the op has to be
        //6 nothing is printed because,even thogh we are decreasing the mp[i],
        //the mp would be 1=1 b=1 c=1 e=0 d=0 and pmp a=1,b=1,c=1 ,and clearly 
        //mp !=pmp,so if mp[i]==0 we have to erase it.
       //  int n1=s.size();
       //  int k=p.size();
       //  int i=0,j=0;
       //  vector<int> res;
       // unordered_map<char,int>mp;
       // unordered_map<char,int> pmp;
       // for(int i=0;i<k;i++) pmp[p[i]]++;
       //  while(j<n1){
       //      mp[s[j]]++;
       //      if(j-i+1<k) j++;
       //      else if(j-i+1==k){
       //          if(mp==pmp) res.push_back(i);
       //          mp[s[i]]--;
       //  // corection line
       //  if(mp[s[i]]==0) mp.erase(s[i]);
       //          i++;
       //          j++;
       //      }
       //  }
       //  return res;
        
        //so we using a hash of vector
       //  int n1=s.size();
       //  int k=p.size();
       //  int i=0,j=0;
       //  vector<int> res;
       // // map<char,int>mp;
       // // map<char,int> pmp;
       //  vector<int> mp(26);
       //  vector<int> pmp(26);
       // for(int i=0;i<k;i++) pmp[p[i]-'a']++;
       //  while(j<n1){
       //      mp[s[j]-'a']++;
       //      if(j-i+1<k) j++;
       //      else if(j-i+1==k){
       //          if(mp==pmp) res.push_back(i);
       //          mp[s[i]-'a']--;
       //          i++;
       //          j++;
       //      }
       //  }
       //  return res;
  
    //now on to the next step using sliding window technique of aditya verma
    /* So what he meant is we need to create a map for the frequencies of chaar 
     in p string, then take count of distinct chars map is for individual freq and count is 
     umber of distint chars, at first calc part we check if thechar at j is present in the
     map,if it is then we reduce its freq ,we do this as tocross out the matched char, but if
     the freq of char at j becomes 0 ,then no. of ditinct char is reduced by 1 so we reduce
     count by 1 ,now regular j++ for fixed size SW, when we hit the window, we just need 
     to check if all distinct chars have been matched tha is, if count is equal to 0, if 
     it is then jus do what question asked, now to slide the window, always the arr[j] is
     always handled outside that particular else if, but arr[i] we need to take care of 
     it ,so if the char at i pos thats gonna leave the window was present in the freq map of p
     pattern string then we need to increase freq of that char by 1,and if it was 0 before
     increasing , that means no. of distinct char increased by 1 so count increased by 1
     and then slide window increement i and j*/
        int n1=s.size(),k=p.size();
        unordered_map<char,int> mp;
        for(auto i:p) mp[i]++;
        int count=mp.size();
        vector<int> res;
        int i=0,j=0;
        while(j<n1){
            //calculation part
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            //same part in all fixed size SW
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                //answer from calculation
                if(count==0) res.emplace_back(i);
                //sliding the window
                if(mp.find(s[i])!=mp.end()){
                   if( mp[s[i]]==0)
                    count++;
                     mp[s[i]]++;
                }
                i++;
                j++;
            }
        }
        return res;
        
    }
};