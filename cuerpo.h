#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>

class cuerpo
{
    double pX, pY, velX, velY, m, r, aX, aY, a;
    double tiempo = 1;
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
};

#endif // CUERPO_H
