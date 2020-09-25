#include "FloydWAlgo.h"
#include <iostream>
#define Null -1
FloydWResponse* Floyd(DoubleList<DoubleList<double>> &prices){
    DoubleList<DoubleList<double>>* price=new DoubleList<DoubleList<double>>(prices);
    DoubleList<DoubleList<int>>* predecessors=new DoubleList<DoubleList<int>>;
    FloydInit(price,predecessors);
    FloydProcess(price,predecessors);
    FloydWResponse * response=new FloydWResponse;
    response->setPredecessors(predecessors);
    response->setPrices(price);
    return response;

}
void FloydInit(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>* & predecessors){
    double maxValue=DGraph<int>::maxValue;
    DoubleList<int>* vector;
    for(int i=0;i<prices->getLen();i++){
        vector=new DoubleList<int>;
        for(int j=0;j<prices->get(i)->getLen();j++){
            if(*prices->get(i)->get(j)<maxValue)vector->add(*new int(i));
            else vector->add(*new int(Null));
        }
        predecessors->add(*vector);
    }
}
void FloydProcess(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors){
    for(int i=0;i<prices->getLen();i++){
        for(int j=0;j<prices->getLen();j++){
            if(i!=j) {
                for (int k = 0; k < prices->getLen(); k++) {
                    if (i != k && j != k)FloydIterator(i, j, k, prices, predecessors);
                }
            }
        }
    }
}
void FloydIterator(int i,int j, int k,DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors){
    int correct=2;
    int evaluator;
    int source_brick;
    int brick_goal;
    int source_goal;
    bool conditionA;
    bool conditionB;
    source_brick=*prices->get(j)->get(i);
    brick_goal=*prices->get(i)->get(k);
    source_goal=*prices->get(j)->get(k);
    conditionA=*predecessors->get(j)->get(i)!=Null;
    conditionB=source_brick+brick_goal<source_goal;
    evaluator= conditionA+ conditionB ;
    std::cout<<evaluator<<std::endl;
    if(evaluator==correct){
        prices->get(j)->set(k,*new double(source_brick+brick_goal));
        predecessors->get(j)->set(k,*new int(i));
    }
}
DoubleList<int>* getPath(FloydWResponse* response,int start,int end){
    DoubleList<DoubleList<int>> *Predecessor=response->getPredecessors();
    DoubleList<int> *returning=new DoubleList<int>;
    returning->add(start);
    int currentPosition=start;
    while(*Predecessor->get(currentPosition)->get(end)!=currentPosition){
        currentPosition=*Predecessor->get(currentPosition)->get(end);
        returning->add(*new int(currentPosition));
        //currentPosition=;
    }
    returning->add(*new int(end));
    return returning;
}
double getPrice(FloydWResponse* response,int start,int end){
    return *response->getPrices()->get(start)->get(end);
}
