#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

class AdjacencyList {
private:
    map<string, vector<string>> list;   // to -> from   // this is the main graph
    map<string, int> outDegree;   // calc outDegree for each website, store here
    map<string, float> pageRank;   // for each website, calc the rank and store the value here!
    set<string> uniqueSites;   // stores all the uniqueSites

public:
    void PageRank(int n);
    void insertEdge(string from, string to);
    void calcRank(int p);
};

void AdjacencyList::PageRank(int n) {
    // prints the PageRank of all pages after p powerIterations in ascending
    // alphabetical order of webpages and rounding rank to two decimal places.

    // iterate over the set with a for loop and print(website name) along with the rank to 2 decimal places.
    for (auto itr = uniqueSites.begin(); itr != uniqueSites.end(); itr++) {
        // rounding to the nearest 2 decimal places!!!
        float newValue = round(pageRank[*itr] * 100) / 100;

        cout << *itr << " ";
        cout << fixed << setprecision(2) << newValue << endl;
    }
}

void AdjacencyList::insertEdge(string from, string to) {
    // add to list, set, & outDegree
    list[to].push_back(from);
    if (list.find(from) == list.end()) {
        list[from] = {};
    }

    // calc outDegree for each website. key: website name || value: everything that points to it.
    outDegree[from] += 1;
    if (outDegree.find(to) == outDegree.end()) {
        outDegree[to] = {};
    }

    // insert a unique website into the set.
    uniqueSites.insert(to);
    uniqueSites.insert(from);
}

void AdjacencyList::calcRank(int p) {
    // then do p calculations!
    map<string, float> storage;
    int i = 1;
    while (i <= p) {
        // do p power iterations, and store the data in the pageRank map
        if (i == 1) {
            for (auto it = list.begin(); it != list.end(); it++) {
                // add to the pageRank
                pageRank[it->first] = 1.0 / static_cast<float>(uniqueSites.size());
            }
        }
        else if (i > 1) {
            // 1. iterate through the graph.
            // 2. for each key, calculate the rank by iterating through the vector
            // 3. rank of key will be vector.size() calculations
            // 4. for each element in vector, add [previous rank/# of out-degrees] to total
            // 5. update the pageRank for that website in the map with the total value calculated.
            // 6. continue until for whole graph, and for p iterations.
            for (auto it = list.begin(); it != list.end(); it++) {

                float total = 0;

                for (int k = 0; k < it->second.size(); k++) {
                    total += pageRank[it->second.at(k)] / static_cast<float>(outDegree[it->second.at(k)]);
                }
                // cannot change the rank here. Need to store all the totals for the websites in something
                // then update the rank of every website.
                storage[it->first] = total;
            }
            // move data from storage, to pageRank
            for (auto iter = storage.begin(); iter != storage.end(); iter++) {
                pageRank[iter->first] = storage[iter->first];
            }
        }
        i += 1;
    }
}