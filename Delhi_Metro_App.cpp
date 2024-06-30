#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits>
#include <string>

using namespace std;

#define INF numeric_limits<float>::max()

void dijkstra(vector<vector<float>>& graph, int source, const vector<string>& stations, int destination) {
    int num_stations = graph.size();
    vector<float> distance(num_stations, INF);
    vector<bool> visited(num_stations, false);

    distance[source] = 0;

    set<pair<float, int>> pq;
    pq.insert({0, source});

    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < num_stations; ++v) {
            if (graph[u][v] != INF && !visited[v]) {
                if (distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                    pq.insert({distance[v], v});
                }
            }
        }
    }

    cout << "Minimum distance from station " << stations[source] << " to " << stations[destination] << ": ";
    if (distance[destination] != INF)
        cout << distance[destination] << " km" << endl;
    else
        cout << "No path found" << endl;
}

int main() {
    // Example Delhi Yellow Line Metro stations
    vector<string> stations = {
        "Samaypur Badli", "Rohini Sector 18", "Haiderpur Badli Mor", "Jahangirpuri", "Adarsh Nagar",
        "Azadpur", "Model Town", "G.T.B. Nagar", "Vishwa Vidyalaya", "Vidhan Sabha", "Civil Lines",
        "Kashmere Gate", "Chandni Chowk", "Chawri Bazar", "New Delhi", "Rajiv Chowk", "Patel Chowk",
        "Central Secretariat", "Udyog Bhawan", "Race Course", "Jor Bagh", "INA", "AIIMS", "Green Park"
    };

    // Example distances between stations in kilometers
    vector<vector<float>> graph = {
        {0, 1.0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {1.0, 0, 1.2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, 1.2, 0, 1.0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, 1.0, 0, 1.1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 1.1, 0, 1.3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 1.3, 0, 1.5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, 1.5, 0, 1.4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, 1.4, 0, 1.2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, 1.2, 0, 1.0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 1.0, 0, 1.1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.1, 0, 1.2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.2, 0, 1.1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.1, 0, 1.2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.2, 0, 1.1, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.1, 0, 1.0, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.0, 0, 1.1, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.1, 0, 1.3, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.3, 0, 1.0, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.0, 0, 1.2, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.2, 0, 1.4, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.4, 0, 1.1, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.1, 0, 1.2, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.2, 0, 1.0},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1.0, 0}
    };

    int source_station;
    for (int i = 0; i < 24; i++) {
        cout << "Enter " << i << " for source station " << stations[i] << endl;
    }
    cout << endl;
    cout << "Enter source station number (0-23): ";
    cin >> source_station;

    int destination_station;
    for (int i = 0; i < 24; i++) {
        cout << "Enter " << i << " for destination station " << stations[i] << endl;
    }
    cout << endl;
    cout << "Enter destination station number (0-23): ";
    cin >> destination_station;

    // Perform Dijkstra's algorithm from source to destination
    dijkstra(graph, source_station, stations, destination_station);

    return 0;
}
