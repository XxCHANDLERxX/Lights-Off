#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_
#include "window.h"
#include "observer.h"

class Cell;

class GraphicsDisplay : public Observer {
    Xwindow &xw;
    int gridSize;
    int squareSize;
public:
    GraphicsDisplay(Xwindow &xw);
    ~GraphicsDisplay();
    void init(int n);
    void clear();
    void notify(Subject &whoNotified) override;
    SubscriptionType subType() const override;
    
};


#endif
