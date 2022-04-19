#include "parens.hpp"
#include <limits.h>
Parentheses::Parentheses(std::vector<int> &x){
    numbers = x;
    d.resize(x.size(),std::vector<int>(x.size(),INT_MAX));
    cut.resize(x.size(),std::vector<int>(x.size(),-1));
    sign.resize(x.size(),std::vector<char>(x.size(),'?'));
}
int Parentheses::CalculateBest(){
    for(int m = 0;m<numbers.size();m++){
        for(int i = 0;i<numbers.size() - m;i++){
            int j = i+m;
            if(i == j){
                d[i][j] = numbers[i];
            }else{
                int a = d[i][i]+d[i+1][j];
                int b = d[i][i]*d[i+1][j];
                d[i][j] = std::min(a,b);
                sign[i][j] = (d[i][j] == a)?'+':'*';
                cut[i][j] = i;

                for(int k = i+1;k<j;k++){
                    a = d[i][k]+d[k+1][j];
                    b = d[i][k]*d[k+1][j];
                    int n = std::min(a,b);
                    char s = (n==a)?'+':'*';
                    if(n < d[i][j]){
                        d[i][j]=n;
                        sign[i][j] = s;
                        cut[i][j] = k;
                    }

                }
            }
        }
    }
    return d[0][numbers.size()-1];
}
int Parentheses::answerForSegment(int i,int j){
    return d[i][j];
}
std::string Parentheses::printSegment(int i,int j){
    if (i==j)
        return std::to_string(numbers[i]);
    return "("+printSegment(i,cut[i][j])+") "+sign[i][j]+" ("+printSegment(cut[i][j]+1,j)+")";
}
std::string Parentheses::printBestOrder(){
    return printSegment(0,numbers.size()-1);
}