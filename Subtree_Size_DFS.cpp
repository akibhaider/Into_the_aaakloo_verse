//// Global Variables///
vvi g;
vi vis;
//// DFS for subtree height /////
int dfs(int v){
    vis[v]=1;
    int subtree_height = 0; //**
    for(int u:g[v]){
        if(vis[u])continue;
        amax(subtree_height, dfs(u)); //**
    }
    subtree_height ++; //**
    return subtree_height;
}
