#include <bits/stdc++.h>
using namespace std;

int N, Q, euler_idx;
vector<int> euler;
vector<int> heights;
vector<int> first;
vector<vector<int>> children;
vector<vector<int>> dp;

void DFS(int u, int level){
    euler.push_back(u);
    heights.push_back(level);
    first[u] = euler_idx;
    euler_idx++;

    for(int v:children[u]){
        DFS(v, level+1);
        euler.push_back(u);
        heights.push_back(level);
        euler_idx++;
    }
}


void fill_dp(){
    for(int i=0;i<dp.size();i++){
        dp[i][0] = i;
    }

    for(int j=1;j<20;j++){
        for(int i=0; i+(1<<j)-1 < dp.size(); i++){

            if ( heights[dp[i][j-1]] <  heights[dp[i+(1<<(j-1))][j-1]] ) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = dp[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int get_min(int left, int right){
    int idx = -1;

    for(int power=19;power>=0;power--){
        if(((1<<power)<=right-left+1)){

            if ( idx==-1 || heights[dp[left][power]] < heights[idx] ) idx = dp[left][power];

            left = left + (1<<power);
        }
    }

    return idx;
}

int main(){    

    cin>>N;cin>>Q;

    children.resize(N);
    first.resize(N);

    for(int i=2;i<=N;i++){
        int x;cin>>x;        
        children[x-1].push_back(i-1);
    }

    euler_idx = 0;
    DFS(0, 1);

    dp.resize(euler.size(), vector<int>(20, -1));

    fill_dp();


    while(Q--){
        int a, b;
        cin>>a;cin>>b;
        a--;b--;

        int left = min(first[a], first[b]);
        int right = max(first[a], first[b]);        

        int res = get_min(left, right);        

        cout << euler[res]+1 << endl;
    }

    return 0;
}