You are given an object street of class Street, representing a circular street, and a positive integer k, which serves as an upper bound for the number of houses on this street (i.e., the number of houses is at most k). Each house has a door that may initially be either open or closed, with the guarantee that at least one door is open.

You start positioned in front of one of these houses, and your goal is to determine the exact count of houses on the street.

// The Street class provides the following methods to assist in your task :



// void closeDoor() : Closes the door of the house you are currently facing.
// boolean isDoorOpen() : Returns true if the door of the house you are currently facing is open, otherwise returns false.
// void moveRight() : Moves to the next house in the circular street (i.e., after the last house, it wraps around to the first house).


// Since the street is circular, numbering the houses from 1 to n, moving right from house i leads to house i+1 for i < n, and from house n, it loops back to house 1.

// Return ans, which represents the total number of houses in the street.

/*
* Definition for a Street.
* class Street {
* public:
*     Street(vector<int> &doors);
*     void closeDoor();
*     bool isDoorOpen();
*     void moveRight();
* };
*/

class Solution {
public:
    int houseCount(Street *street, int k) {
        // Your Code goes here
        int idx =0;
       while(idx<=k){
            if(street->isDoorOpen()){
                break;
            }
            idx++;
            street->moveRight();
       } 
       street->moveRight();
       idx =1;
       int ans =0;
       while(idx<=k){
            if(street->isDoorOpen()){
                ans =idx;
                street->closeDoor();
            }
            idx++;
            street->moveRight();
       }
       return ans;
    }
};