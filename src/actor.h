#pragma once

#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>

class Actor : public QGraphicsItem, public ObserverCollide {
protected:
    QPointF position;
    float angle;

public:
    Actor();

    void setRotation(float newAngle);
    virtual void movement();
    void collision();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};