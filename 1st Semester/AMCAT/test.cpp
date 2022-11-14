// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * strS is the string representing the readings noted by the scientists.
changeK is the number of changes you can make.
 */
int diffPossible(string str, int changeK, int answer = 0)
{
    int counter = changeK;
    int pos = 0;

    int cnt = 0;
    int cnt_0 = 0;
    int cnt_x = 0;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '1')
            cnt++;
        else if (str[i] == '-')
        {
            str[i] = 'X';
            cnt++;
            cnt_0++;
        }
        else if (str[i] == '0')
        {
            cnt_0++;
            if (cnt > answer)
                answer = cnt;
            cnt = 0;
            cnt_0 = 0;
        }
        if (str[i] == 'X')
            cnt_x++;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0' && counter > 0)
        {
            str[i] = '-';
            pos = i;
            counter--;
        }
        else
        {
            break;
        }
    }

    if (cnt_0 == 0)
        return answer;
    else
        diffPossible(str, changeK, answer);
}

int main()
{

    // input for strS
    // string strS;
    // getline(cin, strS);
    // // input for changeK
    // int changeK;
    // cin >> changeK;

    int result = diffPossible("01010", 3, 0);
    cout << result;

    return 0;
}
