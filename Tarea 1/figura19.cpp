// figura 19

#include <vector>
#include <list>
#include <iostream>
using namespace std;


template <typename Container> void Write(const Container& ds, ostream& os)
{
    typename Container::const_iterator iter = ds.begin();
    for (; iter != ds.end(); ++iter)
        os << *iter << endl;
}

int main()
{
    list<float> mylist;
    vector<float> myvector;

    for (int i = 0; i < 10; ++i)
    {
        mylist.push_back(i);
        myvector.push_back(i + 50);
    }

    cout << "Lista" << endl;
    Write(mylist, cout); 

    cout << endl << "Vector:" << endl;
    Write(myvector, cout);

    return 0;
}
