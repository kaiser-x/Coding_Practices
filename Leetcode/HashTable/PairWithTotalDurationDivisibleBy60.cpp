// 1010. Pairs of Songs With Total Durations Divisible by 60
// Medium

// 2896

// 111

// Add to List

// Share
// You are given a list of songs where the ith song has a duration of time[i] seconds.

// Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
//  Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

// Example 1:
// Input: time = [30,20,150,100,40]
// Output: 3
// Explanation: Three pairs have a total duration divisible by 60:
// (time[0] = 30, time[2] = 150): total duration 180
// (time[1] = 20, time[3] = 100): total duration 120
// (time[1] = 20, time[4] = 40): total duration 60
// Example 2:

// Input: time = [60,60,60]
// Output: 3
// Explanation: All three pairs have a total duration of 120, which is divisible by 60.

class Solution {
public:
  /*Logic -
Whenever we consider any number time[i] we can have 2 possibilities :

1) Number is divisible by 60.
2) Number is not divisible by 60.

We basically need to consider the time[i]%60 each time to know if it is==0 or not.
1) If modulo_val==0 we simply do count+=hash[modulo_val]
2) Else we need to find out how far is time[i] away from its next 60 multiple i.e 100 is 20 far from 120 which is a multiple of 60 so if we have a 20 alreay existing then (100,20) can make a valid pair.
3) To achieve this we first do time[i]%60 then subtract it from 60. Like 100 % 60=40 and 60-40=20. So count+=hash[20]

*/
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mp(60,0);
        for(auto &t:time) t=t%60;
        int count=0;
        for(int t:time){
          count+=(t==0)?mp[t]:mp[60-t];
          mp[t]++;
        }
      return count;
    }
};