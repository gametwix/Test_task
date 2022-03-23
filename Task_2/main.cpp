#include <iostream>
#include <vector>
#include "Manipulator.h"

void BypassPoints(  const std::vector<std::pair<double,double>>& points,
                    Manipulator& first_manipulator,
                    Manipulator& second_manipulator,
                    std::vector<std::pair<double,double>>& points_for_first,
                    std::vector<std::pair<double,double>>& points_for_second){
    for(auto& point: points){
        double first_distance = first_manipulator.FindDistance(point);
        double second_distance = second_manipulator.FindDistance(point);
        if(first_manipulator.PointInRadius(point) && !second_manipulator.PointInRadius(point)){
            points_for_first.push_back(point);
            first_manipulator.MoveTo(point);
        }else if(!first_manipulator.PointInRadius(point) && second_manipulator.PointInRadius(point)){
            points_for_second.push_back(point);
            second_manipulator.MoveTo(point);
        }else{
            if(first_distance < second_distance){
                points_for_first.push_back(point);
                first_manipulator.MoveTo(point);
            }else{
                points_for_second.push_back(point);
                second_manipulator.MoveTo(point);
            }
        }
    }
}

int main(){
    std::vector<std::pair<double,double>> points;
    std::pair<double,double> point;
    std::cout << "Input points coordinates:" << std::endl;
    while(std::cin >> point.first >> point.second){
        points.push_back(point);
    }
    
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

    std::vector<std::pair<double,double>> points_for_first;
    std::vector<std::pair<double,double>> points_for_second;

    BypassPoints(points,first_manipulator,second_manipulator,points_for_first,points_for_second);


    for(auto& point:points_for_first){
        std::cout << "{" << point.first << "," << point.second << "}";
    }
    std::cout << std::endl;
    for(auto& point:points_for_second){
        std::cout << "{" << point.first << "," << point.second << "} ";
    }
    std::cout << std::endl;
    return 0;
}