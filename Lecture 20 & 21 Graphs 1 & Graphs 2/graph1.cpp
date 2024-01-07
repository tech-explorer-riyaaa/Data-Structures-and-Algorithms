#include <iostream>
#include <queue>
using namespace std;

void print_DFS(int **edges, int n, int sv, bool* visited) {
    cout << sv << " ";
    visited[sv] = true;
    for(int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i]) {
                continue;
            }
            print_DFS(edges, n, i, visited);
        }
    }
    // can use map or array to store what all vertices we have already seen
}

void printBFS(int** edges, int n, int sv) {
    // recursion not used
    // queue is used.
    queue<int> pendingVertices; // seen but not printed yet
    bool * visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";
        for(int i = 0; i < n; i++) {
            if (i == currentVertex) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    // 2d array to store edges
    // dynamically create krenge
    int **edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++) {
        int f, s;  
        cin >> f >> s;
        edges[f][s] = 1;  
        edges[s][f] = 1;  
    }

    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    cout << "DFS order : ";
    print_DFS(edges, n, 0, visited); // 0 - starting vertex
    cout << endl;
    cout << "BFS order : ";
    printBFS(edges, n, 0);

    // to delete the memory
    delete [] visited;
    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}   