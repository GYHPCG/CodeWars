#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int N = 100009;

struct Node
{
    int d[N];
    int len;

    Node() {memset(d, 0, sizeof(d));len=1;}
    Node(string& s)
    {
        memset(d, 0, sizeof(d));
        len = s.size();
        int i = 0;
        while(s[i] != '\0')
        {
            d[len-i-1] = s[i] - '0';
            ++i;
        }
    }

    int cmp(const Node &t)
    {
        int l = this->len - t.len;
        if(l < 0)
            return -1;

        int i;
        for(i=t.len-1;i>=0;i--)
        {
            if(this->d[i+l] < t.d[i])
                break;
            else if(this->d[i+l] > t.d[i])
            {
                return l;
            }
        }
        if(i < 0)
            return l;
        return l-1;
    }

    void change(int pos)
    {
        this->d[pos] += 1;
        int i = pos;
        while(this->d[i] > 9)
        {
            this->d[i] -= 10;
            this->d[i+1]++;
            ++i;
        }
        if(i+1 > this->len)
            this->len = i+1;
    }

    Node operator / (const Node &t)
    {
        Node ans;
        while(1)
        {
            int p = this->cmp(t);
            if(p == -1)
                break;
            else
            {
                ans.change(p);
                for(int i=0;i<t.len;i++)
                {
                    this->d[i+p+1]--;
                    this->d[i+p] = this->d[i+p]+10-t.d[i];
                    if(this->d[i+p] > 9)
                    {
                        this->d[i+p] -= 10;
                        this->d[i+1+p]++;
                    }
                }
                while(this->len > 1 && this->d[this->len - 1] == 0)
                    this->len--;
            }
        }

        return ans;
    }

};

char str[N];
vector<string> divide_strings(string a, string b) {
    Node ak(a);
    Node bk(b);
    Node ans = ak / bk;
    string sk;
    for(int i = ans.len - 1; i >= 0; --i) {
        sk += ans.d[i] + '0';
    }
    string sb;
    for (int i = ak.len - 1; i >= 0; --i) {
        sb += ak.d[i] + '0';
    }
    return vector<string>{sk,sb};

}
int main()
{
    // scanf("%s",str);
    // Node a(str);
    // scanf("%s",str);
    // // Node b(str);
    // Node ans = a / b;
    // for(int i=ans.len-1;i>=0;i--)//???
    //     printf("%d",ans.d[i]);
    // printf("\n");
    // for(int i=a.len-1;i>=0;i--)//???
    //     printf("%d",a.d[i]);
    // printf("\n");
    
    return 0;
}