#include<bits/stdc++.h>
using namespace std;

queue<int> qu;
int n, a[100][100];
bool traveled[100];

void BFS(int u) {
    qu.push(u);
    traveled[u] = 1;
    while(qu.size()) {
        int u = qu.front();
        qu.pop();
        cout << u << " ";
        for(int v = 1; v <= n; v++) {
            if(a[u][v] && !traveled[v]) {
                qu.push(v);
                traveled[v] = 1;
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(traveled, 0, sizeof(traveled));
    BFS(1);
    cout << endl;
}