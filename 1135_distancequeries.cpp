#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> adj[200005];
int parent[200005][20];
int level[200005];

void DFS(int u, int curr_parent){
    parent[u][0] = curr_parent;
    level[u] = (curr_parent!=-1 ? level[curr_parent] : 0) + 1;

    for(int v:adj[u]){
        if(v!=parent[u][0]){
            DFS(v, u);
        }
    }
}

void binary_lifting(){

    for(int j=1;j<20;j++){
        for(int i=0;i<N;i++){
            if(parent[i][j-1]!=-1) parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int find_lca(int a, int b){
    if(level[a] > level[b]) swap(a, b);

    for(int power = 19; power>=0;power--){
        if((1<<power)<=level[b]-level[a]){
            b = parent[b][power];
        }
    }

    if(a==b) return a;

    for(int power=19;power>=0;power--){
        if(parent[a][power]!=-1 && parent[a][power]!=parent[b][power]){
            a = parent[a][power];
            b = parent[b][power];
        }
    }

    return parent[a][0];
}

int main(){

    memset(parent, -1, sizeof(parent));    
    cin>>N;cin>>Q;    
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a;cin>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(0, -1);
    binary_lifting();

    while(Q--){
        int a, b;
        cin>>a;cin>>b;
        a--;b--;

        int lca_node = find_lca(a, b);

        cout << level[a]-level[lca_node]+level[b]-level[lca_node] << endl;

    }
    return 0;
}