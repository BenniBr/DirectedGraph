/* 
 * File:   node.cpp
 * Author: Benjamin
 * 
 * Created on 18. Mai 2015, 17:02
 */

#include "node.h"
#include "edge.h"

node::node(std::string name){
    this->name=name;
    this->visited=false;
    this->pre=NULL;
    this->dist=0;
}

node::~node(){
    while(inEdgeVector.size()!=0){
         delete inEdgeVector[0]; //aus Vector raus + deletet Element
    }
    while(outEdgeVector.size()!=0){
         delete outEdgeVector[0];
    }
}

void node::setName(std::string name){
    this->name=name;
}
std::string node::getName(){
    return this->name;
}

void node::cleanEdges(){//edges ohne target löschen
    int size =inEdgeVector.size();
    for(int i=0; i<size;  i++){
        if(inEdgeVector[i]->getSource()==NULL){
            inEdgeVector.erase(inEdgeVector.begin()+i);
            i--;
            size=inEdgeVector.size();
        }
    }
    size = outEdgeVector.size();
    for(int i=0; i<size;  i++){
        if(outEdgeVector[i]->getTarget()==NULL){
            outEdgeVector.erase(outEdgeVector.begin()+i);
            i--;
            size=outEdgeVector.size();
        }
    }
}

edge* node::getInEdge(int number){
    if(number<=inEdgeVector.size() && inEdgeVector[number]!=NULL){
        return inEdgeVector[number];
    }else{
        return NULL;
    }
}

int node::getInEdgeNumber(){
    return inEdgeVector.size();
}

void node::addInEdge(edge* toPush){
    inEdgeVector.push_back(toPush);
}

edge* node::getOutEdge(int number){
    if(number<=outEdgeVector.size() && outEdgeVector[number]!=NULL){
        return outEdgeVector[number];
    }else{
        return NULL;
    }
}

int node::getOutEdgeNumber(){
    return outEdgeVector.size();
}

void node::addOutEdge(edge* toPush){
    outEdgeVector.push_back(toPush);
}

bool node::hasTarget(node* target){
    for(int i=0; i<outEdgeVector.size();  i++){
        if(outEdgeVector[i]->getTarget()==target){
            return true;
        }
    }
    return false;
}

void node::setVisited(bool visited){
    this->visited=visited;
}

bool node::isVisited(){
    return this->visited;
}

void node::setPre(node* pre){
    this->pre = pre;
}

node* node::getPre(){
    return this->pre;
}

void node::setDist(float dist){
    this->dist = dist;
}

float node::getDist(){
    return dist;
}
