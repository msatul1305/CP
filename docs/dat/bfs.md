# Breadth-first Search

Time Complexity : **O( V + E )**

BFS : At 0th step the starting node is on fire. At each step fire spreads to all the connected vertices.
```cpp
vector< vector<int> > G;
int n, s;
vector<bool> vis(n + 1, false);
queue<int> Q; Q.push(s);
vis[s] = true;
while(!q.empty()) {
	int f = q.front();
	for(int i = 0; i < (int)G[f].size(); i++) if(!vis[G[f][i]]){
		q.push(G[f][i]);
		vis[G[f][i]] = true;
	}
	q.pop();
}
```
