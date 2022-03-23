#pragma once
#include <utility>
#include <istream>


class Manipulator{
public:
    Manipulator();
    Manipulator(const std::pair<double,double>& InpCenter,const double InpRadius);

    double FindDistance(const std::pair<double,double>& point) const;
    double GetRadius() const;
    bool PointInRadius(const std::pair<double,double>& point) const;
    
    friend std::istream& operator>>(std::istream& in,const Manipulator& manipulator);
private:
    std::pair<double,double> Center;
    double EffectiveRadius;
};