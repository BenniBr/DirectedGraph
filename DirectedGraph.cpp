/* 
 * File:   DirectedGraph.cpp
 * Author: Benjamin
 * 
 * Created on 18. Mai 2015, 20:07
 */

#include "DirectedGraph.h"
#include <string>
#include <map>
#include <cfloat>


using namespace std;

DirectedGraph::DirectedGraph() {
    
}

DirectedGraph::~DirectedGraph() {
    //Nicht notwendig, Aufgabenstellung
}

void DirectedGraph::loadMap(string map){
    ifstream toLoad;        
    char line[256];
    toLoad.open(map, ios_base::in);      
    if (!toLoad){
        return;
    }else{                                                            
        while (!toLoad.eof())
        {
            toLoad.getline(line,256);
            splitData(line);
        }
    }
    cout<<"Map wurde geladen.\n";
}

void DirectedGraph::splitData(char* data){
    string toSplit(data);
    istringstream ss(toSplit);
    string token;
    
    string source;
    string target;
    
    int i=0;
    while(getline(ss, token, ' ')) {
        if(i==0){
            source=addNodePrivate(token);
        }else if(i==1){
            target=addNodePrivate(token);
        }else if(i==2){
            addEdgePrivate(source, target, token);
        }else{
            return;
        }
        i++;
    }
}

string DirectedGraph::addNodePrivate(string add){
    if(nodemap.count(add)==0){ //! count gibt die anzahl zurück 1 oder 0, nie mehr als 1
        node* toAdd=new node(add);
        nodemap.insert(std::pair<string, node*> (add,toAdd));
        return toAdd->getName();
    }else{
        return nodemap[add]->getName();
    }
}

void DirectedGraph::addEdgePrivate(string source, string target, string token){
    // evtl auf Existenz von source und target prüfen
    if(!nodemap[source]->hasTarget(nodemap[target])){
        stringstream sstr;
        float lenght;
        sstr<<token;
        sstr>>lenght;
        edge* toAdd=new edge(nodemap[source],nodemap[target], lenght);
    }
}

void DirectedGraph::printInfo(){
    std::map<string, node*>::iterator it;    
    for (it=nodemap.begin(); it!=nodemap.end(); it++){ // iterator ++
        cout <<"_____________________________________\n";
        cout << "----------" <<it->second->getName() <<"----------" << "\n";
        for(int i=0; i<it->second->getOutEdgeNumber(); i++){
            cout <<"Nach " << it->second->getOutEdge(i)->getTarget()->getName()<<"\n";
        }
        for(int i=0; i<it->second->getInEdgeNumber(); i++){
            cout <<"Aus " << it->second->getInEdge(i)->getSource()->getName()<<"\n";
        }
    }
    cout <<"_____________________________________\n";
}

void DirectedGraph::interactiveMode(){
    bool check = true;
    int a=0;
    string inputSource;
    string inputDest;
    int inputPath;
    while(check){
        cout << "[1]Graph ausgeben, [2]Pfad prüfen, [3]Dijkstra, [0]Beenden" << endl;
        cin >> a;
        switch (a){
            case 1: 
                printInfo();
                break;
            case 2:
                
                
                cout << "Start: " << endl;
                cin >> inputSource;
                cout << "Ziel: " << endl;
                cin >> inputDest;
                cout << "Anzahl maximaler Pfade: " << endl;
                cin >>inputPath;
                routeExists(inputSource, inputDest, inputPath);
                break;
            case 3:
                cout << "Start: " << endl;
                cin >> inputSource;
                dijkstra(inputSource);
                break;
            case 0:
                cout << "Programm wird beendet!" << endl;
                check = false;
                break;
            default:
                cout <<"Ungültige Eingabe!" << endl;
                break;
        }
    }
}

