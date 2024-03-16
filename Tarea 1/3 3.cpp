//3.3

#include <iostream>
using namespace std;

class CVector
{
private:
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta) {
        m_pVect = nullptr;
        m_nCount = 0;
        m_nMax = 0;
        m_nDelta = delta;
    }

    void Resize() {
        int* pTemp = new int[m_nMax + m_nDelta];
        for (int i = 0; i < m_nCount; ++i) {
            pTemp[i] = m_pVect[i];
        }
        delete[] m_pVect;
        m_pVect = pTemp;
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10) {
        Init(delta);
    }

    ~CVector() {
        delete[] m_pVect;
    }

    void Insert(int elem) {
        if (m_nCount == m_nMax) Resize();
        m_pVect[m_nCount++] = elem;
    }

    void Print() const {
        for (int i = 0; i < m_nCount; ++i) cout << m_pVect[i] << " ";
        cout << endl;
    }

};

int main() {
    CVector vec;
    for (int i = 0; i < 20; ++i) vec.Insert(i);
    vec.Print();
    return 0;
}
