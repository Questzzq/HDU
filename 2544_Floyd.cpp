#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    cout << "kdhck" << endl;
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

        // Floyd core
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(graph[i][j] > graph[i][k] + graph[k][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }

        cout << graph[1][n] << endl;
    }
    return 0;
}
