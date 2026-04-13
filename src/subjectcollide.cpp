#include "subjectcollide.h"
#include <algorithm>

void subjectcollide::addObserver(ObserverCollide* o) {
    observers.push_back(o);
}

void subjectcollide::removeObserver(ObserverCollide* o) {
    observers.erase(
        std::remove(observers.begin(), observers.end(), o),
        observers.end()
    );
}

void subjectcollide::notifyObservers(const std::string& state) {
    for (ObserverCollide* o : observers) {
        if (o != nullptr) {
            o->update(state);
        }
    }
}