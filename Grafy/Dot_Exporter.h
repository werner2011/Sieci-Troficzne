#ifndef Dot_Exporter_H
#define Dot_Exporter_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std; 

class GraphVisualizer {
public:
    static void exportToDot(
        const string& filename,
        const string& graphName,
        const vector<string>& labels,
        const vector<vector<int>>& adjList,
        bool isDirected = true)
    {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "[Error] Nie mo¿na zapisaæ do pliku: " << filename << endl;
            return;
        }

        string connector = isDirected ? " -> " : " -- ";
        file << (isDirected ? "digraph " : "graph ") << graphName << " {\n";

        file << "    node [fontname=\"Arial\", shape=box, style=filled, fillcolor=\"#e1f5fe\"];\n";
        file << "    edge [color=\"#546e7a\", penwidth=1.2];\n";
        file << "    rankdir=LR;\n\n";

        for (size_t i = 0; i < labels.size(); ++i) {
            file << "    " << i << " [label=\"" << labels[i] << "\"];\n";
        }

        for (size_t u = 0; u < adjList.size(); ++u) {
            for (int v : adjList[u]) {
                if (!isDirected && u > (size_t)v) {
                    continue;
                }
                file << "    " << u << connector << v << ";\n";
            }
        }

        file << "}\n";
        file.close();
        cout << "[Visualizer] Wygenerowano plik: " << filename << endl;
    }
};

#endif#pragma once
