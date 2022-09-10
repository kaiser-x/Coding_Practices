// 1996. The Number of Weak Characters in the Game
// Medium
// You are playing a game that contains multiple characters, and each of the characters has 
// two main properties: attack and defense. You are given a 2D integer array properties where 
// properties[i] = [attacki, defensei] represents the properties of the ith character in the 
// game.
// A character is said to be weak if any other character has both attack and defense levels 
// strictly greater than this character's attack and defense levels. More formally, a 
// character i is said to be weak if there exists another character j where attackj > attacki 
// and defensej > defensei.
// Return the number of weak characters.
// Example 1:
// Input: properties = [[5,5],[6,3],[3,6]]
// Output: 0
// Explanation: No character has strictly greater attack and defense than the other.
// Example 2:
// Input: properties = [[2,2],[3,3]]
// Output: 1
// Explanation: The first character is weak because the second character 
// has a strictly greater attack and defense.
// Example 3:
// Input: properties = [[1,5],[10,4],[4,3]]
// Output: 1
// Explanation: The third character is weak because the second character 
// has a strictly greater attack and defense.
// Constraints:
// 2 <= properties.length <= 105
// properties[i].length == 2
// 1 <= attacki, defensei <= 105

class Solution {
public:
    /* So the main idea was to use a monotonic stack ,ie to get the nge to right, after sorting the array, but it'd 
    worked for a single element ,here we have two values attack ,so we sort array bassed on any one of the value,
    here we sort using attack value, bu theres a catch on how to handle if attack values are same explained below.
    So after sorting the array would have split into groups of same valued attack,now in each group attack would be
    same so there cant be any weak characters within thw group, but the attack value of the next group is greater
    than the prev grp, so there may be some defense value which are less than the next group defense values,
    so we need to find how many how many characters have defense value lesser than the next groups, now it became 
    similar to the nge to right question, bu the only thing is we should not check the defense value within the 
    group,but in next groups, so as for nge to right question, we will start from the end,and just like in nge ques
    we will check the encountered element is smaller than or equal to the stack top then pop stack, then insert
    the element in stack,but before that check if the stack is non empty, if it's not then count++, but what we
    are actually doing, we need to take the maximum defense val in last group then check how many characters in prev
    to the last group have defense value less than that max value,but at the same time we should not check with the
    elements within the group,but as the array is sorted then obviusly there may be some characters within the group
    that may have defense value less than the max, so for this we can do is have a map of vector, where attack val
    can be key the all defense value can be pushed to the value vector, then for each defense value we can check
    if next groups have any defesne value greater than currrent, as we need the sorted order of attack we will use 
    ordered map, the for each checking will be O(n*n), the moreover each operation on map take log(size of map),so
    this is not viable solution,now this is where the constion in sorting when attack have same value will helpe,
    imagine we are having problem only bcs the maximum val we are caluculating for the current group is doing
    comparisons within the group, and even if somehow we did something we keeping the prev attackvalue and skip
    comparison within group, but after reach the prev grp to curr grp, we need to compare the max defense val of 
    the next grp with this grp,but then again we need to pass the max value of the current grp to the prev grp
    of this after doing the comparisions of it's group,but all this will not help with traditional nge stack sol
    ,so for this what we do in sorting comp, when attack val are same we put the characters with the greter defense
    value at first, for eg {3,5} and {3,8}, the in sort {3,8} will be first then {3,5},how it works, lets start the
    maxval with intmin, then we start from the last charac, last char defense val be updated as the maxvalue now,we
    travers like in backwards, now update maxval whenever we found a defense value greater than maxval, and in this
    manner we will not increase count and only increase the max in ordered to get the maximum value from this grp
    then we move to the next group on the left, now againg itll go in mini to max as we traverse backwards, and 
    we have max of the prev grp, we need to check how many chars ar less than the curent max untill it encounters a
    defense val greter than maxval, So in short if we found a defense val less than maxval then we increement count
    ,if we found a dfense val greater tha maxval then we update max to defense val,so this is why we sort the way we
    sort.*/
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]<b[0]) return true;
        else if(b[0]<a[0]) return false;
        else if(a[0]==b[0]){
            if(a[1]>b[1]) return true;
        }
        //when attack are same,but second vec defense is small the first vec defense.
        return false;
    }
        
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        int n=props.size(),count=0;
        sort(props.begin(),props.end(),comp);
        // stack<int> st;
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty()&&st.top()<=props[i][1]) st.pop();
        //     if(!st.empty())  count++;
        //     st.push(props[i][1]);
        // }
        // return count;
        //But the above stack is unnecesary, bcs we just need to get max of one group and check it we the 
        //elemnst of next grp to its left. so we can just use a variable. In that stakcsolution we are just
        //inserting all elements and then poping them, but the only value needed is max val of a grp, so
        //all the insert and push operations are uneccesary
        int max_so_far=INT_MIN,defense_val;
        for(int i=n-1;i>=0;i--){
            defense_val=props[i][1];
            if(defense_val<max_so_far) count++;
            if(defense_val>max_so_far) max_so_far=defense_val;
        }
        return count;
    }
};