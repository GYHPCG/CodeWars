/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-09-30 15:01:40
 * @LastEditors: CGPan
 * @LastEditTime: 2022-09-30 18:47:54
 */
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
//The longest common subsequence (LCS) problem is the problem of finding the longest       subsequence common to all sequences in a set of sequences.
//It differs from problems of finding common substrings: unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.
using namespace std;

string lcs(const string& x, const string& y)
{
    string x1 =" "+ x;
    string y1 =" "+ y;
    int n1 = x.size();
    int n2 = y.size();
    vector<vector<string>> dp(n1+1,vector<string>(n2+1,""));
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            string k = dp[i-1][j-1];
            k += x1[i];
            if (x1[i] == y1[j]) dp[i][j] = k;
            else {
                dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j]: dp[i][j-1];
            }
        }
    }
    return dp[n1][n2];
}

int main()
{
    string s1 = "anothertest";
    string s2 = "notatest";
    //s1 = s2;
    cout << lcs(s1,s2) << endl;


    return 0;
}