#pragma once

#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>

class Actor : public QGraphicsItem, public ObserverCollide {
protected:
    QPointF position;
    float angle;
    QRectF boundingRect() const override;

public:
    Actor();

    void setRotation(int newAngle);
    virtual void movement();
    void collision();
    void setBoundary(float w, float l);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};