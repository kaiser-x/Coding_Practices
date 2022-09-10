// 705. Design HashSet
// Easy
// Design a HashSet without using any built-in hash table libraries.
// Implement MyHashSet class:
// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the 
// HashSet, do nothing.
// Example 1:
// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]
// Explanation
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // return True
// myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // return False, (already removed)
// Constraints:
// 0 <= key <= 106
// At most 104 calls will be made to add, remove, and contains.

class MyHashSet {
public:
    //The idea is simple create a vector of the size given in constraints,here its given 10^6, but as we know at max
    //an array can have 10^6 size  inside main function or function and 10^7 size when declared globally. So if
    //the constraints are increased it will lead to bottle neck, memory and runtime we also be high.
//     vector<int> mp=std::vector<int>(1e6+1,0);
//     MyHashSet() {
        
//     }
    
//     void add(int key) {
//         mp[key]=1;
//     }
    
//     void remove(int key) {
//         mp[key]=0;
//     }
    
//     bool contains(int key) {
//         return mp[key];
//     }
    //so instead of having vector of this size, we can reduce the size to a optimal length, then wwe can make use of
    //hash funtion that will give us the best index to store the value in, but as we know hashing may have collisions
    //so how are we gonna take care of the collisions, so I remeber studying about this in clg, there we used a
    //linked list to store the value inserted at a index. But we can make use of stl instead of implementiing
    //the whole linked list. So lets make use of list and a hash function.
    //so at each index we can have a list of int
    vector<list<int>> mp;
    //now as we are handling collisions and bottleneck when input range is increased, if we have 1e6+1 size then
    //the time taken will be high, instead we can reduce it to a optimal size in order to let the collisions be 
    //handled.
    // int size=1e6+1;
    int size=100;
    MyHashSet() {
        mp.resize(size);
    }
    //Now to make a hash funtion we will use simpleset method of moduling with size %size method.
    //it will return the index where the value can be inserted.
    int hash(int key){
        return key%size;
    }
    //we can have a additional search funtion as we will need to search in multiple funtions given below.
    //it will return a iterator to the postion of element if present else the list end.
    //use list<int>::iterator or auto
    auto search(int key){
        int ind=hash(key);
        //we are getting the position of the key that is the inde of the given value to search if it is present
        //or not in that index's list.
        //it is not a problem even if the find return end iterator when the element is not found
        return find(mp[ind].begin(),mp[ind].end(),key);
    }
    void add(int key) {
        //we need to find the index at which key is present bcs then only we will be able to access
        //its mp[i].end(), to check if the given key can be inserted or ot, if it is already present then ignore
        //if not the insert he key in the list at that pos.
        int ind=hash(key);
        // instead of searching all the time we can just call contains
        // auto it=search(key);
        // if(it!=mp[ind].end()) return;
        // else mp[ind].push_back(key);
        if(!contains(key))
             mp[ind].push_back(key);
    }
    
    void remove(int key) {
        //we need to check if the element is present ot not before deleting it.
        int ind=hash(key);
        //if the key is not present then just simply retur.
        if(!contains(key)) return;
        auto it=search(key);
        if(it!=mp[ind].end()) mp[ind].erase(it);
    }
    
    bool contains(int key) {
        //search if the the key is present if true return true else false
        int ind=hash(key);
        auto it=search(key);
        if(it!=mp[ind].end())  return true;
        //else
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */