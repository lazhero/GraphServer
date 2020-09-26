/**
  *@file DoubleNode.hpp
  * @author Luis Andrey Zuniga
  * @version 1.0
  * @title DoubleNode - A node with two ponters at other nodes
  * @date 25/09/2020
  *
  */


#include <string>
template<typename T>
class DoubleNode {
private:
    /**
     * @brief Data saved
     */
    T *Data;
    /**
     * @brief Pointer to another node
     */
    DoubleNode<T> *Front;
    /**
     * @brief Pointer to another node
     */
    DoubleNode<T> *Back;
public:
    /**
     * @brief The constructor of the class
     */
    DoubleNode();
    ~DoubleNode();
    /**
     * @brief set the data stored in the node
     * @param the data to be saved
     */
    void setData(T &data);
    /**
     * @brief get the data stored in the node
     * @return  the data stored
     */
    T* getData();
    /**
     * @brief set the "Front" node
     * @param An pointer to a object of the same class
     */
    void setFront(DoubleNode<T> &Node);
    /**
     * @brief set the "Back" node
     * @param An pointer to a object of the same class
     */
    void setBack(DoubleNode<T> &Node);
    /**
     * @brief get the "Back" node
     * @return return the node
     */
    DoubleNode<T>& getBack();
    /**
     * @brief get the "Front" node
     * @return a object of the same class as a reference
     */
    DoubleNode<T>& getFront();
    /**
     * @brief Tells you if the front node is empty
     * @return  true if the front is empty, false if its not
     */
    bool emptyFront();
    /**
     * @brief Tells you if the back node is empty
     * @return true if the front is empty , false if its not
     */
    bool emptyBack();
    /**
     * @brief empty the front
     */
    void makeFrontEmpty();
    /**
     * @brief empty the end
     */
    void makeBackEmpty();
};
template <typename T>
DoubleNode<T>::DoubleNode() {
    Data=(T*)malloc(sizeof(T));
    Front=NULL;
    Back=NULL;
}
template <typename T>
DoubleNode<T>::~DoubleNode() {
    free(Data);
    if(Front!=NULL)free(Front);
    if(Back!=NULL)free(Back);
}
template <typename T>
void DoubleNode<T>::setData(T &data) {
    *Data=data;
}
template <typename T>
T* DoubleNode<T>::getData() {
    return Data;
}
template <typename T>
DoubleNode<T>& DoubleNode<T>::getBack() {
    //if(Back==NULL)return emptyReturn;
    return *Back;
}
template <typename T>
DoubleNode<T>& DoubleNode<T>::getFront() {
    //if(Front==NULL)return emptyReturn;
    return *Front;
}
template <typename T>
void DoubleNode<T>::setBack(DoubleNode<T> &Node) {
    Back=&Node;
}
template <typename T>
void DoubleNode<T>::setFront(DoubleNode<T> &Node) {
    Front=&Node;
}
template <typename T>
bool DoubleNode<T>::emptyBack() {
    if(Back==NULL)return true;
    return false;
}
template <typename T>
bool DoubleNode<T>::emptyFront() {
    if(Front==NULL)return true;
    return false;
}
template <typename T>
void DoubleNode<T>::makeBackEmpty() {
    Back=NULL;
}
template <typename T>
void DoubleNode<T>::makeFrontEmpty() {
    Front==NULL;
}