void DirectedGraph::routeExists( string from, string to, int lenght){
    if(nodemap.count(from)!=0 && nodemap.count(to)!=0 && lenght>0){
        node* source=nodemap[from];
        node* target=nodemap[to];
        node* final=routeSearch(source, target);
        int steps=0;
        while(final->getPre()!=NULL){
            steps++;
            cout<<"Knoten"<< steps<< ":"<< final->getName()<<endl;
            final=final->getPre();
        }
        cout<<"Schritte:"<< steps+1<<endl;
        if(steps<=lenght){
            cout<<"Route gefunden "<<endl;
        }else{
            cout<<"Route nicht gefunden "<<endl;
        }
        unVisitNodes();
        unPreNodes();
    }
        
  /* s.vorgaenger = NULL; s.markiert = true
   Erzeuge Schlange S
   S.enq(s)
   while( !S.empty() ) {
      v = S.deq()
// bearbeite Knoten v
if( v == t ) return v; foreach(Nachfolger vi von v) {
// bearbeite Kante (v, vi) if( !vi.markiert ) {
vi.markiert = true; vi.vorgaenger = v;
S.enq(vi) }
        */
       /* int steps= routeSearch(source, target, lenght);
        if(steps != 0){
            cout<< "Route gefunden. \n";
        }else{
            cout<< "Route nicht gefunden. \n";
        }
        unVisitNodes();
    }else{
        cout << "Eingabe war fehlerhaft. \n";
    }   */
    }


node* DirectedGraph::routeSearch(node* source, node* target){
    source->setPre(NULL);
        source->setVisited(true);
        
        pQueue* q = new pQueue();
        q->Insert(new Element(0,0,source));
        node* temp;
        while(q->Size() > 0){
            temp= q->extractMin()->ptr;
            if(temp==target){
                return target;
            }
            for(int j = 0; j < temp->getOutEdgeNumber(); j++){
                if(!temp->getInEdge(j)->getTarget()->isVisited()){
                    temp->getOutEdge(j)->getTarget()->setVisited(true);
                    temp->getOutEdge(j)->getTarget()->setPre(temp);
                    q->Insert(new Element(0,temp->getOutEdge(j)->getWeight(),temp->getOutEdge(j)->getTarget()));
                }
            }
        }
        return source;
}
//int DirectedGraph::routeSearch(node* source, node* target, int lenght){
  //  source->setVisited(true);
    //pQueue auserhalb der Funktion erstellen, da rekurisv
    //Nach Nachbarn schauen, der visited != true;
    //nachbar->setVisited(true); Das für alle Nachbarn vom Sourceknoten
    //Diese Nachbarn in Queue packen
    
    //Den ersten aus der Queue als Startknoten
    //ersterPQueue aus pQueue entfernen
    //routeSearch(ersterPQueue);
   /* 
    ￼Search_BFS(Graph G, Startknoten s, Zielknoten t) {
   s.vorgaenger = NULL; s.markiert = true
   Erzeuge Schlange S
   S.enq(s)
   while( !S.empty() ) {
      v = S.deq()
// bearbeite Knoten v
if( v == t ) return v; foreach(Nachfolger vi von v) {
// bearbeite Kante (v, vi) if( !vi.markiert ) {
vi.markiert = true; vi.vorgaenger = v;
S.enq(vi) }
} }
}*/
//}
/*
int DirectedGraph::routeSearch(node* source, node* target, int lenght){
    int steps;
    node* data[nodemap.size()];
    for(int i=0; i<source->getOutEdgeNumber();i++){
        if(!source->getOutEdge(i)->getTarget()->isVisited()){
            data[i]=source->getOutEdge(i)->getTarget();
        }
    }
    source->setVisited(1);
    for(int i=0; i<source->getOutEdgeNumber();i++){
        if(!source->getOutEdge(i)->getTarget()->isVisited()){
            if(lenght!=0 && source->getOutEdge(i)->getTarget()!=target){
                if(routeSearch(source->getOutEdge(i)->getTarget(), target, lenght-1)!=0){
                    routeSearch(source->getOutEdge(i)->getTarget(), target, lenght-1);
                }
                cout<<source->getOutEdge(i)->getTarget()->getName()<<" "<<target->getName()<<"\n";
            }else if(lenght!=0 && source->getOutEdge(i)->getTarget()==target){
                cout<<source->getOutEdge(i)->getTarget()->getName()<<" "<<target->getName()<<"\n";
                return steps;
            }else{
                return 0;
            }
        }
    }
    
}
*/
void DirectedGraph::unVisitNodes(){
    std::map<string, node*>::iterator it;    
    for (it=nodemap.begin(); it!=nodemap.end(); it++){
        it->second->setVisited(0);
    }
}

