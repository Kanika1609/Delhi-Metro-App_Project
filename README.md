# Delhi-Metro-App_Project
This C++ project implements Dijkstra's algorithm to calculate the shortest paths between stations on the Delhi Yellow Line Metro. The program allows users to find the minimum distance between two specified metro stations, making it a useful tool for commuters and tourists to plan their routes efficiently.


Features:-


Station Names: The program includes a list of 24 stations on the Delhi Yellow Line Metro.

Graph Representation: Distances between adjacent stations are represented in a 2D vector (graph).

Shortest Path Calculation: Uses Dijkstra's algorithm to find the shortest path between the source and destination stations.

User Input: Allows users to input the source and destination stations to calculate the shortest path.


Implementation Details:-


Graph Representation: The metro network is represented as a 2D vector where each cell contains the distance between two stations. INF (infinity) is used to represent the absence of a direct path.

Dijkstra's Algorithm: The algorithm is used to compute the shortest paths from the source station to all other stations. The minimum distance to the destination station is then printed.

Priority Queue: A set is used to implement a priority queue that helps in selecting the next station with the smallest known distance.
