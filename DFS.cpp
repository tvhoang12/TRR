#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream Mfile("data.in");

    int n;
    Mfile >> n;
    vector<vector<int>> adj(n + 1);
    stack<int> st;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    cin.ignore();
    
    for(int i = 1; i <= n; ++i) {
        string s;
        getline(Mfile, s);
        stringstream ss(s);
        int x; 
        vector<int> temp;

        while(ss >> x) {
            temp.push_back(x);
        }

        adj[i].insert(adj[i].end(),temp.begin(),temp.end());
    }

    st.push(1);
    vis[1] = 1;
    cout << 1 << " ";

    while (st.size())
        {
            int u = st.top();
            st.pop();

            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                if(!vis[v])
                {
                    cout << v << " ";
                    vis[v] = 1;
                    st.push(u);
                    st.push(v);
                    break;
                }
            }
        }
        cout << endl;
}