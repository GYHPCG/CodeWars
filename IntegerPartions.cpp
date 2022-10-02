/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-02 13:11:32
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-02 13:43:28
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
vector<vector<ll> > Enum;
vector<ll>path;
void getEnum(ll n) {
    if(accumulate(path.begin(),path.end(),0) == n) {
        Enum.push_back(path);
        return;
    }
    for (ll i = n; i >= 1; --i) {
        path.push_back(i);
        getEnum(n - i);
        path.pop_back();
        
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
class IntPart
{
public:
  static std::string part(long long n);
};
int main()
{
    Enum.clear();
    path.clear();
    getEnum(4);
    print(Enum);
    return 0;
}
