#include <bits/stdc++.h>
using namespace std;
void dfs(map<int, vector<int>> &m, int src, int par, vector<int> &ans)
{
    for (auto nb : m[src])
    {
        if (nb == par)
            continue;
        dfs(m, nb, src, ans);
        ans[src] = ans[src] + ans[nb];
    }
    ans[src]++;
}
int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
        m[i].push_back(x);
    }
    vector<int> ans(n + 1, 0);
    dfs(m, 1, 1, ans);
    for (int i = 1; i <= n; i++)
        cout << ans[i]-1 << " ";
    cout << endl;
    return 0;
}