#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream encoded_text;
    ofstream decoded_text;

    encoded_text.open("encoded_text.txt");
    decoded_text.open("decoded_text.txt");

    map <int, string> s_table;
    int i, k, old, nw;
    string s;
    char c;
    int in = 0;
    for(i = 0; i < 256; i++)
        s_table[in++] = string(1, i);

    encoded_text >> k;
    old = k;
    decoded_text << s_table[old];
    i = 0;
    while(encoded_text >> k)
    {
        nw = k;
        if( s_table.count(nw) == 0 )         // Exists
        {
            s = s_table[old];
            s = s+c;
        }
        else
        {
            s = s_table[nw];
        }
        decoded_text << s ;
        c = s[0];

        s_table[in++] = s_table[old] + c;
        cout << "Adding " << in-1 << "  " << s_table[old] + c << endl;
        old = nw;
    }
    encoded_text.close();
    decoded_text.close();
}
