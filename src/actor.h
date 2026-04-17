#pragma once

#include <QGraphicsItem>
#include <QSize>
#include <QPoint>
//#include <QPainter>

class Actor : public QGraphicsItem, public ObserverCollide {
protected:
    QSize _screenSize;       //screen size boundaries passed to actors for posn wrapping
    QPoint _position;           //actor position in x,y w/ floating point position
    int _rotation;                 //actor rotation degrees
    bool _collision;

    //for determining collision
    enum class ActorType{
        player, enemy, bullet};
    }
    //QRectF boundingRect() const override; //set collision bounds

public:
    //constructor gets passed screen size 
    Actor(int w, int h, QGraphicsItem* parent = nullptr):
        QGraphicsItem(parent), _screenSize(w,h), _position(0, 0) {};
        
    virtual ~Actor() = default;

    virtual void move() = 0;

    //rotation functions
    void setRotation(int degrees);
    int getRotation()   const;

    //position functions
    void setPosition(int newPosX, int newPosY);
    QPoint::QPoint getPosition()    const;

    virtual ActorType getType() const = 0;

    void collision();

    void setScreenSize(int w, int h);
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;  //function that defines collision bounds
};