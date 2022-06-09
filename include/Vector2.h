#pragma once
class Vector2
{
private:
    int m_x;
    int m_y;

public:
    Vector2(int x, int y) : m_x(x), m_y(y){};

    void setXY(int x, int y)
    {
        m_x = x;
        m_y = y;
    };

    int getX()
    {
        return m_x;
    };
    int getY()
    {
        return m_y;
    };
};