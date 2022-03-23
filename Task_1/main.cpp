#include <iostream>
#include "Manipulator.h"

int main(){
    std::pair<double,double> first_center, second_center;
    double first_radius, second_radius;
    std::cout << "Input center first manipulator:" << std::endl;
    std::cin >> first_center.first >> first_center.second;
    std::cout << "Input effective radius first manipulator:" << std::endl;
    std::cin >> first_radius;
    std::cout << "Input center second manipulator:" << std::endl;
    std::cin >> second_center.first >> second_center.second;
    std::cout << "Input effective radius second manipulator:" << std::endl;
    std::cin >> second_radius;

    Manipulator first_manipulator(first_center,first_radius);
    Manipulator second_manipulator(second_center,second_radius);

    std::pair<double,double> point;
    std::cout << "Input point coordinates:" << std::endl;
    std::cin >> point.first >> point.second;

    double first_distance = first_manipulator.FindDistance(point);
    double second_distance = second_manipulator.FindDistance(point);

    if(first_manipulator.PointInRadius(point) && !second_manipulator.PointInRadius(point)){
        std::cout << "The first manipulator must move" << std::endl;
    }else if(!first_manipulator.PointInRadius(point) && second_manipulator.PointInRadius(point)){
        std::cout << "The second manipulator must move" << std::endl;
    }else if(!first_manipulator.PointInRadius(point) && !second_manipulator.PointInRadius(point)){
        std::cout << "OUT RANGE" << std::endl;
    }else{
        if(first_distance < second_distance){
            std::cout << "The first manipulator must move" << std::endl;
        }else{
            std::cout << "The second manipulator must move" << std::endl;
        }
    }
    return 0;
}