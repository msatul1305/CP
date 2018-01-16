# Breadth-first Search

Time Complexity : **O(V + E)**

BFS : Lexicographically finds the path from source vertex to other vertices.

```cpp
vector< vector<int> > G;
int n, s;
vector<bool> vis(n + 1, false);
```
```cpp
void dfs(int s) {
	vis[s] = true;
	for(int i = 0; i < (int)G[s].size(); i++) if(!vis[G[s][i]]) {
		dfs(i);
	}
}
```

