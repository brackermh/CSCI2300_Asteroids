#include "actor.h"
#include <cmath>

using namespace std;

bool actor::collision(){};

//Position
void Actor::setPosition(int x, int y){
    //checks if actor moves out of bounds and wraps them back to opposite edge if so
    _position.setX(x % _screenSize.width());
    _position.setY(y % (int)_screenSize.height());
    setPos(_position);
}

QPoint Actor::getPosition(){
    return _position;
}

//Rotation
void Actor::setRotation(int angle){
    _rotation = angle % 360;
    QGraphicsItem::setRotation(_rotation);

};

int Actor::getRotation() const {
    return _rotation;
}

void Actor::setScreenSize(int w, int h){
    _screenSize = QSize(w,h);
}
