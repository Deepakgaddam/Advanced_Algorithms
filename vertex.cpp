#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Vertex;

struct CompareVertices {
    bool operator()(const Vertex& v1, const Vertex& v2) const {
        return v1.second > v2.second;
    }
};

vector<int> shortestPathDistances(const vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();

    vector<int> distances(numVertices, INT_MAX);
    distances[startVertex] = 0;

    priority_queue<Vertex, vector<Vertex>, CompareVertices> pq;
    pq.push(make_pair(startVertex, 0));

    while (!pq.empty()) {
        int currentVertex = pq.top().first;
        int currentDistance = pq.top().second;

        pq.pop();

        if (currentDistance > distances[currentVertex]) continue;

        for (int neighborVertex = 0; neighborVertex < numVertices; ++neighborVertex) {
            if (graph[currentVertex][neighborVertex] != INT_MAX) {
                int newDistance = currentDistance + graph[currentVertex][neighborVertex];

                if (newDistance < distances[neighborVertex]) {
                    distances[neighborVertex] = newDistance;
                    pq.push(make_pair(neighborVertex, newDistance));
                }
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> graph = {
        {INT_MAX, 4, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 1, 7},
        {INT_MAX, INT_MAX, INT_MAX, 2},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX}
    };

    int startVertex = 0;

    vector<int> distances = shortestPathDistances(graph, startVertex);

    cout << "Shortest distances from start vertex " << startVertex << ":" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
