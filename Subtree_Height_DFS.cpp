//// Global Variables///
vvi g;
vi vis;
//// DFS for subtree size /////
int dfs(int v){
    vis[v]=1;
    int subtree_size = 0; //**
    for(int u:g[v]){
        if(vis[u])continue;
        subtree_size += dfs(u); //**
    }
    subtree_size ++; //**
    return subtree_size;
}
 
