#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

int main()
{
    int arr[100][100];
    int n;
    int src = 0,dst = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d%d", &src, &dst);
    int way[100][100];  //最短路径
    int minm[100];  //最短路径大小
    bool flag[100]; //是否包含
    for (int i = 0; i < n; i++) //初始化
    {
        for (int j = 0; j < n + 1; j++)
            way[i][j] = -1;
        minm[i] = arr[src][i];
        flag[i] = false;
        if (minm[i] != 10000)
        {
            way[i][0] = src;
            if (i != src)
            {
                way[i][1] = i;
            }
        }
    }
    flag[src] = true;
    for (int i = 0; i < n; i++)
    {
        int mini = src;   //当前最短路径树的最小位置
        for (int j = 0; j < n; j++) //寻找最小且未被包含的位置
        {
            if ((minm[mini] > minm[j] || minm[mini] == 0) && flag[j] == false) mini = j;
        }
        for (int k = 0; k < n; k++) //此时以mini为拓展，比较是否为最短，k则是由mini去比较的结点
        {
            //满足条件即可更新：①不是自己；②结点未被包含；③选取的最小结点必须可到达（即不能是无穷）；④存在新的路线小于原路线即可更新
            if (arr[mini][k] != 0 && flag[k] == false && minm[mini] != 10000 && minm[mini] + arr[mini][k] < minm[k])
            {
                minm[k] = minm[mini] + arr[mini][k];
                int m = 0;
                for (; way[mini][m] != -1; m++)
                {
                    way[k][m] = way[mini][m];
                }
                way[k][m] = k;
            }
        }
        flag[mini] = true;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", minm[i]);
    }
    for (int i = 0; way[dst][i] != -1; i++)
    {
        printf("%d\n", way[dst][i]);
    }
}