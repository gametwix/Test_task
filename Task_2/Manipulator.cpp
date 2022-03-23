#include <cmath>
#include <iostream>
#include "Manipulator.h"


Manipulator::Manipulator():Center({0,0}),EffectiveRadius(0){}
Manipulator::Manipulator(const std::pair<double,double> InpCenter,
                        const double InpRadius):Center(InpCenter),EffectiveRadius(InpRadius){}

double Manipulator::GetRadius()const{return EffectiveRadius;}


double Manipulator::FindDistance(const std::pair<double,double> point) const{
    double xDist = Center.first - point.first;
    double yDist = Center.second - point.second;
    return std::sqrt(xDist*xDist + yDist*yDist);
}

bool Manipulator::PointInRadius(const std::pair<double,double> point) const{
    return FindDistance(point) <= EffectiveRadius;
}

void Manipulator::MoveTo(std::pair<double,double> point){
    Center = point;
}