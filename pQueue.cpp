#include "pQueue.h"

using namespace std;

pQueue::pQueue(){
  elements = 0;
  for(int i=0; i<AMOUNT; i++){
    a[i] = 0;
  }
}
pQueue::~pQueue(){
}

int pQueue::getHeapPos(int id){
  return referenzfeld[id];
}

void pQueue::upHeap(int id){
  int v = id / 2;

    if(v > 0 && this->a[id]->priority < this->a[v]->priority)
    {
        swap(id, v);
        upHeap(v);
    }
}

void pQueue::downHeap(int id){
    
    int smallest;
    int l = 2 * id;
    int r = 2 * id +1;

    if(l <= this->elements && (this->a[l]->priority < this->a[id]->priority))
    {
        smallest = l;
    }
    else
    {
        smallest = id;
    }

    if(r <= elements && (this->a[r]->priority < this->a[smallest]->priority))
    {
        smallest = r;
    }

    if(smallest != id)
    {
        swap(id, smallest);
        downHeap(smallest);
    }
    }
        
       /* if((id*2)<=elements){
            if(a[id*2]->priority < a[id*2+1]->priority){
                if(a[id]->priority < a[id*2]->priority){
                  return;
                }
                else{
                    leftSwap(id);
                }
            }
            else{
                if(a[id]->priority < a[id*2+1]->priority){
                  return;
                }
                else{
                    rightSwap(id);
                }
            }      
        }else{
            if(id*2==elements){
                if(a[id]->priority < a[id*2]->priority){
                  return;
                }
                else{
                  rightSwap(id);
                }
            }
        }
    }*/

void pQueue::swap(int idRoot, int idNext){
    Element* temp = a[idRoot];
    a[idRoot] = a[idNext];
    a[idNext] = temp;
    
    referenzfeld[a[idRoot]->id] = idRoot; // Referenzfeld - Erweiterung
    referenzfeld[a[idNext]->id] = idNext; // Referenzfeld - Erweiterung

    downHeap(idNext);
    return;
}

int pQueue::min(int idOne, int idTwo){
    if(a[idOne]->priority < a[idTwo]->priority){
        return idOne;
    }
    else{
        return idTwo;
    }
}

void pQueue::print(){
  for(int i=1; i<=elements; i++){
    cout << "ID: " << a[i]->id << " Value: " << a[i]->priority << "Node: " << a[i]->ptr->getName()<< endl;
  }
  cout << endl << endl;
}

void pQueue::printReferenzfeld(){
  for(int i=1; i<=elements; i++){
    cout << "Element ID: " << a[i]->id << " Heap ID: " << referenzfeld[a[i]->id] << endl;
  }
}

void pQueue::Insert(Element* Element){
  elements++;
  a[elements] = Element;

  referenzfeld[Element->id] = elements; // Referenzfeld - Erweiterung

  upHeap(elements);
}

int pQueue::Size(){
  return elements;
}

Element* pQueue::extractMin(){
  Element* temp = a[1];
  a[1] = a[elements];
  a[elements] = temp;

  Element cpy = *temp;
  delete a[elements];
  a[elements] = 0;
  elements --;

  downHeap(1);
  return &cpy;
}

void pQueue::Delete(int id, bool refFeld){

    if(!refFeld){
    // Ohne Referenzfeld
        for(int i=1; i<=elements; i++){
            if(a[i]->id == id){
              Element* temp = a[i];
              a[i] = a[elements];
              a[elements] = temp;

              delete a[elements];
              a[elements] = 0;
              elements --;

              downHeap(i);
             // upHeap(i); //--Entfernen

              return;
            }
        }
    }
    else{
        // Mit Referenzfeld
        int i = referenzfeld[id];
        Element* temp = a[i];
        a[i] = a[elements];

        a[elements] = temp;

        referenzfeld[a[i]->id] = i; // Referenzfeld - Erweiterung
        referenzfeld[a[elements]->id] = 0; // Referenzfeld - Erweiterung

        delete a[elements];
        a[elements] = 0;
        elements --;

        downHeap(i);
        upHeap(i);
        return;
    }
}

void pQueue::Increase(int id, int d, bool refFeld){
    if(!refFeld){
  // Ohne Referenzfeld

        for(int i=1; i<=elements; i++){
            if(a[i]->id == id){
                a[i]->priority += d;
                if(d<0){
                    downHeap(i);
                }else{
                    upHeap(i);
                }
                return;
            }
        }
    }
    else{
        // Mit Referenzfeld
        a[referenzfeld[id]]->priority += d;

        if(d<0){
            upHeap(referenzfeld[id]);
        }
        else{
            downHeap(referenzfeld[id]);
        }
    }
}

void pQueue::update(node* ptr){
        for(int i=1; i<=elements; i++){
            if(a[i]->ptr == ptr){
                int temp=a[i]->priority;
                a[i]->priority = ptr->getDist();
                cout << temp<< " zu " << ptr->getDist()<<"\n";
                if(ptr->getDist()<temp){
                    upHeap(i);
                }else{
                    downHeap(i);
                    
                }
                return;
            }
        }
}

Element* pQueue::minimum(){
    return a[1];
}

void pQueue::DeleteElement(node* ptr){
    for(int i=1; i<=elements; i++){
        if(a[i]->ptr == ptr){
            Element* temp = a[i];
            a[i] = a[elements];
            a[elements] = temp;

            delete a[elements];
            a[elements] = 0;
            elements --;

            downHeap(i);
           // upHeap(i); //--Entfernen

            return;
        }
    }
}