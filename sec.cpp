#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

float find_dist(vector<vector<int>> a, vector<int> b)
{
    int n = a.size();
    int X = b[0], Y = b[1];

    vector<pii> v;
    for (int i = 0; i < n; i++) {
        v.pb(mp(a[i][0], a[i][1]));
    }
    sort(v.begin(), v.end());

    float ans = 0.0;
    ans += abs(v[0].ss - v[1].ss);
    int mx = 0;
    for (int i = 1; i < n; i += 3)
    {
        if (Y >= v[i].ss && v[i].ss >= mx)
        {
            ans += v[i + 1].ff - v[i].ff;
            mx = max(mx, v[i].ss);
        }
    }
    mx = 0;
    for (int i = 5; i < n; i += 4)
    {
        if (i + 1 < n && v[i + 1].ss >= mx && v[i + 1].ss >= Y)
        {
            ans += abs(v[i + 1].ss - v[i - 1].ss);
            mx = max(mx, v[i + 1].ss);
        }
    }
    mx = 0;
    for (int i = 5; i < n; i += 4)
    {
        if (i + 1 < n && v[i + 1].ss >= mx && v[i + 1].ss > v[i - 1].ss)
        {
            float x, y;
            x = float(v[i - 1].ff - X);
            y = float(v[i - 1].ss - Y);
            int distance = v[i].ff - v[i - 1].ff;
            float slope = (y / x);

            ans += tan(slope) * distance;
            mx = max(mx, v[i + 1].ss);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2, 0));
    vector<int> coordinates(2);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    cin >> coordinates[0] >> coordinates[1];
    float s = find_dist(v, coordinates);

    cout << fixed << setprecision(1) << s << endl;
}