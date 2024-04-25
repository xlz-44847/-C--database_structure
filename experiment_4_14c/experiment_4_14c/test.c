#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct ONode {
    int row, col;
    int val;
    struct ONode *right, *down;
}ONode;

typedef struct List
{
    int rNum, cNum, t;
    ONode *rhead, *chead;
}List;

List* Init()
{
    List* ret = (List*)malloc(sizeof(List));
    scanf("%d%d", &(ret->rNum), &(ret->cNum));
    ret->rhead = ret->chead = NULL;
    return ret;
}
ONode* Create(int r, int c, int val)
{
    ONode* ret = (ONode*)malloc(sizeof(ONode));
    ret->row = r; 
    ret->col = c; 
    ret->val = val;
    ret->right = ret->down = NULL;
    return ret;
}

int main()
{
    List* plist = Init();
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    for (int i = 0; i < t1 + t2; i++)
    {
        int r = 0, c = 0, val = 0;
        scanf("%d%d%d", &r, &c, &val);
        ONode* tmp = Create(r, c, val);
        ONode* cur = plist->rhead;
        ONode* prev = NULL;
        if (cur == NULL)
        {
            plist->rhead = tmp;
            continue;
        }
        while (cur != NULL)
        {
            prev = cur;
            if (prev->row == r && prev->col == c)
            {
                prev->val += val;
                break;
            }
            cur = cur->right;
            if (cur != NULL && r * 20 + c > (prev->row) * 20 + (prev->col) && r * 20 + c < (cur->row) * 20 + (cur->col))
            {
                prev->right = tmp, tmp->right = cur;
                break;
            }
        }
        if(cur==NULL)
        {
            prev->right = tmp;
        }
    }
    ONode* cur = plist->rhead;
    while (cur != NULL)
    {
        printf("%d %d %d\n", cur->row, cur->col, cur->val);
        cur = cur->right;
    }
}