// 692. Top K Frequent Words
// Medium
// Given an array of strings words and an integer k, return the k most frequent strings.
// Return the answer sorted by the frequency from highest to lowest. Sort the words 
// with the same frequency by their lexicographical order.
// Example 1:
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the 
// number of occurrence being 4, 3, 2 and 1 respectively.
// Constraints:
// 1 <= words.length <= 500
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]
// Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

/*This question is very important, bcs it made me realize of the priority queue works in cpp and how we can sort
priority qeueu using a comparator, and how one should add elelment to the PQ. So there are 3 approaches that we
are gonna mainly talk about, the first one is brute force, making use of hashmap and a vector,make the frequency
map of the given words, now traverse the map and insert those pair of word and it's freq into vector, now sort the
vector based on the freq, and if two have same freq then sort them lexicographically using the word,now make the
result vector ,traverse the sorted vector, and insert all the first k words into the resultant vector. 
second approach is , using a priority queue, then popping the top k elements , so we need the word with highest 
freq at the top of the PQ and so on as we reach the bottom, NOTE** The one thing we need to remember is that, PQ 
fills the bottom first and progress towards the top, so if we are comparing freq, and a has less freq that b
then we return true for a, bcs we need the smaller at the bottom and in PQ bottom is filled first, so if a < b
we return true for a unlike tht typical sort funtion where we will return true if a>b, so that we can get word
with high freq at starting of let's say a vector like in the case of first appraoch. Now how do pass comparatot
to PQ, remeber if we need a min heap we pass greater<> along with a vector and we all know defaultly PQ is
max heap, so it has a vector and a less<>(which are deafualt and even if we explictly mention them it is not
a problem), this less<> and greater<> are the comparator, so instead of this we make a class and in that class we
do operator overloading of the operator () using an operative funtions, so in our case we have pair<int,string> as
data type, so we have two of them in our parameter, now this has to be of reference type, bcs copying such complex
structure is not cheap,and we can use const too, so as we declared first id a<b we need to return true, so that it
is sent to the bottom, and then if freq of both a and b is same then the one which is longer lexicographically
need to be inserted first, in this way we will have the highes freq word at top and lexicographically small word
at top. Now third approach is to remove the element from top once we hit the window of k in PQ, so at the end
we will have top K freq Words in our PQ,But now this can get kinda confusing, the thing is at each time when
window of k is hit, we will remove the least freq number from our list,to do that what we need at top ??? Yes we
need the least occuring word and lexicographically larger word a top(when freq is same), so in our compare method
for our comparator, we will return true if freq of a > b bcs then a can be inserted at the bottom and progress to
the top,and when k window size is hit we pop the current leas occuring word from the PQ so pq.pop(),so we will
have the top K occuring words in our PQ, but we know if we directly pop and push them, then it'd be in reverse order
as our most occuring word would be at the bottom of the PQ, so we create the result vector of size K, and start
inserting all the popped word from PQ from end of the resultant array*/
//we need hashmap for all three approaches as we need to find the freq.
bool compare (const pair<int,string> &a,const pair<int,string> &b){
        if(a.first>b.first) return true;
        else if(b.first>a.first) return false;
        else if(a.second<b.second) return true;
        return false;
    }
class compare2{
    public:
    bool operator() (const pair<int,string> &a,const pair<int,string> &b){
        if(a.first<b.first) return true;
        else if(b.first<a.first) return false;
        else if(a.second>b.second) return true;
        return false;
    }
};
class compare3{
    public:
    bool operator() (const pair<int,string> &a,const pair<int,string> &b){
        if(a.first>b.first) return true;
        else if(b.first>a.first) return false;
        else if(a.second<b.second) return true;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        int n=words.size();
        for(auto word: words) mp[word]++;
        //FIrst appraoch
        // vector<pair<int,string>> res;
        // for(auto p:mp) res.push_back({p.second,p.first});
        // sort(res.begin(),res.end(),compare1);
        // vector<string>  ans;
        // for(int i=0;i<k;i++) ans.push_back(res[i].second);
        // return ans;
        //second approach
        // vector<string> ans;
        // priority_queue<pair<int,string>,vector<pair<int,string>>,compare2> pq;
        // for(auto word:mp){ 
        //     pq.push({word.second,word.first});
        // }
        // for(int i=0;i<k;i++) {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        //third approach
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare3> pq;
        for(auto p:mp){
            pq.push({p.second,p.first});
            if(pq.size()>k) pq.pop();
        }
        int m=k;
        vector<string> ans(m);
        while(!pq.empty()){
            ans[--m]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};