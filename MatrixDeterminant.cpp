/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-09-29 15:38:53
 * @LastEditors: CGPan
 * @LastEditTime: 2022-09-29 19:38:52
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//实现计算n阶行列式
vector<vector<long long>> getNext(int row,int col, vector<vector<long long>> m) {
    int Nrow = m.size();
    vector<vector<long long>>next(Nrow - 1,vector<long long>(Nrow-1,0));
    for (int i = 0,i1 = 0; i < Nrow; ++i) {
    for (int j = 0,j1 = 0; j < Nrow; ++j) { 
        if (i != row && j != col) {
            next[i1][j1] = m[i][j];
            if (j1 == Nrow - 2) {
                ++i1;
                j1 = 0;
            }
            if ( j1 < Nrow - 2) {
                ++j1;
            }
        }
    }
  }
   return next;
}
long long determinant(vector< vector<long long> > m) {
  // TODO: Return the determinant of the square matrix passed in
    long long res = 0;
    int Nrow = m.size();
    if (Nrow == 1) return m[0][0];
    if (Nrow == 2) return m[Nrow - 2][Nrow-2] * m[Nrow-1][Nrow-1] - m[Nrow-2][Nrow-1] * 
    m[Nrow-1][Nrow-2];
    for (int i = 0; i < Nrow; ++i) {
        //每次都对第一行进行降阶
        //然后得到的阶必定没有第一行和第i列的value
        //本次卡在这个地方
        res += m[0][i] * pow(-1,i) * determinant(getNext(0,i,m));
    }
    return res;
}
using namespace std;

int main()
{
    vector<vector<long long>>matrix(3,vector<long long>(3,0));
    for (int i = 0; i < 3;++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << determinant(matrix) << endl;
    return 0;

}
