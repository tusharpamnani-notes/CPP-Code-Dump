// space optimized => O(1)

#include<bits/stdc++.h>
#include <vector>
using namespace std;

int sol(int n){

        int prev2 = 0;
        int prev1 = 1;
        for (int i = 2; i <= n; i++) {
          int curr = prev1 + prev2;
          prev2 = prev1;
          prev1 = curr;
        }
        return prev1;
        
}



int main()
{

        int n; cin >> n;

        cout << sol(n) << endl;

        return 0;

}
