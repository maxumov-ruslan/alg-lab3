#include <iostream>
#include "lis.hpp"
int main(){
    int n;
    
    std::cin>>n;
    std::vector<int> seq(n);
    for(int i = 0;i< n;i++){
        std::cin>>seq[i];
    }
    std::vector<int> lis = findLISOptimal(seq);
    std::cout <<"LIS: ";
    for(int i =0;i<lis.size();i++){
        std::cout <<lis[i]<< ' ';
    }
    std::cout<<std::endl;
    return 0;

}