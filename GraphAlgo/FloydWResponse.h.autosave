/**
  *@file FloyWResponse.h
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title FloydResponse
  * @brief a object to store the info getted  from floyd algorithm
  */
#include "../Graph/DirectedGraph.hpp"

class FloydWResponse{
private:
    /**
     * @brief square matrix of double, represent the prices between every node
     */
    DoubleList<DoubleList<double>>* prices;
    /**
     * @brief double matrix of predecessor
     */
    DoubleList<DoubleList<int>> * predecessor;
public:
    /**
     * @brief get The matrix of prices
     * @return pointer to DoubleList<DoubleList<double>>
     */
    DoubleList<DoubleList<double>>* getPrices();
    /**
     * @brief getPredecessors
     * @return Pointer to DoubleList<DoubleList<int>>
     */
    DoubleList<DoubleList<int>>* getPredecessors();
    /**
     * @brief set the matrix of prices (double)
     * @param pointer to DoubleList<DoubleList<double>>
     */
    void setPrices(DoubleList<DoubleList<double>>* E_prices);
    /**
     * @brief set the predecessors matrix (DoubleList<DoubleList<int>>)
     * @param Pointer to DoubleList<DoubleList<int>>
     */
    void setPredecessors(DoubleList<DoubleList<int>>* E_predecessors);
};
