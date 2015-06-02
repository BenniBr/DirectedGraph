/* 
 * File:   edge.cpp
 * Author: Benjamin
 * 
 * Created on 18. Mai 2015, 17:05
 */

#include "edge.h"

edge::edge(node* source, node* target, float weight){
    this->source=source;
    this->target=target;
    this->weight=weight;
    
    this->target->addInEdge(this);
    this->source->addOutEdge(this);
}

edge::~edge() {
    node* temp= target;
    this->target=NULL; //nur zeiger = NULL!!! 
    this->source->cleanEdges();
    this->source=NULL;
    temp->cleanEdges();
    temp=NULL;
}

float edge::getWeight(){
    return this->weight;
}

void edge::setWeight(float weight){
    this->weight=weight;
}

node* edge::getTarget(){
    return this->target;
}

void edge::setTarget(node* target){
    this->target=target;
}

node* edge::getSource(){
    return this->source;
}

void edge::setSource(node* source){
    this->source=source;
}