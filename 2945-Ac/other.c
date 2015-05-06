#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
int const childnum = 4;  
  
const int map[] = {  
    0, -1, 1, -1, -1, -1, 2,  
    -1, -1, -1, -1, -1, -1,  
    -1, -1, -1, -1, -1, -1, 3  
};  
  
struct node {  
    node* child[childnum];  
    int times;  
    bool isstop;  
    node(): times(0), isstop(false) {  
        memset(child, NULL, sizeof (child));  
    }  
};  
  
const int peoplenum = 20010;  
const int DNAlen = 21;  
int rec[peoplenum];  
char str[peoplenum][DNAlen];  
node* save_stop_node[peoplenum];  
int k = 0; //index for save_stop_node  
  
void free(node *r)  
{  
    for (int i = 0; i != childnum; i++) {  
        if (r->child[i] != NULL)  
            free(r->child[i]);  
    }  
    delete r;  
}  
  
void insert(node *p, char *s)  
{  
    for (int i = 0; s[i]; i++) {  
        int idx = map[s[i]-'A'];  
        if (p->child[idx] == NULL) {  
            p->child[idx] = new node;  
        }  
        p = p->child[idx];  
    }  
    if (p->isstop == true) {  
        (p->times++);  
        return;  
    }  
    p->isstop = true;  
    save_stop_node[k++] = p;  
    p->times = 1;  
}  
  
int main()  
{  
    int n, m;  
    while (scanf("%d%d", &n, &m), n || m) {  
        node *r = new node;  
        for (int i = 0; i != n; i++) {  
            scanf("%s", str[i]);  
            insert(r, str[i]);  
        }  
        memset(rec, 0, sizeof (rec));  
        for (int i = 0; i != k; i++)  
            rec[save_stop_node[i]->times]++;  
        for (int i = 1; i != n+1; i++) {  
            printf("%d\n", rec[i]);  
        }  
        free(r); //POJ2945，把free(r)注释掉运行更快，但内存消耗变大，还好不会MLE  
        k = 0;  
    }  
    return 0;  
}  
