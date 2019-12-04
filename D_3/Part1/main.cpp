#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>
#include <math.h>

using namespace std;

struct Move
{
    char direction;
    int distance;
};

vector<Move> split_string(vector<Move> line, string input)
{
    int pos1 = 0, leng;
    do
    {
        leng = input.substr(pos1, string::npos).find(",");
        if (leng == -1)
            line.push_back({input.substr(pos1, string::npos)[0], stoi(input.substr(pos1, string::npos).substr(1, string::npos))});
        else
            line.push_back({input.substr(pos1, leng)[0], stoi(input.substr(pos1, leng).substr(1, leng))});
        pos1 += leng + 1;
    } while (leng >= 0);

    return line;
}

vector<vector<char>> create_tab(vector<vector<char>> tab, vector<Move> moves)
{
    int x = 0, y = 0;

    for (int i = 0; i < moves.size(); i++)
    {
        int licz = 0;
        //cout << "Move";
        switch (moves[i].direction)
        {
        case 'D':
            for (int k = 0; k < moves[i].distance; k++)
            {
                //cout << "D";
                if (y + 1 >= tab[x].size())
                {
                    for (int l = 0; l < tab.size(); l++)
                    {
                        tab[l].push_back('.');
                    }
                }
                y++;
                tab[x][y] = 'c';
            }
            break;
        case 'U':
            for (int k = 0; k < moves[i].distance; k++)
            {
                //cout << "U";
                if (y - 1 < 0)
                {
                    for (int l = 0; l < tab.size(); l++)
                    {
                        tab[l].insert(tab[l].begin(), '.');
                    }
                }
                else
                {
                    y--;
                }
                tab[x][y] = 'c';
            }
            break;
        case 'R':
            for (int k = 0; k < moves[i].distance; k++)
            {
                //cout << "R";
                if (x + 1 >= tab.size())
                {
                    tab.push_back(vector<char>(tab[x].size(), '.'));
                }
                x++;
                tab[x][y] = 'c';
            }
            break;
        case 'L':
            for (int k = 0; k < moves[i].distance; k++)
            {
                //cout << "L";
                if (x - 1 < 0)
                {
                    tab.insert(tab.begin(), vector<char>(tab[x].size(), '.'));
                }
                else
                {
                    x--;
                }
                tab[x][y] = 'c';
            }
            break;
        }
    }
    return tab;
}

void print_tab(vector<vector<char>> tab)
{
    for (int i = 0; i < tab.size(); i++)
    {
        cout << endl;
        for (int j = 0; j < tab[i].size(); j++)
        {
            cout << tab[i][j];
        }
    }
}

vector<int> find_o(vector<vector<char>> tab)
{
    for (int i = 0; i < tab.size(); i++)
    {
        for (int j = 0; j < tab[i].size(); j++)
        {
            if (tab[i][j] == '0')
            {
                vector<int> answer{i, j};
                return answer;
            }
        }
    }
    return {-1, -1};
}

int find_distance_to_intersect(vector<vector<char>> tab1, vector<int> pos1, vector<vector<char>> tab2, vector<int> pos2)
{
    int rad = 1, x, y;
    for (int i = 0; i < 2; i++)
    {
        if (pos1[i] == -1 || pos2[i] == -1)
            return -1;
    }
    while (pos1[0] + rad < tab1.size() || rad <= pos1[0] || pos1[1] + rad < tab1[pos1[0]].size() || rad <= pos1[1] || pos2[0] + rad < tab2.size() || rad <= pos2[0] || pos2[1] + rad < tab2[pos2[0]].size() || rad <= pos2[1])
    {
        for (int i = 0; i <= rad; i++)
        {
            if (pos1[0] - i >= 0 && pos1[1] - (rad - i) >= 0 && pos2[0] - i >= 0 && pos2[1] - (rad - i) >= 0)
            {
                if (tab1[pos1[0] - i][pos1[1] - (rad - i)] == 'c' && tab2[pos2[0] - i][pos2[1] - (rad - i)] == 'c')
                {
                    return rad;
                }
            }
            if (pos1[0] + i < tab1.size() && pos1[1] - (rad - i) >= 0 && pos2[0] + i < tab2.size() && pos2[1] - (rad - i) >= 0)
            {
                if (tab1[pos1[0] + i][pos1[1] - (rad - i)] == 'c' && tab2[pos2[0] + i][pos2[1] - (rad - i)] == 'c')
                {
                    return rad;
                }
            }
            if (pos1[0] - i >= 0 && pos1[1] + i < tab1[pos1[0]].size() && pos2[0] - i >= 0 && pos2[1] + i < tab2[pos2[0]].size())
            {
                if (tab1[pos1[0] - i][pos1[1] + (rad - i)] == 'c' && tab2[pos2[0] - i][pos2[1] + (rad - i)] == 'c')
                {
                    return rad;
                }
            }
            if (pos1[0] + i < tab1.size() && pos1[1] + i < tab1[pos1[0]].size() && pos2[0] + i < tab2.size() && pos2[1] + i < tab2[pos2[0]].size())
            {
                if (tab1[pos1[0] + i][pos1[1] + (rad - i)] == 'c' && tab2[pos2[0] + i][pos2[1] + (rad - i)] == 'c')
                {
                    return rad;
                }
            }
        }
        rad++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Move> linemov1;
    vector<Move> linemov2;
    string line1, line2;
    std::cin >> line1 >> line2;

    linemov1 = split_string(linemov1, line1);
    linemov2 = split_string(linemov2, line2);

    vector<vector<char>> tab1(1, vector<char>(1, '0'));
    vector<vector<char>> tab2(1, vector<char>(1, '0'));

    tab1 = create_tab(tab1, linemov1);
    tab2 = create_tab(tab2, linemov2);

    //print_tab(tab1);
    //print_tab(tab2);
    vector<int> point1 = find_o(tab1);
    vector<int> point2 = find_o(tab2);

    cout << find_distance_to_intersect(tab1, point1, tab2, point2);

    return 0;
}