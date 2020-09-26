#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**
  *@file mainwindow.h
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title MainWindow
  * @brief the main widget to the Qt application
  */
#define minLen 5;
#include <QMainWindow>
//#include"Graph/DirectedGraph.hpp"
#include "GraphAlgo/FloydWAlgo.h"
class LocalServer;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Needed constructor for the framework
     * @param a QWidget to set a this object parent
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief signal launched when the start server push button is clicket
     */
    void on_StartServer_clicked();
    /**
     * @brief process the info getted from the socket
     * @param QString from data setted from the socket
     */
    void gettingClientText(QString data);

private:
    Ui::MainWindow *ui;
    LocalServer *server;
    DGraph<int>* graph;
    /**
     * @brief a ver to count the id of the node to be added
     */
    int nodeID=0;
    /**
     * @brief Handle the request reprented as a pointer to DoubleList<int>
     * @param pointer to DoubleList<int>
     */
    void handleRequest(DoubleList<int>* List);
    /**
     * @brief addNode to the graph
     */
    void addNode();
    /**
     * @brief addRelation between the start and the end node, with a value given
     * @param int position of the start node
     * @param int Position of the end node
     * @param int value to set the value
     */
    void addRelation(int start,int end, int value);
    /**
     * @brief send the shorest route to the socket
     * @param int start node pos
     * @param int end node pos
     */
    void getShortestRoute(int start,int end);
    /**
     * @brief checks if the relation ship if there is some previous relation
     * @param int start node
     * @param int end node
     * @return bool true if there is no relation, false
     */
    bool cheakFree(int start,int end);
    /**
     * @brief checks if a given position is [0:len[
     * @param pos to be evaluated
     * @return  true if its in the range
     */
    bool position_check(int pos);
    /**
     * @brief process the string getted , this is called from the signal
     * @param the text to be processed
     * @return  a double list that separates each parameter
     */
    DoubleList<int>* processText(std::string text);


};
#endif // MAINWINDOW_H
