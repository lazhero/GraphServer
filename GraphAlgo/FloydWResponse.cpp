#include "FloydWResponse.h"
DoubleList<DoubleList<int>>* FloydWResponse::getPredecessors() {
    return predecessor;
}
DoubleList<DoubleList<double>>* FloydWResponse::getPrices() {
    return prices;
}
void FloydWResponse::setPrices(DoubleList<DoubleList<double>> *E_prices) {
    prices=E_prices;
}
void FloydWResponse::setPredecessors(DoubleList<DoubleList<int>>*E_predecessors) {
    predecessor=E_predecessors;
}

