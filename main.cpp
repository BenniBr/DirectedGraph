/* 
 * File:   main.cpp
 * Author: Benjamin
 *
 * Created on 18. Mai 2015, 17:01
 */

#include <cstdlib>
#include "DirectedGraph.h"
#include "node.h"
#include "edge.h"
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    string map="OS_Map.txt";
    DirectedGraph* Os=new DirectedGraph();
    Os->loadMap(map);
    Os->interactiveMode();
//    Os->routeExists("Melle", "Osnabrueck", 3);
    //Os->dijkstra("Melle");
    //cout<<"Pfadsuche: "<<Os->hasPathWithLenght("Bissendorf", "Ladbergen", 4);
 
    return 0;
}

