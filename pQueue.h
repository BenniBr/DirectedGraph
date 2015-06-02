#pragma once
#include <string>
#include "Element.h"
#include "pQueue.h"
#include "node.h"
#include <iostream>

using namespace std;
#define AMOUNT 100  //Konstruktor
class pQueue{

public:
    int elements;
    Element* a[AMOUNT];
    int referenzfeld[AMOUNT];

    pQueue();
    ~pQueue();
    int getHeapPos(int id);
    void upHeap(int id);
    void downHeap(int id);
    void print();
    void printReferenzfeld();
    void Insert(Element* Element);
    int Size();
    void Delete(int id, bool refFeld);
    void Increase(int id, int d, bool refFeld);
    Element* minimum();
    Element* extractMin();
    void swap(int idOne, int idTwo);
    int min(int idOne, int idTwo);
    void DeleteElement(node* ptr);
    void update(node* ptr);
};
