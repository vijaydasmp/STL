#include "vectors.h"
#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

int increment(int x)
{
    return (x+1);
}

class incremento
{
    int step;
public:
    incremento(int i)
    {
        step = i;
    }
    int operator()(int x)
    {
        return x+step;
    }

};
bool myfunction (int i,int j) { return (i>j); }

void vector_practice()
{
    vector<int> intvect = {1,2,3,4,5,6};
    cout<<intvect.capacity();
    cout<<endl;
    cout<<intvect.size();
    cout<<endl;
    // display to output stream
    std::copy(intvect.begin(),intvect.end(),std::ostream_iterator<int>(std::cout," "));

    // Transform
    std::transform(intvect.begin(),intvect.end(),intvect.begin(),increment);
    cout<<endl;
    std::copy(intvect.begin(),intvect.end(),std::ostream_iterator<int>(std::cout," "));

    // functor
    std::transform(intvect.begin(),intvect.end(),intvect.begin(),incremento(10));
    cout<<endl;
    std::copy(intvect.begin(),intvect.end(),std::ostream_iterator<int>(std::cout," "));

    // sort
    std::sort(intvect.begin(),intvect.end(),myfunction);
    cout<<endl;
    std::copy(intvect.begin(),intvect.end(),std::ostream_iterator<int>(std::cout," "));

    // sort with lambda function
    std::sort(intvect.begin(),intvect.end(),[](const int x, const int y) { return x > y;});
    cout<<endl;
    std::copy(intvect.begin(),intvect.end(),std::ostream_iterator<int>(std::cout," "));

    // erase remove idiom , since remove algorithm
    intvect.erase(std::remove(intvect.begin(),intvect.end(),15),intvect.end());
    cout<<endl;
    std::copy(intvect.begin(),intvect.end(),std::ostream_iterator<int>(std::cout," "));

    auto it = std::find(intvect.begin(),intvect.end(),12);
    cout<<"\n"<<*it;

    // auto loops
    cout<<"\n";
    for(const int &it: intvect)
            cout<<it<<endl;
    
    intvect.
}

