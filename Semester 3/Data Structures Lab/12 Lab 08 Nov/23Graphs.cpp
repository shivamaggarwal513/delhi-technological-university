#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int vertices;
	list<int> *adjacency;

public:
	Graph(int v)
    {
        vertices = v;
        adjacency = new list<int>[v];
    }

	void addEdge(int v, int w)
    {
        adjacency[v].push_back(w);
    }

	void BFS(int s)
    {
	    bool *visited = new bool[vertices];
	    for(int i = 0; i < vertices; i++)
		    visited[i] = false;

	    list<int> queue;

	    visited[s] = true;
	    queue.push_back(s);

	    list<int>::iterator i;

	    while(!queue.empty())
	    {
		    s = queue.front();
		    cout << s << " -> ";
		    queue.pop_front();

		    for (i = adjacency[s].begin(); i != adjacency[s].end(); i++)
		    {
			    if (!visited[*i])
			    {
				    visited[*i] = true;
				    queue.push_back(*i);
			    }
		    }
	    }
        cout << "END \n";
    }

    void DFS(int s)
    {
        bool *visited = new bool[vertices];
	    for(int i = 0; i < vertices; i++)
		    visited[i] = false;

	    list<int> stack;

	    visited[s] = true;
	    stack.push_back(s);

	    list<int>::iterator i;

	    while(!stack.empty())
	    {
		    s = stack.back();
		    cout << s << " -> ";
		    stack.pop_back();

		    for (i = adjacency[s].begin(); i != adjacency[s].end(); i++)
		    {
			    if (!visited[*i])
			    {
				    visited[*i] = true;
				    stack.push_back(*i);
			    }
		    }
	    }
        cout << "END \n";
    }
};

int main()
{
	Graph x(5);
    x.addEdge(0, 3);
    x.addEdge(1, 3);
    x.addEdge(1, 4);
    x.addEdge(2, 4);
    x.addEdge(3, 2);
    x.addEdge(4, 0);

    /*    4
        / ^ ^
       /  |  \ 
      v   |   \ 
      0   1    2
      \   |   ^
       \  |  /
        v v / 
          3
    */

	cout << "Breadth first search starting from vertex 1: \n";
	x.BFS(1);

    cout << "Depth first search starting from vertex 1: \n";
    x.DFS(1);

	return 0;
}