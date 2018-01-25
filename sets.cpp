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
};
void set_pratice()
{
    set<Triangle> TriangleSet;

    Triangle t1(1,2,3);
    Triangle t2(3,4,5);
    Triangle t3(5,6,7);
    Triangle t4(3,4,5);
    Triangle t5(13,4,5);


    t1.gethash();
    t2.gethash();
    t3.gethash();
    t4.gethash();


    TriangleSet.insert(t1);
    TriangleSet.insert(t2);
    TriangleSet.insert(t3);
    TriangleSet.insert(t4);
    TriangleSet.insert(t5);

    cout<<TriangleSet.size();
   // cout<<"Size = "<<TriangleSet.size();
}
