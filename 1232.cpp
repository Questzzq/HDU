#include <iostream>
using namespace std;

const int MAX = 1000;
int father[MAX];

int Find(int x) {
    if(father[x] == -1)
        return x;
    return father[x] = Find(father[x]);
}

void Union(int a, int b) {
    int fa = Find(a);
    int fb = Find(b);
    if(fa != fb)
        father[fa] = fb;
}

int main() {
    int n, m;
    while(cin >> n && n) {
        cin >> m;
        for(int i = 1; i <= n; i++)
            father[i] = -1;

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }

        int ans = 0;
        for(int i = 1; i<= n; i++) {
            if(father[i] == -1)
                ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
