/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-08 16:07:06
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-08 17:52:05
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

constexpr int Maxsize = 1000;
using ull = unsigned long long;
struct num {
    int number[Maxsize];
    int len = 0;
    num() {
        memset(number,0,sizeof(number));
        len = 0;
    }
};
num getInteger(const string& x) {
    num In;
    int n = x.size();
    for (int i = 0; i < n; ++i) {
        In.number[i] = x[i] -'0';
        In.len++;
    }
    return In;
}
vector<string> divide_strings(string a, string b) {
    num res;
    num In = getInteger(a);
    ull Ib = stoull(b);
    ull r = 0;
    for (int i = 0; i < In.len; ++i) {
            r = r * 10 + In.number[i];
        if (r < Ib) {
            res.number[i] = 0;
            r = r % Ib;
        }
        else {
            res.number[i] = r / Ib;
            r = r % Ib;
        }
        //r = r *    
    }
    // cout << "res: " << endl;
    // for (int i = 0; i < In.len; ++i) {
    //     cout << res.number[i];
    // }
    // cout << endl;
    // ull Ia = 0;
    // for (int i = 0; i < In.len; ++i) {
    //     Ia = Ia * 10 + res.number[i];
    // }
    //Ia = Ia + In.number[In.len - 1];
    string Ia;
    for (int i = 0; i < In.len; ++i) {
        Ia += res.number[i] + '0';
    }
   if (Ia.size() > 1) {
        for (int i = 0; i < Ia.size();) {
            if (Ia[i] == '0') {
                Ia.erase(i,1);
                i = i;
            }
            else break;
        }
   }
   cout <<Ia << endl;
    return vector<string>{Ia,to_string(r)};
     

   //数据太大，调用库函数失败
  //return vector<string> {to_string(stoull(a, nullptr, 10) / stoull(b, nullptr, 10)), //to_string(stoull(a, nullptr, 10) % stoull(b, nullptr, 10))}; // This might work for the sample tests and maybe even half of the random tests but it won't work for arbitrarily large integers ;-)
}

int main()
{
    // string a{"71096879055141582785973534560117092584759022480985225328375429033018723094424797115751452014799063318746881871883529532855863659499877613304091362837224962350"};
    // string b{"3670781597954921910054293799691"};
    string a{"18446744073709551616"};
    string b{"8293849282123"};
    vector<string>res{divide_strings(a,b)};
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;

}
