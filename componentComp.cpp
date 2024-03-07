#include<bits/stdc++.h>
using namespace std;

stack <int> st;
int n, a[100][100], cnt;
bool traveled[100];

void DFS(int u) {
    st.push(u);
    traveled[u] = true;
    while(st.size()) {
        int u = st.top();
        st.pop();
        for (int v = 1; v <= n; v++) {
            if (a[u][v] == 1 && traveled[v] == false) {
                st.push(u);
                st.push(v);
                traveled[v] = true;
                break;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    memset(traveled, 0, sizeof(traveled));
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (traveled[i] == false) {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << endl;
}