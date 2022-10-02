/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-01 09:58:30
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-01 10:06:25
 */

/*Create two functions to encode and then decode a string using the Rail Fence Cipher. This cipher is used to encode a string by placing each character successively in a diagonal along a set of "rails". First start off moving diagonally and down. When you reach the bottom, reverse direction and move diagonally and up until you reach the top rail. Continue until you reach the end of the string. Each "rail" is then read left to right to derive the encoded string.*/

#include <string>
using namespace std;
std::string encode_rail_fence_cipher(const std::string &str, int n) {
    int n = str.size();
    if (n == 0) return "";
    string s1;
    for (int i = 0; i < n; i += (n+1)) {

    }

}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
    int n = str.size();
    if (n == 0) return "";
    
  
}
int main()
{


    return 0;
}