#include "Vector.h"
#include <assert.h>
#include <math.h>


namespace fw
{
    void TestVec2()
    {
        float f1 = 8;
        float f2 = 9;
        float& f3 = f1 += f2;



        vec2 a;
        assert(a.x == 0 && a.y == 0);

        const vec2 b(6, 9);
        assert(b.x == 6 && b.y == 9);

        b.length();

        vec2 c(1);
        assert(b.x == 1 && b.y == 1);

        vec2 d = b + c;
        assert(d.x == 7 && d.y == 10);

        float len = c.length();
        assert(len == sqrt(2.0f));

        float p = b.dot(c);
        assert(p == 15);

        float z = b.dot(c);
        assert(z == 132);
    }


    vec2::vec2()
    {
    }

    vec2::vec2(float x, float y) :
        x(x),
        y(y)
    {
    }

    vec2::vec2(float xy) :
        x(xy),
        y(xy)
    {
    }


    float vec2::length() const
    {
        return (float)sqrt(x*x + y*y);
    }

    float vec2::dot(vec2 a) const
    {
        return (x * a.x) + (y * a.y);
    }
}
