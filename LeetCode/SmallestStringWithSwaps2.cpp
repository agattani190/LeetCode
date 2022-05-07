#include <queue>
#include <string>
#include <vector>
using namespace std;

void bfs(int u, vector<bool> &visited, vector<vector<int>> &graph,
         vector<int> &component);

// Time Complexity: O(m+nlogn)
// Space Complexity: O(m+n)
string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
  int n = s.size();
  int m = pairs.size();

  vector<vector<int>> graph(n, vector<int>());
  vector<int> component;
  for (int i = 0; i < m; i++) {
    graph[pairs[i][0]].push_back(pairs[i][1]);
    graph[pairs[i][1]].push_back(pairs[i][0]);
  }
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      component = {i};
      bfs(i, visited, graph, component);
      sort(component.begin(), component.end());
      string t = "";
      for (int j = 0; j < component.size(); j++) {
        t += s[component[j]];
      }
      sort(t.begin(), t.end());
      for (int j = 0; j < component.size(); j++) {
        s[component[j]] = t[j];
      }
    }
  }
  return s;
}

void bfs(int u, vector<bool> &visited, vector<vector<int>> &graph,
         vector<int> &component) {
  queue<int> q;
  q.push(u);
  int i;
  while (!q.empty()) {
    i = q.front();
    q.pop();
    for (int j = 0; j < graph[i].size(); j++) {
      if (!visited[graph[i][j]]) {
        visited[graph[i][j]] = true;
        component.push_back(graph[i][j]);
        q.push(graph[i][j]);
      }
    }
  }
}