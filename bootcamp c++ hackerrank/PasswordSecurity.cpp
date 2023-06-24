#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getMinFlips' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING pwd as parameter.
 */




int getMinFlips(string pwd) {

    int count = 0;
    for (int i = 0; i < pwd.size(); i++) {
        if (pwd[i] == '0') {
            count++;
        }
    }
    if (count == 0 || count == pwd.size()) {
        return 0;
    }
    int minFlips = min(count, (int)pwd.size() - count);
    int flips = 0;
    for (int i = 0; i < pwd.size(); i++) {
        if (pwd[i] == '0') {
            flips++;
        }
        else {
            flips--;
        }
        minFlips = min(minFlips, flips);
    }
    return minFlips;



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pwd;
    getline(cin, pwd);

    int result = getMinFlips(pwd);

    fout << result << "\n";

    fout.close();

    return 0;
}
