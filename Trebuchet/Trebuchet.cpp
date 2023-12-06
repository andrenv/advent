#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <string>
#include <regex>
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char** argv) {

    ifstream infile("data.txt");
    string line;
    const regex last("(\\d)(?!.*\\d)");
    const regex first("[\\d]");

    const regex last2("(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)");
    const regex first2("[\\d]|(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)");

    int total1 = 0;
    int total2 = 0;

    while (getline(infile, line))
    {
        smatch m1;
        smatch m2;
        smatch m3;

        // part 1
        regex_search(line, m1, first);
        regex_search(line, m2, last);
        
        auto first = line[m1.position()];
        auto last = line[m2.position()];

        int f = int(first - '0')*10 + int(last - '0');

        total1 += f;

        // part 2
        regex_search(line, m1, first2);
        auto aux_line = line;
        int m3_position = 0;
        int prev_len = 0;
        string m3_result;
        int m2_pos = m2.position();
        while (regex_search(aux_line, m3, last2))
        {
            m3_result = m3[0];
            if (m3_position == 0 && prev_len == 0)
            {
                m3_position += m3.position();
            }
            else 
            {
                m3_position += prev_len + m3.position();
            } 
            prev_len = m3.length();
            aux_line = m3.suffix().str();
            //cout << m3_result << " " << m3_position;
        }

        vector<string> results = { m1[0], m3_result };
        if (m2.position() > m3_position || (regex_search(aux_line, m3, last2) == 0) && (m2.position() >= m3_position))
        {
            results = { m1[0], m2[0]};
        }

        vector<int> results_int = {0, 0 };

        for (int i=0; i <= 1; i++)
        {
            if (results[i].compare("1") == 0 || results[i].compare("2") == 0 || results[i].compare("3") == 0 || results[i].compare("4") == 0 || results[i].compare("5") == 0 || results[i].compare("6") == 0 || results[i].compare("7") == 0 || results[i].compare("8") == 0 || results[i].compare("9") == 0)
            {
                auto aux = results[i][0];
                results_int[i] = int(aux - '0');
            }
            if (results[i].compare("one") == 0) { results_int[i] = 1; }
            if (results[i].compare("two") == 0) { results_int[i] = 2; }
            if (results[i].compare("three") == 0) { results_int[i] = 3; }
            if (results[i].compare("four") == 0) { results_int[i] = 4; }
            if (results[i].compare("five") == 0) { results_int[i] = 5; }
            if (results[i].compare("six") == 0) { results_int[i] = 6; }
            if (results[i].compare("seven") == 0) { results_int[i] = 7; }
            if (results[i].compare("eight") == 0) { results_int[i] = 8; }
            if (results[i].compare("nine") == 0) { results_int[i] = 9; }

        }
        std::cout << results_int[0] * 10 + results_int[1];
        std::cout << "\n";
        total2 += results_int[0] * 10 + results_int[1];
        //std::cout << total2;
        //std::cout << "\n";
        
    }

    std::cout << total2;


}