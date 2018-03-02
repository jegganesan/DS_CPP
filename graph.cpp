#include<iostream>
#include<list>

using namespace std;

class graph {
    private:
	int vert;
	list<int> *adj;
    public:
	graph(int v) {
	    vert = v;
	    adj = new list<int>[v];
	}

	void add_adj(int v, int a) {
	    adj[v].push_back(a);
	}

	void bfs(int v) {
	    bool visited[vert];
	    for(int i = 0; i<vert; i++) {
		visited[i] = false;
	    }
	    list<int> q;
	    q.push_back(v);
	    cout<<"Displaying graph in BFS: ";
	    while(!q.empty()) {
		int s = q.front();
		cout<<s<<"  ";
		q.pop_front();
		visited[s] = true;
		for(list<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++) {
		    if(!visited[*it]) {
			q.push_back(*it);
		    }
		}
	    }
	    cout<<endl;
	}

	void dfsUtil(int v, bool visited[])
	{
	    cout<<v<<"  ";
	    list<int> q;
	    q.push_back(v);
	    visited[v] = true;
	    
	    for(list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
		if(!visited[*it]) {
	    	    dfsUtil(*it, visited);
		}
	    }
	}

	void dfs(int v) {
	    bool visited[v];
	    for(int i = 0; i<vert; i++) {
		visited[i] = false;
	    }
	    cout<<"Displaying graph in DFS: ";
	    dfsUtil(v, visited);
	    cout<<endl;
	}
};

int main()
{
    graph g(4);
    g.add_adj(0, 1);
    g.add_adj(0, 2);
    g.add_adj(1, 2);
    g.add_adj(2, 0);
    g.add_adj(2, 3);
    g.add_adj(3, 3);
    g.bfs(2);
    g.dfs(2);
    return 0;
}

