#include <bits/stdc++.h>
using namespace std;

int N;
int coins[100];
bool dp[100001][100];


int main(){
    memset(dp, false, sizeof(dp));
    cin>>N;
    int max_sum = 0;
    for(int i=0;i<N;i++) cin>>coins[i], max_sum+=coins[i];

    for(int i=0;i<N;i++){
        for(int sum = 0;sum<=max_sum;sum++){
            if(sum==0 && i==0){
                dp[sum][i] = false;
            } else if(sum==0){
                dp[sum][i] = false;
            } else if(i==0){
                if(sum==coins[i]) dp[sum][i] = true;
            } else {
                dp[sum][i] = dp[sum][i-1];

                if(sum-coins[i] > 0){
                    dp[sum][i] = (dp[sum][i] | dp[sum-coins[i]][i-1]);
                } else if(sum-coins[i]==0){
                    dp[sum][i] = true;
                }
            }
        }        
    }

    vector<int> pos;

    for(int sum=1;sum<=max_sum;sum++){
        if(dp[sum][N-1]) pos.push_back(sum);
    }

    cout << pos.size() << endl;
    for(int x:pos) cout << x << " ";

    return 0;
}