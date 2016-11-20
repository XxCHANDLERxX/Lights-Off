#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell():isOn{false}{}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
    return Info{row,col,isOn};
}

void Cell::setOn() {
    isOn = true;
    notifyObservers(SubscriptionType::All);
}

void Cell::toggle() {
    if (isOn == true) {
        isOn = false;
    } else {
        isOn = true;
    }
    notifyObservers(SubscriptionType::All);
    notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::setCoords(int r, int c) {
    this->row = r;
    this->col = c;
}

void Cell::notify(Subject &whoNotified) {
    if (isOn == false) { setOn(); }
    else { isOn = false; }
    notifyObservers(SubscriptionType::All);
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
