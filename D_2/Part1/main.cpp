#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> tab;
    int temp;
    do
    {
        cin >> temp;
        tab.push_back(temp);
    } while (temp != -97);

    int index = 0;
    while (tab[index] != 99)
    {
        if (tab[index] == 1)
        {
            tab[tab[index + 3]] = tab[tab[index + 1]] + tab[tab[index + 2]];
        }
        if (tab[index] == 2)
        {
            tab[tab[index + 3]] = tab[tab[index + 1]] * tab[tab[index + 2]];
        }
        index += 4;
    }
    //cout << tab[0];

    return 0;
}
