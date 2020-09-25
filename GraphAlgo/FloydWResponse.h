#include "../Graph/DirectedGraph.hpp"

class FloydWResponse{
private:
    DoubleList<DoubleList<double>>* prices;
    DoubleList<DoubleList<int>> * predecessor;
public:
    DoubleList<DoubleList<double>>* getPrices();
    DoubleList<DoubleList<int>>* getPredecessors();
    void setPrices(DoubleList<DoubleList<double>>* E_prices);
    void setPredecessors(DoubleList<DoubleList<int>>* E_predecessors);
};
