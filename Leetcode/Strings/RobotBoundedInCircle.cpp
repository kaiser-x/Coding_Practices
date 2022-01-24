// 1041. Robot Bounded In Circle
// Medium

// On an infinite plane, a robot initially stands at (0, 0) 
// and faces north. Note that:

// The north direction is the positive direction of the y-axis.
// The south direction is the negative direction of the y-axis.
// The east direction is the positive direction of the x-axis.
// The west direction is the negative direction of the x-axis.
// The robot can receive one of three instructions:

// "G": go straight 1 unit.
// "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
// "R": turn 90 degrees to the right (i.e., clockwise direction).
// The robot performs the instructions given in order, 
// and repeats them forever.

// Return true if and only if there exists a circle in the 
// plane such that the robot never leaves the circle.

// Example 1:

// Input: instructions = "GGLLGG"
// Output: true
// Explanation: The robot is initially at (0, 0) facing the north direction.
// "G": move one step. Position: (0, 1). Direction: North.
// "G": move one step. Position: (0, 2). Direction: North.
// "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
// "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
// "G": move one step. Position: (0, 1). Direction: South.
// "G": move one step. Position: (0, 0). Direction: South.
// Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
// Based on that, we return true.
// Example 2:

// Input: instructions = "GG"
// Output: false
// Explanation: The robot is initially at (0, 0) facing the north direction.
// "G": move one step. Position: (0, 1). Direction: North.
// "G": move one step. Position: (0, 2). Direction: North.
// Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
// Based on that, we return false.
// Example 3:

// Input: instructions = "GL"
// Output: true
// Explanation: The robot is initially at (0, 0) facing the north direction.
// "G": move one step. Position: (0, 1). Direction: North.
// "L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
// "G": move one step. Position: (-1, 1). Direction: West.
// "L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
// "G": move one step. Position: (-1, 0). Direction: South.
// "L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
// "G": move one step. Position: (0, 0). Direction: East.
// "L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
// Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
// Based on that, we return true.
 
// Constraints:

// 1 <= instructions.length <= 100
// instructions[i] is 'G', 'L' or, 'R'.

class Solution {
public:
  //so the whole premise is that the robot starts at the origin
  //and follows set of instructions and we gotta see if there existes a
  //a circular plane that robot never leaves,the instruction string size
  //is greater than 1 always.
  //Now the directions like 0:North,1:West,2:South and 3:East
  // ..and the xi and yi array correspondingly change the the coordinates
    int xi[4]={0,-1,0,1};
    int yi[4]={1,0,-1,0};
    bool isRobotBounded(string ins) {
      //starting position that is origin
      int x=0,y=0;
      int n=ins.size();
      //the direction where robot is facing,as given in the question
      //at start it is facing up North thats why 0.
      int face=0;
      for(int i=0;i<n;i++){
        //if it go then just change the x and y value according to
        //the xi and yi direction array.
        if(ins[i]=='G'){
          x+=xi[face];
          y+=yi[face];
        }
        //if the instruction is to turn left i.e anticloack wise
        //and we have our directions number increasing anti clock wise,so
        //we just gotta increement face by 1,and the %4 is becausse after
        //3 that is east we want to come back to North and avoid array 
        //index overflow while accessing xi and yi dir arrays
        else if(ins[i]=='L'){
          face=(face+1)%4;
        }
        //now for right ,in question its given as clockwise,but as already
        //we have our directions number increasing anti clock wise,so you 
        //might think then lets decreement it,well for eg 0-1 is -1 and
        //-1 is not a n index,and also right from 0 we need 3 and it's
        // possible to use if and all and make it work,but the simplest
        //way is to add by 3,four direction you want to turn right
        //turn 3 times left ,voila you are facing the desired direction.
        else if(ins[i]=='R'){
          // face=(face+1)%4;
          // face=(face+1)%4;
          // face=(face+1)%4;
          face=(face+3)%4;
        }
      }
      //now if there's 0 net displacment then its true
      
      // if(x==0&&y==0) return true;
      
      //if there's non 0 net displacement ,but the direction is not north 
      //then return true,I am still not ablee to under why,like GG is false
      //but LGG is true,both are just going in their straight line
      //respectively,but why onlt north is returning false
      
      // if(face!=0) return true;
      
      //else return false
      
      // return false;
      
      //easy way
      return (x==0&&y==0||face!=0)    ;
  
    }
};