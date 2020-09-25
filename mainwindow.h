#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartServer_clicked();
    void gettingClientText(QString data);

private:
    Ui::MainWindow *ui;
    LocalServer *server;
    DGraph<int>* graph;
    int nodeID=0;
    void handleRequest(DoubleList<int>* List);
    void addNode();
    void addRelation(int start,int end, int value);
    void getShortestRoute(int start,int end);
    bool cheakFree(int start,int end);
    bool position_check(int pos);
    DoubleList<int>* processText(std::string text);


};
#endif // MAINWINDOW_H
