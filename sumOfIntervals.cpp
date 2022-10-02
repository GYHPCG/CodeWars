/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-09-30 13:56:34
 * @LastEditors: CGPan
 * @LastEditTime: 2022-09-30 14:49:01
 */
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
//合并区间问题
bool com(const pair<int,int> a, const pair<int,int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    sort(intervals.begin(),intervals.end(),com);
    int n = intervals.size();
    int sum = intervals[0].second - intervals[0].first;
    for (int  i = 1; i < n; ++i) {
        if (intervals[i].first < intervals[i-1].second && intervals[i].second > intervals[i-1].second) {
            sum += intervals[i].second - intervals[i-1].second;
        }
        else if (intervals[i].second < intervals[i-1].second) {
            intervals[i].second = intervals[i-1].second;
        }
        else if (intervals[i].first >= intervals[i-1].second){
            sum += intervals[i].second - intervals[i].first;
        }
    }

    return sum;
}
int main()
{
    vector<pair<int,int>>vec{{-448, 434}, {-308, 84}, {383, 441},{434,487}};
    cout << sum_intervals(vec) << endl;
    return 0;
}