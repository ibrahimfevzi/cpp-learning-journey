#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'Paragraph' class below.
 * 
 * Paragraph(string text, int width)
 * output()
 * 
 */
class Paragraph {
public:
    vector<string> paragraph;

    Paragraph(string text, int width) {
        wrapText(text, width);
    }

    void wrapText(const string& text, int width) {
        int i = 0;
        while (i < text.size()) {
            string line = "";
            while (i < text.size() && line.size() < width) {
                if (text[i] == ' ') {
                    if (line.size() + 1 == width) {
                        break;
                    }
                    line += text[i];
                }
                else {
                    line += text[i];
                }
                i++;
            }
            paragraph.push_back(line);
       
        }
    }

    vector<string> output() {
        return paragraph;    }
};

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string text;
    getline(cin, text);

    string width_temp;
    getline(cin, width_temp);

    int width = stoi(ltrim(rtrim(width_temp)));
    Paragraph object(text,width);
    vector<string> result = object.output();

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


/*output :
 text
rapp
ngis
un 

ama aslında şöyle olmalıydı:
text
wrap
ping
isfu
n
*/




