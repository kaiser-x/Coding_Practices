// 706. Design HashMap
// Easy
// Design a HashMap without using any built-in hash table libraries.
// Implement the MyHashMap class:
// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key 
// already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, or -1 if this map 
// contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains the 
// mapping for the key.
// Example 1:
// Input
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// Output
// [null, null, null, 1, -1, null, 1, null, -1]
// Explanation
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // The map is now [[1,1]]
// myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
// myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
// myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
// myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
// myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
// myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
// myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
// Constraints:
// 0 <= key, value <= 106
// At most 104 calls will be made to put, get, and remove.

class MyHashMap {
public:
    //This is the simple approach, but we can optimize it by having a hashing funtion and handling collisions
//     vector<int>vc;
//     MyHashMap() {
//         vc.resize(1e6+7,-1);
//     }
    
//     void put(int key, int value) {
//         vc[key]=value;
//     }
    
//     int get(int key) {
//         return vc[key];
//     }
    
//     void remove(int key) {
//         vc[key]=-1;
//     }
    /*Just like design hashet ,we have to create a vector of list,but instead of sinlg eint value we will have
    pair of int for key and value.*/
    vector<list<pair<int,int>>>mp;
    int size=1000;
    MyHashMap() {
        mp.resize(size);
    }
    int hash(int key){
        //return the index where the key can be inserted
        return key%size;
    }
    auto search(int key){
        int ind=hash(key);
        //in design hash we had a single int value, so we couldve iterated over the list at index ind and returned
        //the iterator where the key was or itll return iterator pointing to list end.
        //but here since we have a list of pair of int, we can search for the pair of int with find funtion,,but we 
        //only know key, and not value, so we have to use the for loop.
        //this search will return the iterator of the pair of int else return the end of the iterator of the lis
        //at index ind
        auto i=mp[ind].begin();
        for(;i!=mp[ind].end();i++){
            if(i->first==key) return i;
        }
        //if not found ,then i will point at end of the list.
        return i;
        
    }
    void put(int key, int value) {
        //to put element there are 2 ways, either we can search the key, if it exits then update the 
        //key's value, else we can pushback the key value pair.
        //ther way is to remove the pair and then pushback the given key value pair.ill follow latter method
        int ind=hash(key);
        remove(key);
        mp[ind].push_back({key,value});
    }
    
    int get(int key) {
        int ind=hash(key);
        auto i=search(key);
        if(i!=mp[ind].end()) return i->second;
        return -1;
    }
    
    void remove(int key) {
        int ind=hash(key);
        //we need to check if the returned iterator is end then we cant delete it,in that case we just have to return
        auto i=search(key);
        if(i==mp[ind].end()) return;
        mp[ind].erase(i);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */