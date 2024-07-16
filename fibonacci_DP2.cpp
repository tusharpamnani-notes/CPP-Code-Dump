// tabulation method

#include<bits/stdc++.h>
#include <vector>
using namespace std;

int sol(int n){

        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
                dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
        
}


int main()
{

        int n; cin >> n;
 
        cout << sol(n) << endl;

        return 0;

}
