#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
typedef int info;
struct Spysok
{
    Spysok* Link,
        * Link1,
        * Link2;
    info inf;
};

int Creat(Spysok*& first, Spysok*& last, int index, int N, int i);
int COUT(Spysok*& L, info inf, int N, int index);
int Process(Spysok*& L, int k);

int main(void)
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Spysok* first = NULL;
    Spysok* last = NULL;

    int index = rand() % 6, N = 4, i = 0;
    Creat(first, last, index, N, i);

    Spysok* L = first;
    Spysok* L1 = first;
    Spysok* L2 = first;
    cout << "L: " << endl << endl;
    COUT(L, 0, N, index);
    cout << endl << endl;
    L = first;
   cout<<"кількість додатних значень: "<< Process(L,0)<<endl;
    return 0;
}

int Creat(Spysok*& first, Spysok*& last, int index, int N, int i)
{
    Spysok* tmp = new Spysok;

    tmp->inf = index;
    tmp->Link1 = NULL;
    tmp->Link2 = NULL;
    if (first == NULL)
        first = tmp;
    else
    {
        last->Link1 = tmp;
        tmp->Link2 = last;
    }
    last = tmp;

    if (i < N - 1)
        return Creat(first, last, rand() % 6, N, i + 1);
    else
        return 0;
}

int COUT(Spysok*& L, info inf, int N, int index)
{
    if (L != NULL)
    {
        inf = L->inf;
        cout << inf << "   ";
    }

    if (L != NULL)
        return COUT(L->Link1, inf, N, index + 1);
    else
        return 0;
}

int Process(Spysok*& L, int k)
{
    info inf;
    while (L != NULL)
    {
        if (L->inf > 0)
            Process(L,k+1);
        L = L->Link1;
    }
    return k;
}