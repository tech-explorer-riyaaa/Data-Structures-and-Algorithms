#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
    int weight;
};

int findParent(int v, int* parent) {
    if(parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
}

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight; // to sort array in increasing order
} 

void kruskals(Edge* input, int n, int E) {
    // sort the input array in ascending order based on weight
    sort(input, input + E, compare); // generally only - in int and double starting and eding iterator pass krna hai
    // apna in-built mat use karo kaise decide krna hai - humare compare func ki help se decide karo humare array ko kaise sort krna hai

    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int count = 0; // no. of edges in MST
    int i = 0; // we're working on ith edge.

    while(count != n - 1) {
        Edge currentEdge = input[i];

        // check if we can add the currentEdge in MST or not.
        // to know topmost parent
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for(int i = 0; i < n - 1; i++) {
        if(output[i].source < output[i].dest)
            {cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;}
        else {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

}

int main() {
    int n, E;
    cin >> n >> E;
    Edge* input = new Edge[E];
    for(int i = 0; i < E; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    // input array ready.

    kruskals(input, n, E);
}