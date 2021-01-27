#include <vector>
using namespace std;

vector <vector<int>> getGrapgFromConsole(int n, int s, int f);
void saveResultToFile(int s, int f, int res);
int dijkstra(int n, int s, int f, vector<vector<int>> a);
void saveGraphviz(vector<vector<int>> g);