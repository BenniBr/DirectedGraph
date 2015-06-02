#include "Element.h"
#include "node.h"
using namespace std;

Element::Element(int id, float priority, node* ptr){
  this->id = id;
  this->priority = priority;
  this->ptr = ptr;
}
Element::~Element(){
}
