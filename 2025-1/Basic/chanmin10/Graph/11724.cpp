#include <iostream>
#include <queue>
using namespace std;

bool graph[1001][1001];

int main(){
    int N, M, u, v;
    int cnt = 0;
    queue<int> q;
    cin >> N >> M;
    while(M--){
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
    for(int i = 1; i <= N; i++){
        if(!graph[i][0]){
            cnt++;
            q.push(i);
            graph[i][0] = true;
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                for(int j = 1; j <= N; j++){
                    if(graph[tmp][j]){
                        q.push(j);
                        graph[j][0] = true;
                        graph[tmp][j] = false;
                        graph[j][tmp] = false;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
