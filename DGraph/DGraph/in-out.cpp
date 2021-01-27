#include "in-out.h"
#include <iostream>
#include <fstream>

vector <vector<int>> getGrapgFromConsole(int n, int s, int f) 
{
    vector <vector <int> > a(n, vector <int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    return a;
}

void saveResultToFile( int s, int f, int res)
{
    ofstream fout;
    fout.open("output.txt");
    fout << "Старт: "<< s<<  " Финиш: "<<f<<" Результат: "<< res;
    fout.close();
}

void saveGraphviz(vector<vector<int>> g)
{
    ofstream out("outGraph.dot");
    out << "digraph {\n";
    for (size_t i = 0; i < g.size(); ++i) {
        out << "  " << i << ";\n";
    }
    for (size_t v = 0; v < g.size(); ++v) {
        for (auto u : g[v]) {
            out << "  " << v << " -> " << u << ";\n";
        }
    }
    out << "}\n";
}