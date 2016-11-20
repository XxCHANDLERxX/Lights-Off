#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n):gridSize{n}{
    for (int i = 0; i < n; ++i) {
        vector<char> r;
        for (int j = 0; j < n; ++j) {
            r.emplace_back();
            r[j] = '_';
        }
        theDisplay.push_back(r);
    }
}

void TextDisplay::notify(Subject &whoNotified) {
    if (whoNotified.getInfo().state == true) {
        theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'X';
    } else {
        theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = '_';
    }
}

TextDisplay::~TextDisplay() {
    for (unsigned int i = 0; i < theDisplay.size(); ++i) {
        theDisplay[i].clear();
    }
    theDisplay.clear();
}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i = 0; i < td.gridSize; ++i) {
        for (int j = 0; j < td.gridSize; ++j) {
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
    return out;
}
