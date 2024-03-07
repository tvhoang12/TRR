#include<bits/stdc++.h>
using namespace std;

stack <int> st;
int n, a[100][100];
bool traveled[100];
int before[100];
string str;

void DFS(int u) {
    st.push(u);
    traveled[u] = 1;
    while(st.size()) {
        int u = st.top();
        st.pop();
        for(int v = 1; v <= n; v++) {
            if(a[u][v] && !traveled[v]) {
                st.push(u);
                st.push(v);
                traveled[v] = 1;
                before[v] = u;
                break;
            }
        }
    }
    cout << endl;
}

void checkPath(int s, int t) {
    if(before[t] == 0) {
        cout << -1 << endl;
    }
    else {
        str = to_string(t) + ' ';
        int u = before[t];
        str += to_string(u) + ' ';
        while(u != s) {
            if(u == 0) {
                str = "-1";
                break;
            }
            u = before[u];
            str += to_string(u) + ' ';
        }
        cout << str << endl;
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
    memset(before, 0, sizeof(before));

    for(int i = 1; i <= n; i++) {
        if(!traveled[i])
            DFS(i);
    }

    int s, t;
    cin >> s >> t;

    checkPath(s, t);
}