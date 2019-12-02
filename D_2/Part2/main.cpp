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

    vector<int> tab2 = tab;

    for (short i = 0; i < 100; i++)
    {
        for (short j = 0; j < 100; j++)
        {
            tab = tab2;
            tab[1] = i;
            tab[2] = j;
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
            if (tab[0] == 19690720)
                cout << i * 100 + j;
        }
    }

    return 0;
}
