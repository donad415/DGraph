#include "in-out.h"
#include <iostream>
#include <queue>

const int Inf = 30000;
using namespace std;

int main()
{
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<vector<int>> a = getGrapgFromConsole(n, s, f);
    saveGraphviz(a);
    int res = dijkstra(n, s, f, a);
    saveResultToFile(s, f, res);
    system("pause");
    return 0;

}

int dijkstra(int n, int s, int f, vector<vector<int>> a) {
    vector <int> d(n, Inf);
    d[s] = 0;
    priority_queue <pair <int, int > > q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int len = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > d[v]) continue;
        for (int i = 0; i < n; i++) {
            int to = i;
            int length = a[v][i];
            if (d[to] > d[v] + length && length >= 0) {
                d[to] = d[v] + length;
                q.push(make_pair(-d[to], to));
            }
        }
    }
    if (d[f] == Inf) return -1;
    else return d[f];
}
