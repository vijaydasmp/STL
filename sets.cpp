/*We are given n triangles along with length of their three sides as a,b,c.
Now we need to count number of unique triangles out of these n given triangles.
Two triangles are different from one another if they have at least one of the sides different*/

class Triangle
{

    multiset<int> sides;
    public:
    Triangle()
    {
        sides.insert(-3);
        sides.insert(-2);
        sides.insert(-1);
    }
    Triangle(int i, int j , int k)
    {
        sides.insert(i);
        sides.insert(j);
        sides.insert(k);
    }
    multiset<int> getSides()
    {
         return sides;
    }
    bool operator < (const Triangle &t1) const
    {
        return gethash() < t1.gethash();
    }

    int gethash() const
    {
        int hash = 0;
        int index = 0;
        for (auto it: sides)
        {
                hash += (++index) * it;
        }
        index = 0;
        //cout<<hash<<endl;
        return hash;
    }
    //friend ostream& operator<<(ostream&s, Triangle& t1);
};
