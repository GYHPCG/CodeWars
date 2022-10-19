/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-03 11:31:42
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-07 20:43:01
 */
#include <iostream>
#include <cmath>
using namespace std;

int getOne(int x) {
  //int ones = 0;
  //way1 :单纯按照逻辑那些二进制规则会超时
//   // for (int i = 32; i >= 0; --i) {
//   //       ones += (x & 1);
//   //       x = x>>1;
//   // }
  // while(x) {
  //   x -= (x & -x);
  //   ones += 1;
  // }
//way2: 找规律
  // while(x) {
    
  // }
  //return ones;
  if (x == 0) return 0;
  int t = log2(x);
  return t * pow(2,t-1) + x-pow(2,t) + 1 + getOne(x - pow(2,t));
}
long long countOnes ( int left, int right )
{
  //long long sumOnes = 0;
  // for (int i = left; i <= right; ++i) {
  //   sumOnes += getOne(i);
  // }
	return getOne(right) - getOne(left - 1);
}
int main()
{
    cout << getOne(5) << endl;
    cout << countOnes(52868585, 68127216) << endl;
    return 0;

}
