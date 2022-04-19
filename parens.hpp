#pragma once
#include <vector>
#include <string>
typedef std::vector<std::vector<int> >  v2d;
class Parentheses{
    std::vector<int> numbers;
    std::vector<std::vector<int> > d;
    std::vector<std::vector<int> > cut;
    std::vector<std::vector<char> > sign;
    std::string printSegment(int i,int j);
    public:
    Parentheses(std::vector<int> &x);
    int CalculateBest();
    int answerForSegment(int i,int j);
    std::string printBestOrder();
};