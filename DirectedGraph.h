/* 
 * File:   DirectedGraph.h
 * Author: Benjamin
 *
 * Created on 18. Mai 2015, 20:07
 */

#ifndef DIRECTEDGRAPH_H
#define	DIRECTEDGRAPH_H
#include <string>
#include <fstream>
#include <iostream> 
#include <vector>
#include <sstream>
#include <map>

#include "edge.h"
#include "node.h"
#include "pQueue.h"

using namespace std;

class DirectedGraph {
public:
    DirectedGraph();
    virtual ~DirectedGraph();
    void loadMap(string map);
    void interactiveMode();
    void printInfo();
    void routeExists(string from, string to, int lenght);
    node* routeSearch(node* source, node* target);
    void dijkstra(string from);
    
private:
     std::map <string, node*> nodemap;
     void splitData(char* data);
     string addNodePrivate(string add);
     void addEdgePrivate(string source, string target, string token);
     void unVisitNodes();
     void unPreNodes();
};

#endif	/* DIRECTEDGRAPH_H */

