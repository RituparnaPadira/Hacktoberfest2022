//This Program Find the minimum number of throws required to win a given Snakes and Ladders board game.
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
 
// Total number of vertices in the graph
// 10 x 10 board
#define N 100
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<int> adjList[N + 1];
 
    // Constructor
    Graph(vector<Edge> const &edges)
    {
        // add edges to the graph
        for (Edge edge: edges)
        {
            // Please note that the graph is directed
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 
// A queue node
struct Node
{
    // stores number associated with graph node
    int ver;
 
    // `min_dist` stores the minimum distance of a node from the starting vertex
    int min_dist;
};
 
// Perform BFS on graph `g` starting from a given source vertex
int BFS(Graph const &g, int source)
{
    // create a queue for doing BFS
    queue<Node> q;
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N + 1);
 
    // mark the source vertex as discovered
    discovered[source] = true;
 
    // assign the minimum distance of the source vertex as 0 and
    // enqueue it
    Node node = { source, 0 };
    q.push(node);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        node = q.front();
        q.pop();
 
        // Stop BFS if the last node is reached
        if (node.ver == N) {
            return node.min_dist;
        }
 
        // do for every adjacent node of the current node
        for (int u: g.adjList[node.ver])
        {
            if (!discovered[u])
            {
                // mark it as discovered and enqueue it
                discovered[u] = true;
 
                // assign the minimum distance of the current node
                // one more than the minimum distance of the parent node
                Node n = {u, node.min_dist + 1};
                q.push(n);
            }
        }
    }
}
 
int findMinimumMoves(unordered_map<int, int> &ladder, unordered_map<int, int> &snake)
{
    // find all edges involved and store them in a vector
    vector<Edge> edges;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 6 && i + j <= N; j++)
        {
            int src = i;
 
            // update destination if there is any ladder
            // or snake from the current position.
            int dest = (ladder[i + j] || snake[i + j]) ?
                (ladder[i + j] + snake[i + j]) : (i + j);
 
            // add an edge from src to dest
            Edge e = { src, dest };
            edges.push_back(e);
        }
    }
 
    // construct a directed graph
    Graph g(edges);
 
    // Find the shortest path between 1 and 100 using BFS
    return BFS(g, 0);
}
 
int main()
{
    // snakes and ladders are represented using a map
    unordered_map<int, int> ladder, snake;
 
    // insert ladders into the map
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;
 
    // insert snakes into the map
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;
 
    cout << findMinimumMoves(ladder, snake);
 
    return 0;
}
