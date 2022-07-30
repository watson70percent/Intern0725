#include <iostream>

/* class Point2のオペレータをオーバーロードし，各要素の加減算ができるようにしてみよう。
 * また比較オペレータもオーバーロードしてみよう。
 */

class Point2
{
public:
    Point2()
    {
        m_x = 0;
        m_y = 0;
    }

    Point2(int32_t x, int32_t y)
    {
        m_x = x;
        m_y = y;
    }

    ~Point2()
    {
    }

    Point2 operator+(const Point2& rhs)
    {
        // TODO: 実装してください
        Point2 ans;
        ans.m_x = this->m_x + rhs.m_x;
        ans.m_y = this->m_y + rhs.m_y;
        return ans;
    }

    Point2 operator-(const Point2& rhs)
    {
        // TODO: 実装してください
        Point2 ans;
        ans.m_x = this->m_x - rhs.m_x;
        ans.m_y = this->m_y - rhs.m_y;
        return ans;
    }

    const Point2& operator=(const Point2& rhs)
    {
        // TODO: 実装してください
        Point2 ans;
        this->m_x = rhs.m_x;
        this->m_y = rhs.m_y;
        return *this;
        //代入だからthisの中身を変えて大丈夫
    }

    // TODO: operator == も実装してください。
    bool operator==(const Point2& rhs) {
        bool ans = true;
        if (this->m_x != rhs.m_x)ans = false;
        if (this->m_y != rhs.m_y)ans = false;
        return ans;
    }

    void Print()
    {
        std::cout << m_x << "," << m_y << std::endl;
    }
private:
    int32_t m_x;
    int32_t m_y;
};

// mainは編集する必要ありません。
int main()
{
    Point2 a(1,2);
    Point2 b(3,4);
    Point2 add(4,6);
    Point2 sub(-2,-2);
    
    Point2 c = a + b;
    Point2 d = a - b;

    std::cout << "operator + ";
    if (c == add) {
        std::cout << "ok." << std::endl;
    }else{
        std::cout << "error." << std::endl;
    }

    std::cout << "operator - ";
    if (d == sub) {
        std::cout << "ok." << std::endl;
    }else{
        std::cout << "error." << std::endl;
    }

    a.Print();
    b.Print();
    c.Print();
    d.Print();

    a = b = c = d;

    std::cout << "operator = ";
    
    if (a == d) {
        std::cout << "ok." << std::endl;
    }
    else {
        std::cout << "error." << std::endl;
    }

    return EXIT_SUCCESS;
}
