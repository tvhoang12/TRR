#include<bits/stdc++.h>
using namespace std;

stack <int> st;
int n, a[100][100];
bool traveled[100];

void DFS(int u) {
    st.push(u);
    traveled[u] = 1;
    cout << u << " ";
    while(st.size()) {
        int u = st.top();
        st.pop();
        for(int v = 1; v <= n; v++) {
            if(a[u][v] && !traveled[v]) {
                st.push(u);
                st.push(v);
                traveled[v] = 1;
                cout << v << " ";
                break;
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
    DFS(1);
    cout << endl;
}