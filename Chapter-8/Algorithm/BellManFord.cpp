// Answer contains this link......
// https://www.scaler.in/bellmanford-algorithm/
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
};

const int N = 1e5;
long long dist[N];

int main()
{
    int node, e;
    cin >> node >> e;
    vector<Edge> list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list.push_back(Edge(a, b, c));
    }

    for (int i = 1; i <= node; i++) // 1 based index
    // for (int i = 0; i <node; i++)// 0 based index
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    for (int i = 1; i <= node - 1; i++)
    {
        for (Edge eg : list)
        {
            int u = eg.a;
            int v = eg.b;
            int w = eg.c;

            if (dist[u] < INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 1; i <= node; i++) // 1 based index ( input node numbres)
    // for (int i = 0; i <node; i++)// 0 based index
    {
        cout << i << "->" << dist[i] << endl;
    }
    bool flag = true;
    for (Edge eg : list)
    {
        int u = eg.a;
        int v = eg.b;
        int w = eg.c;

        if (dist[u] < INT_MAX && dist[u] + w < dist[v])
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "NOT cycle" << endl;
    else
        cout << "Cycle detected " << endl;
}

/*
Nodes: 1, 2, 3, 4, 5
Therefore, node = 5.
Edges: e = 7.
Edge from 1 to 2 with weight 6

Edge from 1 to 3 with weight 5

Edge from 2 to 4 with weight -1

Edge from 2 to 3 with weight -2

Edge from 3 to 4 with weight 4

Edge from 3 to 5 with weight 3

Edge from 4 to 5 with weight 3


          //Input//
5
7
1 2 6
1 3 5
2 4 -1
2 3 -2
3 4 4
3 5 3
4 5 3

     //output//
1->0
2->6
3->4
4->5
5->7
NOT cycle



*/
