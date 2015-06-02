/* 
 * File:   node.h
 * Author: Benjamin
 *
 * Created on 18. Mai 2015, 17:02
 */

#ifndef NODE_H
#define	NODE_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>

//forward declaration
class edge;

class node {
    //INFO:
    //NEW: Node wird erstellt
    //DELETE: Edges werden entfernt
    //        Edges in Source und Target Nodes werden entfernt
public:
    node(std::string name);
    virtual ~node();
    void setName(std::string name);
    std::string getName();
    void cleanEdges(); //edges ohne target löschen
    void addInEdge(edge* toPush);
    edge* getInEdge(int number);
    int getInEdgeNumber();
    void addOutEdge(edge* toPush);
    edge* getOutEdge(int number);
    int getOutEdgeNumber();
    bool hasTarget(node* target);
    void setVisited(bool visited);
    bool isVisited();
    //int getPriority();
    void setPre(node* pre);
    node* getPre();
    void setDist(float dist);
    float getDist();
    
       
private:
    std::string name;
    std::vector <edge*> inEdgeVector;
    std::vector <edge*> outEdgeVector; 
    bool visited;
    float dist;     //momentan kürzeste Strecke, für pQueue --- für Dijkstra
    node* pre;     //Vorgänger Knoten --- für Dijkstra
    
    //pQueue
   // int priority;
};
/*
bool operator<(node &a, node  &b){
        return a.getPriority() < b.getPriority();
    }*/
#endif	/* NODE_H */

