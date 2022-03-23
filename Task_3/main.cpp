#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>


int main(){
    std::string str;
    std::vector<double> point(3);
    std::cin >> point[0] >> point[1] >> point[2];
    while(std::cin >> str){
        try{
            std::vector<std::string> substrs;
            //split by ;
            std::string::size_type position = str.find(";");
            while(position != std::string::npos){
                substrs.push_back(str.substr(0,position));
                str = str.substr(position+1, str.size());
                position = str.find(";");
            }
            //checking the number of elements
            if(substrs.size() != 3 || str.size() != 0){
                throw std::runtime_error("ERROR SCRIPT");
            }
            //check first letter
            if(substrs[0][0] != 'X' || substrs[1][0] != 'Y' || substrs[2][0] != 'Z'){
                throw std::runtime_error("ERROR SCRIPT");
            }
            //try convert to double
            std::vector<double> move(3);
            for(int i = 0; i < 3; ++i){
                substrs[i] = substrs[i].substr(1,substrs[i].size());
                try{
                    move[i] = stod(substrs[i]);
                }catch(std::invalid_argument){
                    throw std::runtime_error("ERROR SCRIPT");
                }
            }
            //sum
            for(int i = 0; i < 3; ++i){
                point[i] += move[i];
            }
        }catch(std::runtime_error error){
            std::cout << point[0]<< " " << point[1]<< " " << point[2] << std::endl;
            std::cout << error.what() << std::endl;
            return 0;
        }

    }
    
    std::cout << point[0]<< " " << point[1]<< " " << point[2] << std::endl;
    
    return 0;
}