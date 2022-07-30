#include <vector>
#include <iostream>

int sum(const std::vector<int>& v)
{
    int result{ 0 };
    for (auto&& i : v) {
        result += i;
    }
    return result;
}

int main()
{
    std::vector<int> v{ 200,100,16,29,30,55 };
    std::cout << sum(v) << std::endl;
    return EXIT_SUCCESS;
}
