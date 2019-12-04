#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool apply_criteria(int x)
{
    string y = to_string(x);
    int size = y.size();
    bool pair = false;
    for (int i = 1; i < size; i++)
    {
        if (y[i - 1] > y[i])
            return false;
        if (y[i - 1] == y[i])
            pair = true;
    }
    return true && pair;
}
int main()
{
    int counter;
    int border1, border2;
    cin >> border1 >> border2;
    for (int i = border1; i < border2; i++)
    {
        if (apply_criteria(i))
            counter++;
    }
    cout << counter;

    return 0;
}