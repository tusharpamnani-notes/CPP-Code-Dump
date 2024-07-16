/* 
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1


Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

"Indexing is start from 1"
*/


#include<bits/stdc++.h>
#include <vector>
using namespace std;

int sol(int n, vector<int> &dp){
        if(n<=1)
                return n;

        if(dp[n] != -1)
                return dp[n];
        
        dp[n] = sol(n-1, dp) + sol(n-2, dp);

        return dp[n]; 
}



int main()
{

        int n; cin >> n;

        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++)
                dp[i] = -1;
        
        cout << sol(n, dp) << endl;

        return 0;

}
