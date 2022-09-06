// 987. Vertical Order Traversal of a Binary Tree
// Hard
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions 
// (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for 
// each column index starting from the leftmost column and ending on the rightmost column. 
// There may be multiple nodes in the same row and same column. In such a case, sort these 
// nodes by their values.
// Return the vertical order traversal of the binary tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /* The idea is to mark a node with its high difference and level, so we use level order, for each node
    mark hight differenc and lvl, we start with 0,0 from root, for left decrease hd by 1 and increase by 1
    ,for right increase both hd and lvlv, we can have vice versa to, the matter as if if do this then
    lets take for example the first test case, 3 hd 0 lvl 0, then right 20 hd=1,lvl=1,then we go to
    15, hd will be reduce  by1 as we left, hd=0, lvl=2, now 3 and 15 are of same col, this is how we will
    find the column element, with hteir hight difference, now you may ask why do we need the lvl, it is so
    that we can have sorted answer accordind to the leve, bcs column answer starts from top to bottom, so
    we use map instead of unordered_map, as map we can store according to hd and then by level*/
    void bfs(TreeNode* root,map<int,map<int,multiset<int>>> &mp){
        // treenode to travers, then storea lvl and height idfference of that node.
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto ele=q.front(); q.pop();
            TreeNode* node=ele.first;
            int lvl=ele.second.first;
            int height_diff=ele.second.second;
            //now we need to insert this into a contain that will sort it. accordingly to hd and then by lvl
            mp[height_diff][lvl].insert(node->val);
            // auto vc=mp[height_diff][lvl];
            // cout<<"hd:"<<height_diff<<" lvl"<<lvl<<"\n";
            // for(auto k: vc) cout<<k<<" ";
            // cout<<"\n";
            if(node->left!=nullptr) q.push({node->left,{lvl+1,height_diff-1}});
            if(node->right!=nullptr) q.push({node->right,{lvl+1,height_diff+1}});
        }
    }
    void dfs(TreeNode* root,map<int,map<int,multiset<int>>> &mp,int lvl,int hd){
        if(root==nullptr) return;
        mp[hd][lvl].insert(root->val);
        dfs(root->left,mp,lvl+1,hd-1);
        dfs(root->right,mp,lvl+1,hd+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        //to store nodes in sorted order of height difference and then by levle we use a map.
        map<int,map<int,multiset<int>>> mp;
        //havinng vector will not work, explained down below.
         // map<int,map<int,vector<int>>> mp;
        //bfs
        // bfs(root,mp);
        //dfs 
        dfs(root,mp,0,0);
        /*Now the map will look like this:
                hd:0 lvl0
                3 
                hd:-1 lvl1
                9 
                hd:1 lvl1
                20 
                hd:0 lvl2
                15 
                hd:2 lvl2
                7 
                ,you can see tha the map has key as hd, then each hd has another map as value, int that 
                value map, we have key as lvl and a vector as value, now each hd can have different lvl
                ,so each lvl will have it's own vector of elements that have that hd and that lvl, but
                we need answers in terms of hd not lvl,(we need lvl only for storing elements in sorted
                order from top to bottom and lvl is strat with 0 at top and increase as going down below,
                ,so we need to itersste each hd, the in each hd we need to iterate all lvl and append all
                elements vector into single vector ans insert it into result vector, fo that we have a
                syntax to append vector b to vector a, a.insert(starting iterator of a, from where we can 
                appended contents of vector b, then starting iterator of b ,ending iterator of b)
                so it is a.insert(a.end(),b.begin(),b.end())''
*/
        
        /* NOTE: ****All of the above approach is correct,what we need to understand is that we need to
        have our answers insorted order of height difference(lowest-[posibliy negative] from left to
        hghest-[positive] to right, take it as row or column , here im considering as row, then lvl
        from 0 at top to log n at bottom, so first we need to sort the element wrt hd, then wrt lvl, but
        when two or more node have same value, then we need to sort it in increasing order, but if we
        have vector we will need to explicitly sort it again, but of we have multiset, that set will take
        care of sorting if a nodes have same hd and lvl. for exapmle, we have two node 6 and 5 with 
        hd as 1 and lvl as 3, now 6 appears first while traveling level 3 so in vector it will be pushed
        first then 5, and we'll get 6,5. but wee need 5,6 , thats the reason for using multiset over vector
        first map sort hd ,second map sort lvl, then if both hd and lvl are same then to sort elements
        we have multi set.*/
        for(auto hd:mp){
            vector<int> column;
            for(auto lvl:hd.second){
                column.insert(column.end(),lvl.second.begin(),lvl.second.end());
                /*While using vector, sorting col will not work, as we are sorting col which is primarly 
                heght differece based,lets say we have two node 6 and 5, which have same lvl and hd,
                and thate hd doesnt interfere with other nodes,then sorting it will give 5,6 and work fine,
                but when lets say there are two node 4 and 2 with hd as 0 and lvl as 3, but there's root
                node 3 with hd as 0 and lvl as 0, here the answer should be {3,2,4}, but if we sort
                wrt hd, the it'll give {2,3,4}, but in order of lvl 3 apears first, sothis will not work,
                what we can do is sort vector present in lvl.second before appending it into column. 
                that'll work too, but sorting column vector will not work.*/
                // sort(column.begin(),column.end());
                //if you wanna use vector and  sort lvl.seond before appending it to column, heres how to do
                // sort(lvl.second.begin(),lvl.second.end());
                // column.insert(column.end(),lvl.second.begin(),lvl.second.end());  
            }
            res.push_back(column);
            
        }
        return res;
    }
};