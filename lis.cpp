#include "lis.hpp"
#include <algorithm>
#include <limits.h>
std::vector<int> findLIS(const std::vector<int> &a){
    int n = a.size();
    std::vector<int> prev(n,-1);
    std::vector<int> d(n,0);
    for(int i = 0;i<n;i++){
        d[i] = 1;
        prev[i] = -1;
        for(int j = 0;j<i;j++){
            if(a[j] < a[i] && d[j]+1>d[i]){
                d[i] = d[j]+1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    int length = d[0];
    for(int i=0;i<n;i++){
        if(d[i] >length){
            pos = i;
            length = d[i];
        }
    }
    std::vector<int> answer;
    while(pos != -1){
        answer.push_back(a[pos]);
        pos = prev[pos];
    }
    std::reverse(answer.begin(),answer.end());
    return answer;
}
std::vector<int> findLISOptimal(const std::vector<int> &a){
    int n = a.size();
    std::vector<int> prev(n,-1);
    std::vector<int> d(n+1,INT_MAX);
    std::vector<int> pos(n+1,-1);
    int length = 0;
    pos[0] = -1;
    d[0] = INT_MIN;
    for(int i =0; i<n;i++){
        int j = std::lower_bound(d.begin(),d.end(),a[i]) - d.begin();
        if(d[j-1] <a[i] && a[i] < d[j]){
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j -1];
            length = std::max(length,j);
        }
    }
    int p = pos[length];
    std::vector<int> answer;
    while(p != -1){
        answer.push_back(a[p]);
        p = prev[p];
    }
    std::reverse(answer.begin(),answer.end());
    return answer;

}
