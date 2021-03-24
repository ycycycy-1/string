#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn = 1e5+5;
const int mx = 40;
const int mod = 1e9+5;
const ll inf = 34359738370;
const int INF = 1e9+5;
//马拉车算法  首先对s进行预处理成str （ab->$#a#b）
//利用回文串的轴对称性,设立一个中心标的物id ，以及id为中心的回文串向右最远到达位置的后一格mx
//利用id来更新[id,mx)区间上，任意一个点作为中心得到的最大回文子串，同时不断更新id和对应的mx
//最终str中的p[i]-1就是原字符串的回文子串长度
char s[maxn], str[maxn * 2];
int length1[maxn];
int length2[maxn];
int Init() //预处理
{
    int len = strlen(s);
    str[0] = '$', str[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        str[j++] = s[i];
        str[j++] = '#';
    }
    str[j] = 0;
    return j;
}
int manacher() //返回最长回文串长度
{
    int len = Init();
    int p[maxn * 2]; //设p[i]为str中,以i为中心的最大回文串半径
    int id = 0, mx = 0;
    int ans = 1;
    for (int i = 1; i <= len; i++)
    {
        int left_i = 2 * id - i; //i关于id的轴对称点，利用他来加速查找
        if (i < mx)
            p[i] = min(p[left_i], mx - i); //首先是最大不能超过mx-i，再更具id左右对称,left_i的就是i的
        else
            p[i] = 1;
        while (str[i - p[i]] == str[i + p[i]])
            p[i]++; //右边界是'\0'所以不用特判
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
        ans = max(ans, p[i] - 1);
    }
    for (int i = 0; i <= len; i++)
        printf("%d ", p[i]);
    int begin_len = strlen(s);
    //以某个元素位置为中心的最长奇数回文串
    for (int i = 0; i < len; i++)
    {
        length1[i] = p[(i + 1) * 2] - 1;
    }
    //偶数回文串，i为左中间位置  如abba   $#a#b#b#a#,length2[1]就是 p[5]-1=4
    for (int i = 0; i < len; i++)
    {
        length2[i] = p[(i + 1) * 2 + 1] - 1;
    }
    cout << '\n';
    return ans;
}
int main()
{
    scanf("%s", s);
    int ans = manacher();
    cout << ans;
    return 0;
}
