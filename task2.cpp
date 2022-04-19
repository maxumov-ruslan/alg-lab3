#include <iostream>
#include "parens.hpp"
int main(){
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0;i<n;i++){
        std::cin>>nums[i];
    }
    Parentheses  parens(nums);
    std::cout <<"BEST: "<< parens.CalculateBest()<<std::endl;
    std::cout<<parens.printBestOrder()<<std::endl;
    return 0;

}