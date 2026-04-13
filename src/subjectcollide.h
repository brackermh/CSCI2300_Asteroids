#pragma once

#include <vector>
#include <string>
#include "ObserverCollide.h"

class subjectcollide {      //adjust for actor collision
protected:
    std::vector<ObserverCollide*> observers;

public:
    virtual ~subjectcollide() {}
    virtual void addObserver(ObserverCollide* o);
    virtual void removeObserver(ObserverCollide* o);
    virtual void notifyObservers(const std::string& state);
};
