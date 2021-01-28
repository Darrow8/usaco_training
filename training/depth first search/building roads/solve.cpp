#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
// https://cses.fi/problemset/task/1666
using namespace std;
// the following code is code from https://usaco.guide/silver/dfs that I am analyzing to understand, not my actual code

const int MN = 1e5+10;

int N, M, ans, rep[MN];
vector<int> adj_list[MN];
bool visited[MN];

void dfs(int node)
{
    visited[node] = true;
    for(int u:adj_list[node])
        if(!visited[u])
            dfs(u);
}
int count_components()
{
    int count=0;
    for(int i=1;i<=N;++i)
        if(!visited[i])
        {
            rep[count++]=i;
            dfs(i);
        }
    return count;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0,u,v;i<M;++i){
        scanf("%d%d", &u, &v);
        cout << u << " " << v << endl;
        cout << i << endl;
        adj_list[u].push_back(v);

        adj_list[v].push_back(u);
    }

    // for (int i = 0; i < MN; i++) {

    // }
        // ans = count_components();
        // printf("%d\n", ans-1);
        // for(int i=1;i<ans;++i)
        //     printf("%d %d\n", rep[i-1], rep[i]);
    return 0;
}