void DirectedGraph::unPreNodes(){
    std::map<string, node*>::iterator it;    
    for (it=nodemap.begin(); it!=nodemap.end(); it++){
        it->second->setPre(NULL);
    }
}

void DirectedGraph::dijkstra(string from){
    node* source;
    if(nodemap.count(from)!=0){
        source = nodemap[from];
    }
    else{
        cout << "Falsche Eingabe" << endl;
        return;
    }
    int i = 1;
    pQueue* q = new pQueue();
    std::map<string, node*>::iterator it;    
    for (it=nodemap.begin(); it!=nodemap.end(); it++){
        it->second->setVisited(0);
        it->second->setPre(NULL);
        if(it->second == source){
            it->second->setDist(0);
        }
        else{
            it->second->setDist(999.9);
        }
        q->Insert(new Element(i, it->second->getDist(), it->second));
        i++;
    }
    q->print();
    node* popped;
    while(q->Size() > 0){
        q->print();
        popped = q->extractMin()->ptr;
        cout << "EX:"<< popped->getName()<<","<<popped->getDist()<<"\n";
        popped->setVisited(true);
        for(int j = 0; j < popped->getOutEdgeNumber(); j++){
            if(!popped->getOutEdge(j)->getTarget()->isVisited()){
                if(popped->getDist() + popped->getOutEdge(j)->getWeight() < popped->getOutEdge(j)->getTarget()->getDist()){
                   // cout << "2. if " << q->Size() << endl;
                    popped->getOutEdge(j)->getTarget()->setDist(popped->getDist() + popped->getOutEdge(j)->getWeight());  
                    q->update(popped->getOutEdge(j)->getTarget());
                    //setDist->Update auf Element popped->getOutEdge(j)->getTarget()
                    //Dieses Element rausschmeißen, mit neuer dist einfügen
                    popped->getOutEdge(j)->getTarget()->setPre(popped);
                }
               // cout << "1. if " << q->Size() << endl;
            }
           // cout << "for " << q->Size() << endl;
        }
    }
    std::map<string, node*>::iterator it2;    
    for (it2=nodemap.begin(); it2!=nodemap.end(); it2++){
        cout << "Distanz vom Knoten " << it2->second->getName() << " zum Startknoten: " << endl;
        node* toPrint = it2->second;
        float route = toPrint->getDist();
        while(toPrint->getPre() != NULL){
            cout << "Knoten: " << toPrint->getName() << endl;
            toPrint=toPrint->getPre();
        }
        cout << "Kürzester Weg: " << route << endl<<endl;    
    }
    unVisitNodes();
    unPreNodes();
    //pQueue erstellen
    //foreach node v in nodemap
        //v.setVisited(false); v.pre = NULL;
        //if(v == source){ v.dist = 0;}
        //else{v.dist = MAXDOUBLE;}
        //v in pQueue;
    //while(pQueue != empty())
        //v = pQueue.pop; v.setVisited(true);
        //foreach Nachfolger vi von v 
            //if((!vi.isVisited())){
                //if((v.dist + Entfernung von v nach vi) < vi.dist){
                    //vi.dist = v.dist + Entfernung von v nach vi;
                    //vi.pre = v;
                    //pQueue.update(vi); ???
                //}
            //}
    //printRange()
}