#include "FloydWResponse.h"
FloydWResponse* Floyd(DoubleList<DoubleList<double>> &prices);
void FloydInit(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors);
void FloydProcess(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>* & predecessors);
void FloydIterator(int i,int j, int k,DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors);
DoubleList<int>* getPath(FloydWResponse* response,int start,int end);
double getPrice(FloydWResponse* response,int start,int end);
