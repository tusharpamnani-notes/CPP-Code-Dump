/*
  You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
  Each time, you can climb either one step or two steps. 
  You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
*/

// space complexity is optimized => O(1)


#include <bits/stdc++.h> 

#define MOD 1000000007

int countDistinctWays(int nStairs) {
    //  Write your code here
    if(nStairs == 0) return 1;
    if(nStairs == 1) return 1;


    int prev2 = 1;
    int prev1 = 1;
    int curr = 0;

    for(int i=2; i<= nStairs; i++){
        curr = (prev1 + prev2) %MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
    return  0;
}
