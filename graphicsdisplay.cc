#include "graphicsdisplay.h"
#include "info.h"
#include "cell.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(Xwindow &xw):xw{xw}{}

GraphicsDisplay::~GraphicsDisplay(){}

void GraphicsDisplay::init(int n){
    gridSize = n;
    squareSize = 500 / n;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            xw.fillRectangle(squareSize*i, squareSize*j, squareSize, squareSize, Xwindow::Black);
            xw.fillRectangle(squareSize*j, squareSize*i, squareSize, squareSize, Xwindow::Black);
        }
        
    }
    
}

void GraphicsDisplay::clear(){
    xw.fillRectangle(0, 0, 500, 500, Xwindow::White);
}

void GraphicsDisplay::notify(Subject &whoNotified) {
    if (whoNotified.getInfo().state == true) {
        xw.fillRectangle(squareSize*whoNotified.getInfo().col, squareSize*whoNotified.getInfo().row, squareSize, squareSize, Xwindow::White);
    } else {
        xw.fillRectangle(squareSize*whoNotified.getInfo().col, squareSize*whoNotified.getInfo().row, squareSize, squareSize, Xwindow::Black);
    }
}

SubscriptionType GraphicsDisplay::subType() const {
    return SubscriptionType::All;
}
