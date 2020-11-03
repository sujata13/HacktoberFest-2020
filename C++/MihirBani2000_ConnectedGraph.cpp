// C++ code to count the number of connected components in the given graph
#include <iostream>
#include <vector>
typedef long long int ll;
using namespace std;

ll vis[100005];
ll count = 0;

// Function to perform Depth-First-Search on the graph
void dfs(ll num, vector<ll> matrix[])
{
    vis[num] = 1;
    for (ll i = 0; i < matrix[num].size(); i++)
    {
        ll child = matrix[num][i];
        if (vis[child])
            continue;
        // cout<<"visited:"<<child;
        dfs(child, matrix);
    }
}

int main()
{
    count = 0;
    vector<ll> matrix[100005];
    ll n, m;
    cout << "\nEnter no of vertices: ";
    cin >> n;
    cout << "\nEnter no of edges: ";
    cin >> m;
    for (ll i = 0; i < n + 1; i++)
        vis[i] = 0;

    cout << "Enter the adjacent vertices: for eg if vertex 1 and 2 are adjacent and vertex 2 and 3 are adjacent\n";
    cout << "You enter - \n 1 2\n 2 3\n and so on\n Enter now:\n";
    for (ll i = 0; i < m; ++i)
    {
        ll a, b;
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, matrix);
        }
    }

    cout << "\nThe number of connected components are: " << count << "\n";

    return 0;
}