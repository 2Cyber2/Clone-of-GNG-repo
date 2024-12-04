#pragma once

namespace fw {
    void TestVec2();

    class ivec2
    {
    public:
        int x = 0;
        int y = 0;
    };

    class vec2
    {
    public:
        vec2();
        vec2(float x, float y);
        vec2(float xy);

        float length() const;
        float dot(vec2 a) const;
        
        vec2 operator+(const vec2& o) const { return vec2(x + o.x, y + o.y); }
        vec2 operator-(const vec2& o) const { return vec2(x - o.x, y - o.y); }
        vec2 operator*(const vec2& o) const { return vec2(x * o.x, y * o.y); }

        vec2 operator*(float o) const { return vec2(x * o, y * o); }
        vec2 operator/(vec2& o) const { return vec2(x / o.x, y / o.y); }


        //vec2& c = a += b
        vec2& operator+=(const vec2& o) { x += o.x;  y += o.y; return *this; }
        vec2& operator-=(const vec2& o) { x -= o.x;  y -= o.y; return *this; }

        void normalize()
        {
            float len = length();
            if (len == 0)
                return;
            x /= len;
            y /= len;
        }

    public:
        float x = 0;
        float y = 0;
    };

} // namespace fw
