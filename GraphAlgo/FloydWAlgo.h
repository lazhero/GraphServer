/**
  *@file FloydWAlgo.h
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title Floyd-Warshall
  *
  */
#include "FloydWResponse.h"
/**
 * @brief get a object of the type FloydWresponse
 * @param a square matrix
 * @return a FloydWrespose object
 */
FloydWResponse* Floyd(DoubleList<DoubleList<double>> &prices);
/**
 * @brief Initializates a predecessor matrix of the algorith, given a matrix of doubles
 * @param prices the ponter to a square matrix of double
 * @param predecessors the pointer to a matrix of int to be initializated
 */
void FloydInit(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors);
/**
 * @brief Does the FloydAlgo with the given two matrices
 * @param pointer to a square matrix of doubles
 * @param pointer to a square matrix of int
 */
void FloydProcess(DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>* & predecessors);
/**
 * @brief tells you if you can goe to the k node , given a j start node and using i as a bridge
 * @param i  bridge
 * @param j start
 * @param k end
 * @param  pointer to a square matrix of double
 * @param pointer to a square matrix of int
 */
void FloydIterator(int i,int j, int k,DoubleList<DoubleList<double>>*& prices, DoubleList<DoubleList<int>>*& predecessors);
/**
 * @brief gets the path to from a node to another
 * @param response the FloyWresponse
 * @param start
 * @param end
 * @return a DoubleList<int> with a sucession of the route given
 */
DoubleList<int>* getPath(FloydWResponse* response,int start,int end);
/**
 * @brief get the price to go from one node to another
 * @param FloydWresponse
 * @param start
 * @param end
 * @return  a double of the price
 */
double getPrice(FloydWResponse* response,int start,int end);
