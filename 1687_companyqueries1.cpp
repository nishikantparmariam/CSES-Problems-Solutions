#include <bits/stdc++.h>
using namespace std;

int N, Q;
int parent[200001][20];

int main(){    
    cin>>N;cin>>Q;
    memset(parent, -1, sizeof(parent));

    for(int i=2;i<=N;i++){
        int x;cin>>x;
        parent[i][0] = x;
    }

    for(int power=1;power<20;power++){
        for(int i=1;i<=N;i++){
            if(parent[i][power-1]!=-1) parent[i][power] =  parent[parent[i][power-1]][power-1];
        }
    }    

    while(Q--){
        int x;int k;
        cin>>x;cin>>k;
        int currPower = 0;        
        int res = x;

        while(k > 0){
            if(((k&1)==1)){
                res = parent[res][currPower];
                if(res==-1) break;
            }
            currPower++;
            k>>=1;
        }

        cout << res << endl;

    }

    return 0;
}