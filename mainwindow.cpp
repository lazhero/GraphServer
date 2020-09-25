#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "localserver.h"
#include<iostream>

#include<string>
#define separator '#'
int lowestIndex=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server=new LocalServer(this);
    graph=new DGraph<int>;
    connect(server,SIGNAL(incomingText(QString)),this,SLOT(gettingClientText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_StartServer_clicked(){
    QString Name=ui->lineEdit->text();
    if(Name.length()>5 || true){
        server->startListening(Name);
        ui->ServerName->setText(Name);

    }
    ui->lineEdit->setText(QString(""));

}
void MainWindow::gettingClientText(QString data){
   ui->List->addItem(data);
    std::cout<<data.toStdString()<<std::endl;
    std::string recieve=data.toStdString();
   DoubleList<int> *resultList=this->processText(recieve);
    for(int i=0;i<resultList->getLen();i++){
        std::cout<<"El dato en posicion "<<i<<std::endl;
        std::cout<<*resultList->get(i)<<std::endl;
    }
    handleRequest(resultList);
}

void MainWindow::handleRequest(DoubleList<int> *List)
{
    int condition=*List->get(lowestIndex);
    switch (condition) {
   case 0:
        addNode();
        break;
    case 1:
        addRelation(*List->get(lowestIndex+1),*List->get(lowestIndex+2),*List->get(lowestIndex+3));
        break;
    case 2:
        getShortestRoute(*List->get(lowestIndex+1),*List->get(lowestIndex+2));
        break;

    }
}

void MainWindow::addNode()
{
    graph->AddNode(*new int(nodeID));
    nodeID++;
    server->write(QString("0"));
}

void MainWindow::addRelation(int start, int end, int value)
{
    if(!position_check(start)|| !position_check(end)) server->write(QString("-1"));
    else{
        graph->fixRelationShip(start,end,value);
        graph->fixRelationShip(end,start,value);
        server->write(QString("1"));
    }
}

void MainWindow::getShortestRoute(int start, int end)
{
    if(!position_check(start)|| !position_check(end)){
        server->write(QString(false));
        return;
    }
   DoubleList<DoubleList<double>> *List= graph->getRelations();
   for(int i=0;i<List->getLen();i++){
       for(int j=0;j<List->getLen();j++){
           std::cout<<"El dato en "<<i<<" "<<j<<" es "<<*List->get(i)->get(j)<<std::endl;
       }
   }

   FloydWResponse *response=Floyd(*List);
    double price=getPrice(response,start,end);

    if(price>=graph->maxValue)server->write(QString("-1"));
    else{
        std::cout<<"Lo logre antes de la obtencion del path"<<std::endl;
        DoubleList<int> *path=getPath(response,start,end);
        for(int i=0;i<path->getLen();i++){
            std::cout<<"El dato detro de la path es "<<path->get(i)<<std::endl;
        }
        std::cout<<"termine de revisar la ruta"<<std::endl;
        std::string message="The shortest route is ";
        for(int i=0;i<path->getLen();i++){
            message+=std::to_string(*path->get(i))+",";
        }
        message+="\nThe value is ";
        message+=std::to_string((int)price);
        std::cout<<"El texto por enviar para la ruta corta es "<<message;
        server->write(QString::fromStdString(message));
    }

}

bool MainWindow::cheakFree(int start, int end)
{
    if(!position_check(start)||!position_check(end))return false;
    DoubleList<double>* Relation=graph->getRelations(start);
    if(*Relation->get(end)<graph->maxValue)return true;
    return false;
}

bool MainWindow::position_check(int pos)
{
    if(pos<0 || pos>=nodeID)return false;
    return true;
}
DoubleList<int>* MainWindow::processText(std::string text){
    if(text.length()<=0)return nullptr;
    DoubleList<int> * returning=new DoubleList<int>;
    std::string substring;
    int startLock=0;
    for(unsigned int i=0;i<text.length();i++){
        if(text.at(i)==separator){
            substring=text.substr(startLock,i-startLock);
            startLock=i+1;
            returning->add(*new int(std::stoi(substring))) ;
        }
    }
    return returning;
}
