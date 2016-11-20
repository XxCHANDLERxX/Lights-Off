#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
    for (auto &o:observers) {
        if (o->subType() == t) {
            o->notify(*this);
        }
    }
}
