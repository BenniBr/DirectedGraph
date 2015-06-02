/* 
 * File:   edge.h
 * Author: Benjamin
 *
 * Created on 18. Mai 2015, 17:05
 */

#ifndef EDGE_H
#define	EDGE_H
#include "node.h"

class edge {
    //INFO:
    //NEW: Source und Target Nodes werden durch Edges erweitert
    //DELETE: Edge wird aus Source und Target entfernt
public:
    edge(node* source, node* target, float weight);
    virtual ~edge();
    float getWeight();
    void setWeight(float weight);
    node* getTarget();
    void setTarget(node* target);
    node* getSource();
    void setSource(node* source);
    
private:
    node* source;
    node* target;
    float weight;

};

#endif	/* EDGE_H */

