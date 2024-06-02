#include <iostream>  
#include <vector>  
#include <queue>  
using namespace std;  

vector<int> bfs(const vector<vector<int>>& adj_list, int start, int target = -1)  
{  
    int n = adj_list.size();  
    vector<bool> visited(n, false);  // a boolean array to track visited vertices  
    vector<int> order;  // a vector to store the BFS traversal order  
  
    queue<int> q;  // a queue to hold the vertices to be visited  
    q.push(start);  // add the starting vertex to the queue  
    visited[start] = true;  // mark the starting vertex as visited  
    while (!q.empty())  
    {  
        int u = q.front();  // get the next vertex in the queue  
        q.pop();  // remove the vertex from the queue  
  
        order.push_back(u);  // add the vertex to the traversal order  
  
        // add all the unvisited neighbors of u to the queue  
        for (int v : adj_list[u])  
        {  
            if (!visited[v])  
            {  
                q.push(v);  
                visited[v] = true;  
            }  
        }  
    }  
    if (target != -1 && !visited[target])  
    {  
        // the target vertex was not found, return an empty vector  
        return {};  
    }  
    return order;  
}  
int main()  
{  
    // create an adjacency list for a graph with 5 vertices  
    vector<vector<int>> adj_list = {  
        {1, 2},  
        {0, 3, 4},  
        {0, 4},  
        {1, 4}, 
        {1, 2, 3} 
    };  
    // perform a BFS search starting from vertex 0  
    vector<int> order = bfs(adj_list, 0);  
    // print the traversal order  
    cout << "BFS traversal order: ";  
    for (int i : order)  
    {  
        cout << i << " ";  
    }  
    cout << endl;  
  
    return 0;  
}  
