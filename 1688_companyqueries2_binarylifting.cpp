#include <bits/stdc++.h>
using namespace std;

int parent[200005][20];
int level[200005];
vector<int> adj[200005];

int LCA(int a, int b){
    if(level[a] > level[b]) swap(a, b);
    
    for(int power=19;power>=0;power--){
        if((1<<power)<=level[b] - level[a]){
            b = parent[b][power];
        }
    }

    if(a==b) return a;    
    
    for(int power=19;power>=0;power--){
        if(parent[a][power]!=-1 && parent[b][power]!=-1 && parent[a][power]!=parent[b][power]){            
            a = parent[a][power];
            b = parent[b][power];            
        }
    }

    return parent[a][0];
}



void DFS(int u, int curr_level){
    level[u] = curr_level;
    for(int v:adj[u]){
        DFS(v, curr_level+1);
    }
}


int main(){
    int N, Q;
    cin>>N;cin>>Q;   

    memset(parent, -1, sizeof(parent)); 

    for(int i=2;i<=N;i++){
        int x;
        cin>>x;
        parent[i][0] = x;
        adj[x].push_back(i);
    }

    //lift
    for(int j=1;j<20;j++){
        for(int i=1;i<=N;i++){
            if(parent[i][j-1]!=-1) parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    //DFS
    DFS(1, 1);

    while(Q--){
        int a,b;
        cin>>a;cin>>b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}