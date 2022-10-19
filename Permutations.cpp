/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-01 10:19:44
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-01 11:34:30
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//方法1，求全排列，用回溯算法
vector<string>res;
/*string path;
void backTrack(string& s, vector<bool>& used) {
    if (path.size() == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < (int) s.size(); ++i) {
        if (i > 0 && s[i] == s[i-1] && used[i-1] == true) continue;
        if(used[i] == false) {
            used[i] = true;
            path += s[i];
            backTrack(s,used);
            used[i] = false;
            path.pop_back();
        }
    }
}*/
//方法二，调用库函数求排列
//2. 调用库函数

 /* ==**std::next_permutation**====(**first,last**)==

   它用于将[first, last]范围内的元素重新排列到下一个字典上更大的排列。排列是N的每一个！元素可以采用的可能排列方式(其中N是范围内的元素数量)。可以根据它们在字典上的比较方式来排序不同的排列。

3. ==**std**::**prev_permutation(first,last)**==

   它用于将[first, last)范围内的元素重新排列为上一个按字典顺序排列的排列。排列是N的每一个！元素可以采用的可能排列方式(其中N是范围内的元素数量)。可以根据它们在字典上的比较方式来排列不同的排列顺序*/

void Next_permutation(string s) {
    //next_permutation(first,end),每次只能找到比当前排列下一个的排列
    //所以，要想获得所有的全排列，必须先sort(),然后循环里找。
    sort(s.begin(),s.end());
    do {
        res.push_back(s);
    } while(next_permutation(s.begin(),s.end()));
    //return res;
}
std::vector<std::string> permutations(std::string s) {
  // Your code here
    int n = s.size();
    //先排序
    sort(s.begin(),s.end());

   // vector<bool>used(n,false);

    //backTrack(s,used);
    return res;
}
int main()
{

    string s{"rbhr"};
    //cout << permutations(s) << endl;
    //排序去重
    //sort(s.begin(),s.end());
    //permutations(s);

    Next_permutation(s);
    cout << res.size() << endl;
    for (int i = 0; i < res.size();++i) {
        cout << res[i] << endl;
    }
    return 0;
}