#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    const int inf = 0x3f3f3f3f;
    while(scanf("%d %d", &n, &m) && n && m) {
        vector<vector<int> > graph(n + 1);
        for(int i = 0; i < graph.size(); i++)
            graph[i].resize(n + 1);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) graph[i][j] = 0;
                else graph[i][j] = inf;
            }
        }

        int a, b, tmp;
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &a, &b, &tmp);
            graph[a][b] = graph[b][a] = tmp;
        }

        vector<int> dis(n + 1);
        for(int i = 1; i <= n; i++)
            dis[i] = graph[1][i];

        vector<bool> book(n + 1);
        for(int i = 1; i <= n; i++)
            book[i] = false;
        book[1] = true;

        // Dijkstra  core
        int minTime = inf;
        int u, v;
        for(int i = 1; i <= n - 1; i++) {
            //找到离1号顶点最近的顶点
            minTime = inf;
            for(int j = 1; j <= n;j++) {
                if(book[j] == false && dis[j] < minTime) {
                    minTime = dis[j];
                    u = j;
                }
            }

            book[u] = true;
            for(v = 1; v <= n; v++) {
                if(graph[u][v] < inf) {
                    if(dis[v] > dis[u] + graph[u][v])
                        dis[v] = dis[u] + graph[u][v];
                }
            }
        }
        
        cout << dis[n] << endl;
    }
    return 0;
}
