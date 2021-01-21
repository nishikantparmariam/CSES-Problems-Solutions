#include <bits/stdc++.h>
using namespace std;
int dp[200001][20];
int arr[1000];
int N;

void fillDp(){
    for(int i=0;i<N;i++){
        dp[i][0] = arr[i];
    }

    for(int j=1;j<20;j++){
        for(int i=0;i+(1<<j)-1<N;i++){
            dp[i][j] = dp[i][j-1]+dp[i+(1<<(j-1))][j-1];
        }
    }
}

void sum(int i, int j){
    int res = 0;
    for(int power=19;power>=0;power--){
        if((1<<power)<=j-i+1){
            res+=dp[i][1<<power];
            i = i+(1<<power);
        }
    }
    return res;
}



// dp[i][j] = f (arr[i]...arr[i+2^j-1])

int main(){

    return 0;   
}