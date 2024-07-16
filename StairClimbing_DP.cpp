/*
  You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
  Each time, you can climb either one step or two steps. 
  You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
*/


#include <bits/stdc++.h> 
#include <vector>

#define MOD 1000000007

int sol(int nStairs, int i, vector<int>& dp){
    if(i == nStairs) return 1;
    if(i > nStairs) return 0;


    if(dp[i] != -1) return dp[i];

    dp[i] = (sol(nStairs, i+1, dp) + sol(nStairs, i+2, dp)) % MOD;
    return dp[i];
}

int countDistinctWays(int nStairs) {
    //  Write your code here
    vector<int> dp(nStairs+1, -1);
    int res = sol(nStairs, 0, dp);
    return res;
}
