/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-09-27 10:47:37
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-14 10:07:39
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool path_finder(string maze) {
  // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
  // starting from (0, 0) in a n × n maze (represented as a string)
  // and return a boolean value accordingly
  int sn = maze.size();
  string m;
  for (int i = 0; i < sn; ++i) {
    if (maze[i] != '\n') m += maze[i];
    else continue;
  }
  int sm = m.size();
  int n =floor(sqrt(sm));
  cout << sn << endl; 
  cout << sm << endl;
  cout << n << endl;
  vector<vector<char>>maze1(n,vector<char>(n));
  int k = 0;
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        maze1[i][j] = m[k];
        ++k;
      //  cout << maze1[i][j] << " ";
      }
  }
  vector<vector<bool>>dp(n,vector<bool>(n,false));
  for (int i = 0; i < n; ++i) {
      if(maze1[0][i] != 'W') dp[0][i] = true;
      else break;
  }
  for (int i = 0; i < n; ++i) {
    if (maze1[i][0] != 'W') dp[i][0] = true;
    else break;
  }
  // for(int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n;++j) {
  //       cout << dp[i][j]<<" ";
  //   }
  // }
  // cout << endl;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
        if (maze1[i][j] == '.') {
            if (dp[i][j-1]) dp[i][j] = true;
            if (dp[i-1][j]) dp[i][j] = true;
            //if (dp[i][j] && maze1[i-1][j-1] != 'W') dp[i-1][j-1] = true;
        }
        else dp[i][j] = false;
    }
  }
  for(int i = 1; i < n; ++i) {
    for (int j = 1; j < n;++j) {
        if(dp[i][j] && maze1[i-1][j-1] != 'W') dp[i-1][j-1] = true;
        if(dp[i][j] && maze1[i-1][j] != 'W') dp[i-1][j] = true;
    }
  }
  // cout << endl;
  return dp[n-1][n-1];
}
int main()
{
    string s = ".W...W...W...\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n...W...W...W.";
    cout << path_finder(s) << endl;
    return 0;
}