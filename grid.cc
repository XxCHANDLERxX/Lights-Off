#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(Xwindow &w):td{nullptr}, gd{new GraphicsDisplay{w}}{}

Grid::~Grid() {
    for (unsigned int i = 0; i < theGrid.size(); ++i) {
        theGrid[i].clear();
    }
    theGrid.clear();
    delete td;
    delete gd;
}

void Grid::clearGrid() {
    for (unsigned int i = 0; i < theGrid.size(); ++i) {
        theGrid[i].clear();
    }
    theGrid.clear();
    delete td;
}

bool Grid::isWon() const {
    for (unsigned int i = 0; i < theGrid.size(); ++i) {
        for (unsigned int j = 0; j < theGrid[i].size(); ++j) {
            if (theGrid[i][j].getState() == true) {
                return false;
            }
        }
    }
    return true;
}

void Grid::init(int n) {
    gridSize = n;
    clearGrid();
    gd->clear();
    gd->init(n);
    td = new TextDisplay(n);
    for (int i = 0; i < n; ++i) {
        vector<Cell> r(n,Cell());
        for (int j = 0; j < n; ++j) {
            r[j].setCoords(i, j);
        }
        theGrid.push_back(r);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                theGrid[i][j].attach(&theGrid[i][j+1]);
                theGrid[i][j].attach(&theGrid[i+1][j]);
            } else if (i == 0 && j == n-1) {
                theGrid[i][j].attach(&theGrid[i][j-1]);
                theGrid[i][j].attach(&theGrid[i+1][j]);
            } else if (i == n-1 && j == 0) {
                theGrid[i][j].attach(&theGrid[i-1][j]);
                theGrid[i][j].attach(&theGrid[i][j+1]);
            } else if (i == n-1 && j == n-1) {
                theGrid[i][j].attach(&theGrid[i-1][j]);
                theGrid[i][j].attach(&theGrid[i][j-1]);
            } else if (i == 0 && j > 0 && j < n-1) {
                theGrid[i][j].attach(&theGrid[i][j-1]);
                theGrid[i][j].attach(&theGrid[i+1][j]);
                theGrid[i][j].attach(&theGrid[i][j+1]);
            } else if (i == n-1 && j > 0 && j < n-1) {
                theGrid[i][j].attach(&theGrid[i][j-1]);
                theGrid[i][j].attach(&theGrid[i-1][j]);
                theGrid[i][j].attach(&theGrid[i][j+1]);
            } else if (j == 0 && i > 0 && i < n-1) {
                theGrid[i][j].attach(&theGrid[i-1][j]);
                theGrid[i][j].attach(&theGrid[i][j+1]);
                theGrid[i][j].attach(&theGrid[i+1][j]);
            } else if (j == n-1 && i > 0 && i < n-1) {
                theGrid[i][j].attach(&theGrid[i-1][j]);
                theGrid[i][j].attach(&theGrid[i][j-1]);
                theGrid[i][j].attach(&theGrid[i+1][j]);
            } else {
                theGrid[i][j].attach(&theGrid[i-1][j]);
                theGrid[i][j].attach(&theGrid[i][j-1]);
                theGrid[i][j].attach(&theGrid[i+1][j]);
                theGrid[i][j].attach(&theGrid[i][j+1]);
            }
            theGrid[i][j].attach(td);
            theGrid[i][j].attach(gd);
        }
    }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

void Grid::init(int r, int c) {
    turnOn(r, c);
}

ostream &operator<<(ostream &out, const Grid &g) {
    out << *g.td;
    return out;
}
