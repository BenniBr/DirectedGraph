#pragma once
#include "node.h"

using namespace std;

class Element{

public:
	Element();
	~Element();
	Element(int id, float priority, node* ptr);
	int id;
	float priority;
        node* ptr;
};
