/* Research queue which is implemented in C library at http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.
Using queue, complete function bool isBipartite(vector<vector<int>> graph) to determine if a graph is bipartite or not (the graph can be disconnected). In caat https://en.wikipedia.org/wiki/Bipartite_graph.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//---START---
bool isBipartite(vector<vector<int>> graph)
{
  int n = graph.size();
  vector<int> color(n, 0); // 0 = unassigned, 1 = color 1, 2 = color 2
  for (int i = 0; i < n; i++)
  { // iterate over all nodes in the graph
    if (color[i] == 0)
    {               // if the node has not been visited yet
      color[i] = 1; // set its color to 1
      queue<int> q;
      q.push(i); // enqueue the node
      while (!q.empty())
      {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node])
        { // iterate over the node's neighbors
          if (color[neighbor] == color[node])
          {               // if the neighbor has the same color as the node
            return false; // not bipartite
          }
          else if (color[neighbor] == 0)
          {                                    // if the neighbor has not been colored yet
            color[neighbor] = 3 - color[node]; // color the neighbor with the opposite color of the node
            q.push(neighbor);                  // enqueue the neighbor
          }
        }
      }
    }
  }
  return true; // bipartite
}
//---END---
int main()
{
  int G[6][6] = {{0, 1, 0, 0, 0, 1},
                 {1, 0, 1, 0, 0, 0},
                 {0, 1, 0, 1, 0, 0},
                 {0, 0, 1, 0, 1, 0},
                 {0, 0, 0, 1, 0, 1},
                 {1, 0, 0, 0, 1, 0}};
  int n = 6;

  vector<vector<int>> graph(n, vector<int>());
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (G[i][j])
        graph[i].push_back(j);
    }
  }

  isBipartite(graph) ? cout << "Yes" : cout << "No";
  return 0;
}
