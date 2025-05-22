#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

stack<int> stc;
queue<int> q;
vector<int> v1[1001];

int main(){
    int N, M, V;
    cin >> N >> M >> V;
    while(M--){
        int a, b;
        cin >> a >> b;
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        sort(v1[i].begin(), v1[i].end(), greater<>());
    }

    //DFS
    bool vis[1001] = {};
    vis[V] = true;
    cout << V << ' ';
    for(auto e : v1[V])
        stc.push(e);
    while(!stc.empty()){
        int tmp = stc.top();
        stc.pop();
        if(vis[tmp])    continue;
        vis[tmp] = true;
        cout << tmp << ' ';
        for(auto e : v1[tmp])
            stc.push(e);
    }
    cout << '\n';

    //BFS
    for(int i = 1; i <= N; i++){
        sort(v1[i].begin(), v1[i].end());
    }
    fill(vis, vis+1001, 0);
    vis[V] = true;
    cout << V << ' ';
    for(auto e : v1[V]){
        if(!vis[e]){
            q.push(e);
            vis[e] = true;
        }
    }
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for(auto e : v1[tmp]){
            if(!vis[e]){
                q.push(e);
                vis[e] = true;
            }
        }
    }
    cout << '\n';
    return 0;
}
