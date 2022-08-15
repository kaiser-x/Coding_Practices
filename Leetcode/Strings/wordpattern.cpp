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

CPP Code:
class Solution {
public:
   /*The question is same as isomorphic strings, but there it was two string and we had
    to map char to a char, but here we have to map a char to a string, So it is the same
    as that question, we create a map, iterate, and check if key i.e char in pattern[i] is
    present or not, if it is present then we check if the value of that key in map is
    same as the string in s[i], if not then return false, else continue, if the key is not
    present then before we map the key with value, we have to check if the value is already
    present in the map mapped by some other key, if so ten we return false, else we map
    the key ro the value and continue,but that to check if map containsValue s[i] is not
    possible in cpp but it is possible in java, so to check containsValue, we maintain a
    set that tsores all the str[i] that has been mapped as a value to a key p[i]*/
    bool wordPattern(string p, string s) {
        
        unordered_map<char,string> mp;
        //Tokenising sentence to get words
        vector<string> str;
        //1st approach to tokenize, the default delimiter is white space " "
        stringstream ss(s);
        //The above method will wipe all the previous contents in stream and insert sentence
        //string s into the stream, if you want to add a string to stream without wiping
        //away previous contents use insert operator <<
        //for eg like this, ss<<s;
        string token;
        while(ss>>token){
            str.push_back(token);
        }
        //2nd approach, if you want to explicitly mention a delimiter like in splits method
        //in java
        // while(getline(ss,token," ")) str.push_back(token);
        if(str.size()!=p.size()) return false;
        int n=p.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            //if key is present check if it points to the same value as string str[i]
            if(mp.find(p[i])!=mp.end()){
                //if they are not same that means the key points to to different words
                //so return falsse
                if(mp[p[i]]!=str[i]) return false;
            }
            else{
                //If key is not present, then before mapping key and value, check if str[i]
                //is already present as a value to some other key or not.
                if(st.find(str[i])!=st.end()) return false;
                // mp.insert(pair<char,string>{p[i],str[i]});
                //If new key and new value then map them, and insert value into set to
                //check for containsValue in future iterations
                mp[p[i]]=str[i];
                st.insert(str[i]);
            }
        }
        return true;
        
        /*Another approach is to have two maps each for p and s whos key point to a unique
        number, so we are not mappin p[i] and str[i] directly but indirectly, so we check
        if key p[i] is present in map or not,if its present then we check if corresponding
        str[i] is present in the other map or not , if it is not present that mean, p[i] is
        already pointing to something else which is not str[i], so return false,otherwise
        check if both p[i] and str[i] are pointing to the same unique number or not,if they
        dont then return false., now if p[i] is not present in map, then before mapping
        p[i] and str[i] to a unique number, we have to check that str[i] is not already
        pointing to a number i.e it is not already a value to a different key.*/
        
        int n=p.size();
        stringstream ss(s);
        string token;
        vector<string> str;
        while(ss>>token) str.push_back(token);
        if(n!=str.size()) return false;
        unordered_map<char,int> pm;
        unordered_map<string,int> sm;
        for(int i=0;i<n;i++){
            if(pm.find(p[i])!=pm.end()){
                if(sm.find(str[i])==sm.end()) return false;
                if(pm[p[i]]!=sm[str[i]]) return false;
            }else{
                if(sm.find(str[i])!=sm.end()) return false;
                pm[p[i]]=sm[str[i]]=i;
            }
        }
        return true;
    }
};

Java Code:

class Solution {
    /*The question is same as isomorphic strings, but there it was two string and we had
    to map char to a char, but here we have to map a char to a string, So it is the same
    as that question, we create a map, iterate, and check if key i.e char in pattern[i] is
    present or not, if it is present then we check if the value of that key in map is
    same as the string in s[i], if not then return false, else continue, if the key is not
    present then before we map the key with value, we have to check if the value is already
    present in the map mapped by some other key, if so ten we return false, else we map
    the key ro the value and continue, then if iterated fully then return true*/
    public boolean wordPattern(String p, String s) {
        int n=p.length();
        String str[]=s.split(" ");
        int sSize=str.length;
        if(sSize!=n) return false;
        HashMap<Character,String> hm=new HashMap<>();
        for(int i=0;i<n;i++){
            if(hm.containsKey(p.charAt(i))){
                if(!(hm.get(p.charAt(i)).equals(str[i]))) return false;
            }else{
                if(hm.containsValue(str[i])) return false;
                hm.put(p.charAt(i),str[i]);
            }
        }
        return true;
    }
}



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

