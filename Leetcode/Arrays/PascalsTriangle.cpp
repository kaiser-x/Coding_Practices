```
CPP Code:

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        vector<int> prev;
        for(int i=0;i<n;i++){
            vector<int> list;
            list.push_back(1);
            for(int j=1;j<i;j++) 
                list.push_back(prev[j-1]+prev[j]);
            if(i!=0) 
                list.push_back(1);
            res.push_back(list);
            prev=list; 
        }
        return res;
    }
};
Java Code:

class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> al=new ArrayList<>();
        List<Integer> prev=new ArrayList<>();
        for(int i=0;i<n;i++){
            List<Integer> list=new ArrayList<>();
            list.add(1);
            for(int j=1;j<i;j++){
                list.add(prev.get(j-1)+prev.get(j));
            }
            if(i!=0) list.add(1);
            prev=list;
            al.add(list);
        }
        return al;
    }
}
```