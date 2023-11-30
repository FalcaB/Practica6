#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>

class cuerpo : public QGraphicsItem
{
    double pX, pY, velX, velY, m, r, aX, aY, a;
    double tiempo = 1;
    double escR = 0.1;
    double escP = 0.025;
public:
    cuerpo();
    cuerpo(double, double, double, double, double, double);
    void CalVel();
    void CalP();
    void CalA(double, double, double);
    void A(double, double);
    double getPX() const;
    double getPY() const;
    double getM() const;
    double getAX() const;
    void setAX(double newAX);
    double getAY() const;
    void setAY(double newAY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CUERPO_H
