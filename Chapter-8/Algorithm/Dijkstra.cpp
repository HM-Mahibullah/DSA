// https://www.youtube.com/watch?v=bHolUy5sqq8

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int, int>> v[N];
long long dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstr(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> papa = pq.top();
        int pnode = papa.first;
        int pcost = papa.second;
        pq.pop();
        for (pair<int, int> u : v[pnode])
        {
            int cnode = u.first;
            int ccost = u.second;
            if (pcost + ccost < dis[cnode])
            {
                dis[cnode] = pcost + ccost;
                pq.push({cnode, dis[cnode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstr(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;   
    }
}
/*
Using the provided graph illustration, let's go through each iteration of Dijkstra's algorithm in the given


Input Graph
In the image, we have a graph with the following edges and weights:

0→1 with weight 2

0→2 with weight 6

1→3 with weight 5

2→3 with weight 8

3→4 with weight 10

3→5 with weight 15

4→6 with weight 2

5→6 with weight 6

Assuming node 0 is the source node, the goal is to find the shortest path from node 0 to all other nodes.

Execution Steps
Let’s go through each iteration of the algorithm, updating distances and exploring nodes.

Initialization:

dis[0] = 0 (distance to the source node is 0).
All other nodes are initialized to infinity (INT_MAX):

dis = [0, ∞, ∞, ∞, ∞, ∞, ∞]
Iteration 1:

Current Node: 0 (distance 0).
Explore Neighbors:

0→1 with weight 2:
New distance to node 1 =0+2=2.
Update dis[1] to 2 and push (1, 2) to the priority queue.

0→2 with weight 6:
New distance to node 2 =0+6=6.
Update dis[2] to 6 and push (2, 6) to the priority queue.
Updated Distances:

dis = [0, 2, 6, ∞, ∞, ∞, ∞]
Iteration 2:

Current Node: 1 (distance 2).
Explore Neighbors:

1→0 with weight 2 (already processed, skip).

1→3 with weight 5:
New distance to node 3 =2+5=7.
Update dis[3] to 7 and push (3, 7) to the priority queue.
Updated Distances:

dis = [0, 2, 6, 7, ∞, ∞, ∞]
Iteration 3:

Current Node: 2 (distance 6).
Explore Neighbors:

2→0 with weight 6 (already processed, skip).

2→3 with weight 8:
New distance to node 3 =6+8=14,
 which is greater than the current distance (7), so we skip updating dis[3].
Updated Distances:

dis = [0, 2, 6, 7, ∞, ∞, ∞]
Iteration 4:

Current Node: 3 (distance 7).
Explore Neighbors:

3→1 with weight 5 (already processed, skip).

3→2 with weight 8 (already processed, skip).

3→4 with weight 10:
New distance to node 4 =7+10=17.
Update dis[4] to 17 and push (4, 17) to the priority queue.

3→5 with weight 15:
New distance to node 5 =7+15=22.
Update dis[5] to 22 and push (5, 22) to the priority queue.
Updated Distances:

dis = [0, 2, 6, 7, 17, 22, ∞]
Iteration 5:

Current Node: 4 (distance 17).
Explore Neighbors:

4→3 with weight 10 (already processed, skip).

4→6 with weight 2:
New distance to node 6 =17+2=19.
Update dis[6] to 19 and push (6, 19) to the priority queue.
Updated Distances:

dis = [0, 2, 6, 7, 17, 22, 19]
Iteration 6:

Current Node: 6 (distance 19).
Explore Neighbors:

6→4 with weight 2 (already processed, skip).

6→5 with weight 6:
New distance to node 5 =19+6=25,
which is greater than the current distance (22), so we skip updating dis[5].
Updated Distances:

dis = [0, 2, 6, 7, 17, 22, 19]
Iteration 7:

Current Node: 5 (distance 22).
Explore Neighbors:

5→3 with weight 15 (already processed, skip).

5→6 with weight 6 (already processed, skip).
Updated Distances:

dis = [0, 2, 6, 7, 17, 22, 19]
Final Output
The shortest distances from the source node 0 to each node are:

0 -> 0
1 -> 2
2 -> 6
3 -> 7
4 -> 17
5 -> 22
6 -> 19
This output represents the minimum distance required to reach each node from the source (node 0) based on Dijkstra's algorithm.
*/
