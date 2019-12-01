#include <iostream>

using namespace std;

int calculate_fuel(int a)
{
    a /= 3;
    a -= 2;
    if (a <= 0)
        return 0;
    else
        return a + calculate_fuel(a);
}

int main(int argc, char const *argv[])
{
    int sum = 0;
    int temp;

    for (short i = 0; i < 100; i++)
    {
        cin >> temp;
        sum += calculate_fuel(temp);
    }

    cout << sum;

    return 0;
}
