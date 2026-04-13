#pragma once

#include <string>

class ObserverCollide {
public:
    virtual ~ObserverCollide() {}
    virtual void update(const std::string& collission) = 0; //change to collision detect
};