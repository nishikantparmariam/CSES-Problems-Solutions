#include <bits/stdc++.h>
using namespace std;

int N;
long long int dp[125251][501];
long long int mod = 1000000007;

int main(){    
    cin>>N;
    int SUM = N*(N+1)/2;

    if(SUM&1) {
        cout << 0; 
        return 0;
    }

    SUM=SUM/2;
    

    for(int i=1;i<=N;i++){
        for(int sum=0;sum<=SUM;sum++){
            if(sum==0) dp[sum][i] = 0;
            else if(i==1) {
                if(sum==1) dp[sum][i] = 1;
                else dp[sum][i] = 0; 
            } else {
                dp[sum][i] = (dp[sum][i-1] + (sum-i>=0 ? ( sum-i==0 ? 1 : dp[sum-i][i-1] ) : 0))%mod;
            }
        }
    }
    

    cout << dp[SUM][N];

    return 0;
}


