#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int INF = 1e8;

typedef pair<int, int> pii;
typedef vector<int> Array;

class Edge {
public:
    int source, target, weight;
    Edge(int s, int t, int w) : source(s), target(t), weight(w) {}
};

class Graph {
private:
    int v;
    map<pii, int> weight;
public:
    vector<Edge> edges;
    // 0-based index
    Graph(int v) : v(v) {};

    void connect(int s, int t, int w) {
        edges.push_back(Edge(s, t, w));
        weight[make_pair(s, t)] = w;
    }

    int get(int s, int t) { return weight[make_pair(s, t)]; }

    int size() { return v; }
};

bool BellmanFord(Graph &graph, Array &distance, Array &predecessors, int source) {
    // Initialization
    for(int i = 0; i < graph.size(); i++) {
        distance[i] = INF;
        predecessors[i] = -1;
    }

    distance[source] = 0;

    // Bellman Steps
    for(int i = 0; i < graph.size() - 1; i++) {
        for(Edge edge : graph.edges) {
            // Relaxation
            int s = edge.source;
            int t = edge.target;
            if (distance[t] > distance[s] + graph.get(s, t)) {
                distance[t] = distance[s] + graph.get(s, t);
                predecessors[t] = s;
            }
        }
    }

    for(Edge edge : graph.edges) {
        // Relaxation
        int s = edge.source;
        int t = edge.target;
        if (distance[t] > distance[s] + graph.get(s, t)) {
            return false;
        }
    }

    return true;
}

int main() {
    int v, e;
    cin >> v >> e;

    Graph g(v);

    for(int i = 0; i < e; i++) {
        int s, t, w;
        cin >> s >> t >> w;

        g.connect(--s, --t, w);
    }

    int source, target;
    cin >> source >> target;
    source--; target--;

    Array distance(v);
    Array predecessors(v);

    if (BellmanFord(g, distance, predecessors, source)) {
        if (distance[target] == INF) {
            cout << "NO WAY" << endl;
        } else {
            cout << distance[target] << endl;
        }
    } else {
        cout << "MIA GETS RICH" << endl;
    }

    // for(auto x : distance) cout << x << " "; cout << endl;
    // for(auto x : predecessors) cout << x << " "; cout << endl;
}