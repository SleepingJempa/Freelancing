#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
private:
public:
    int source;
    int target;
    int weight;
    Edge(int source, int target, int weight) : source(source), target(target), weight(weight) {};
};

class Graph
{
private:
    int v;
    int e;
    vector<Edge> edges;
public:
    Graph(int v, int e) : v(v), e(e) {};
    void connect(int s, int t, int  w) { edges.push_back(Edge(s, t, w)); }
    void sortEdges();
    Edge &getEdge(int i) { return edges[i]; }
};

void Graph::sortEdges() {
    sort(
        edges.begin(),
        edges.end(),
        [] (Edge const &a, Edge const &b) -> bool {
            return a.weight < b.weight;
        }
    );
}

int main() {
    int v, e;
    
    cout << "How many vertices the graph should have? ";
    cin >> v;

    cout << "How many edges the graph should have? ";
    cin >> e;

    cout << "Creating a graph object with " << v << " vertices and " << e << " edges.\n";
    Graph graph(v, e);

    int s, t, w;
    cout << "Now enter" << v << "pairs of s, t, w as source, target and weight to add a edge between them:\n";
    for(int i = 0; i < e; i++) {
        cout << "Enter the " << i << "-th edge end-points: (Format: s t w) ";
        cin >> s >> t >> w;
        s--; t--;
        graph.connect(s, t, w);
    }

    cout << "Sorting the edges of the graph using thir weight.\n";
    graph.sortEdges();

    cout << "Graph edges after sorting: \n";
    for(int i = 0; i < e; i++) {
        Edge edge = graph.getEdge(i);
        s = edge.source;
        t = edge.target;
        w = edge.weight;
        
        cout << "(" << s << " -- " << t << ") - weight = " << w << "\n";
    }

    vector<bool> marked(v, false);
    vector<bool> select(e, false);

    cout << "Starting the process of creating a MST...\n";

    for(int i = 0; i < e; i++) {
        cout << "Checking " << i << "-th edge.\n";
        Edge edge = graph.getEdge(i);
        s = edge.source;
        t = edge.target;
        w = edge.weight;

        if (!marked[s] || !marked[t]) {
            cout << "New unvisited end-point(s) found. Selecting this edge for MST.\n";
            marked[s] = true;
            marked[t] = true;
            select[i] = true;
        }
    }

    cout << "The MST (Jungle if it's not connect) is completed.\n";

    cout << "Result is as below (Edges):\n";
    for(int i = 0; i < e; i++) {
        if (select[i]) {
            Edge edge = graph.getEdge(i);
            s = edge.source;
            t = edge.target;
            w = edge.weight;
            cout << "(" << s << " -- " << t << ") - weight = " << w << "\n";
        }
    }
}