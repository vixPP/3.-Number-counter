#include <iostream>
#include <vector>
#include<algorithm>


class DivisibleByThree
{
public:
    DivisibleByThree() : sum(0), count(0) {}

    void operator()(int num)
    {
        if (num % 3 == 0)
        {
            sum += num;
            count++;
        }
    }

    int get_sum() const { return sum; }
    int get_count() const { return count; }

private:
    int sum;
    int count;
};

int main()
{
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i];
        if (i < numbers.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    DivisibleByThree functor = std::for_each(numbers.begin(), numbers.end(), DivisibleByThree());

    std::cout << "[OUT]: get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << functor.get_count() << std::endl;

    return 0;
}