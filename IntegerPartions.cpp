/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-02 13:11:32
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-04 17:44:51
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>
using namespace std;
using ll = long long;
vector<vector<ll> > Enum;
vector<ll>path;
ll getEnum(ll n, ll m) {
   if (n == 1 || m == 1) {
    return 1;
   }
   else if ( m > n) {
    return getEnum(n,n);
   }
   else if (m == n) {
    return 1 + getEnum(n,n-1);
   }
   else return getEnum(n-m,m) + getEnum(n,m-1);
   return 0;

}
void Count(int n, int m, vector<ll> path) {
    if (n == 0){
        Enum.push_back(path);
        return;
    } //cout << s << endl;
    else {
        if (m > 1) {
            Count(n, m-1, path);
        }
        if (m <= n) {
            path.push_back(m);
            Count(n-m,m,path);
        }
    }
}
void print(vector<vector<ll>>& vec) {
    for (auto i = 0 ; i < vec.size();++i) {
        for (auto j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
ll getRange(vector<ll>& vec) {
    return vec[vec.size()-1] - vec[0];
}
double getAverage(vector<ll>& vec) {

    return (double) accumulate(vec.begin(),vec.end(),0) / vec.size();
}
double getMed(vector<ll>& vec) {
    int n = vec.size();
    if (n % 2 == 1) return (double) vec[n/2];
    return (double) (vec[n/2] + vec[n/2 -1]) / 2;

}
class IntPart
{
public:
  static std::string part(long long n);
};
int main()
{
    Enum.clear();
    path.clear();
    //cout << getEnum(4,4) << endl;
    Count(7,7,path);
    //int n = Enum.size();
    vector<ll>Sorta;
    for (int i = 0; i < Enum.size(); ++i) {
        //Sorta.push_back(accumulate(Enum[i].begin(),Enum[i].end(),0));
        int tmp = 1;
        for (int j = 0; j < Enum[i].size(); ++j) {
            tmp *= Enum[i][j];
        }
        Sorta.push_back(tmp);
    }
    //cout << n << endl;
    //cout << Sorta.size() << endl;
    sort(Sorta.begin(),Sorta.end());
    //去重
    auto ik = unique(Sorta.begin(),Sorta.end());
    Sorta.erase(ik,Sorta.end());
    // for (auto k : Sorta) {
    //     cout << k << " ";
    // }
    // cout << endl;
   // print(Enum);
    //获取range
    ll range = getRange(Sorta);
    cout << "range: " << range << endl;
   //获取平均值
    double av = getAverage(Sorta);
    //获取中位数
    double med = getMed(Sorta);
    string s = "Range: ";
   // char c = range + '0';
   string p = to_string(range);
    s += p;
    s += " Average: ";
    char k[5];
    sprintf(k,"%.2f",av);
    string sav = k;
    s += sav;
    s += " Median: ";
    sprintf(k,"%.2f",med);
    s += k;
    cout << s << endl;
    return 0;
}
