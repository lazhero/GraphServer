/**
  *@file DirectedGraph.hpp
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title Generic Directed Graph
  */


#include "../DoubleList/DoubleList.hpp"
template<typename T>
class DGraph{
public:
    /**
     * @brief The class constructor
     */
    DGraph();
    /**
      *@brief The class destructor
      */

    ~DGraph();
    /**
     * @brief get the the node a define positon
     * @param position of the node (ordered by how they were entered)
     * @return  the data in that node
     */
    T* getNode(int pos);
    /**
     * @brief get Relations of a specific node
     * @param position in the node list
     * @return a list of double with the prices to the other nodes
     */
    DoubleList<double>* getRelations(int pos);
    /**
     * @brief get a matrix with the relations between every node
     * @return  a DoubleList<DoubleList<double>>
     */
    DoubleList<DoubleList<double>>* getRelations();
    /**
     * @brief add a new node
     * @param the data to that node
     */
    void AddNode(T &data);
    /**
     * @brief Delete the node at some position
     * @param position to be deleted
     */
    void DeleteNode(int pos);
    /**
     * @brief change the value in the relationship between two nodes
     * @param the position of the start node at the nodes list
     * @param the position of the end node at the end
     * @param price to be setted
     */
    void fixRelationShip(int from,int to, double price);
    /**
     * @brief maxValue constant
     */
    constexpr static const double maxValue=9999999.9;

private:
    /**
     * @brief List of nodes
     */
    DoubleList<T>* Nodes;
    /**
     * @brief RelationMatrix
     */
    DoubleList<DoubleList<double>>* RelationMatrix;
    /**
     * @brief get a pointer that refers a memory cell with the max constant
     * @param ptr
     */
    void getPointerMaxValue(double *&ptr);
    /**
     * @brief initialice a list indicated at the pointer given , with the len indicated and all position have the value parsed
     * @param List  Pointer to the list to be initilizated
     * @param len of the list that you want
     * @param value to fill the list with
     */
    void getVector(DoubleList<double>* List,int len,double value);
};
template<typename T>
DGraph<T>::DGraph() {
    Nodes=new DoubleList<T>;
    RelationMatrix=new DoubleList<DoubleList<double>>;
}
template<typename T>
void DGraph<T>::getPointerMaxValue(double *&ptr) {
    ptr=(double*)malloc(sizeof(double));
    *ptr=maxValue;
}
template<typename T>
void DGraph<T>::getVector(DoubleList<double>* List,int len,double value){
    double *temp;
    for(int i=0;i<len;i++){
        temp=(double*)malloc(sizeof(double));
        *temp=value;
        List->add(*temp);
    }
}
template<typename T>
T* DGraph<T>::getNode(int pos) {
    return Nodes->get(pos);
}
template<typename T>
DoubleList<double>* DGraph<T>::getRelations(int pos) {
    return RelationMatrix->get(pos);
}
template<typename T>
void DGraph<T>::AddNode(T &data) {
    double *temp;
    Nodes->add(data);
    int len=Nodes->getLen();
    for(int i=0;i<len-1;i++){
        DGraph<T>::getPointerMaxValue(temp);
        RelationMatrix->get(i)->add(*temp);
    }
    DoubleList<double>* vector=new DoubleList<double>;
    getVector(vector,len,maxValue);
    RelationMatrix->add(*vector);
}
template<typename T>
void DGraph<T>::DeleteNode(int pos) {
    Nodes->erase(pos);
    RelationMatrix->erase(pos);
    for(int i=0;i<RelationMatrix->getLen();i++){
        RelationMatrix->get(i)->erase(pos);
    }
}
template<typename T>
void DGraph<T>::fixRelationShip(int from, int to, double price) {
    *RelationMatrix->get(from)->get(to)=price;
}
template<typename T>

DoubleList<DoubleList<double>>* DGraph<T>::getRelations(){
    return RelationMatrix;
}
template<typename T>
DGraph<T>::~DGraph(){
    free(RelationMatrix);
    free(Nodes);
}

