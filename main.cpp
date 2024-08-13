#include <iostream>
#include <string>
#include "GreaphAPI.h"

using namespace std;

int main()
{
    //Create a graph object
    AdjacencyList g;

    int n, p;
    string from, to;
    cin >> n;
    cin >> p;

    for(int i = 0;i < n; i++)
    {
        cin >> from;
        cin >> to;

        // insert into the graph
        g.insertEdge(from, to);
    }

    // calculate the rank of every page
    g.calcRank(p);

    // print the rank of the pages in alphabetical order
    g.PageRank(n);

    return 0;
}
