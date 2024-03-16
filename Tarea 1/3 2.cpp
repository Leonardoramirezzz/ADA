//3.2

#include <iostream>
using namespace std;

struct cvec {

    int* vec;
    int count = 0;
    int max = 0;
    int delta = 10;

    cvec(int initialSize = 10, int growthDelta = 10) : count(0), max(initialSize), delta(growthDelta) {
        vec = new int[max];
    }

    void Resize(cvec* pthis) {
        int* ptemp;
        ptemp = new int[pthis->max + pthis->delta];
        for (int i = 0; i < pthis->max; i++) ptemp[i] = pthis->vec[i];
        delete [] pthis->vec;
        pthis->vec = ptemp;
        pthis->max += pthis->delta;
    }

    void Insert(cvec *pthis, int elem) {
        if (pthis->count == pthis->max) Resize(pthis);
        pthis->vec[pthis->count++] = elem;
    }

    void print(cvec* pthis) {
        for (int i = 0; i < pthis->count; i++) cout << pthis->vec[i] << " ";
    }
};


int main() {
    cvec Vec1;
    cvec Vec2;

    for (int i = 0; i < 20; i++) Vec1.Insert(&Vec1, i);
    Vec1.print(&Vec1);
}
