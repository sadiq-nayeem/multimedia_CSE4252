#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream input_text;
    ofstream encoded_text;

    input_text.open("in.txt");
    encoded_text.open("encoded_text.txt");

    map <string, int> s_table;
    int i;
    string inp, s;
    char c;
    int in = 0;
    bool x = false;

    for(i = 0; i < 256; i++)
        s_table[string(1, i)] = in++;

    while(getline(input_text, inp))
    {
        //if(x) inp = '\n' + inp;
        inp += '\n';

        s = string(1, inp[0]);
        string t;
        int len = inp.size();
        i = 1;
        while(i < len)
        {
            t = string(1, inp[i]);
            if( s_table[s+t] > 0)
                s = s+t;
            else
            {
                encoded_text << s_table[s] << " ";
                s_table[s+t] = in++;
                cout << "Adding " << s+t << "  " << in-1 << endl;
                s = t;
            }
            i++;
        }
        encoded_text << s_table[s] << " ";
        x = true;

        s.clear();
        inp.clear();
    }
    //input_text.close();



    encoded_text.close();
}
