using namespace std;

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

vector<string>* parse(string str, vector<string> *parts) {
    // If string is empty, we are done
    if (str == "") {
        return parts;
    }

    // If starts with space, ignore and move to next char
    if (str.at(0) == ' ') {
        return parse(str.substr(1, str.length() -1), parts);
    }

    if (str.at(0) == '"') {
        int nextOccurrence = str.find_first_of('"', 1);
        parts->push_back(str.substr(1, nextOccurrence - 1));
        return parse(str.substr(nextOccurrence + 1, str.length() - 1), parts);
    }

    if (str.at(0) == '[') {
        int nextOccurrence = str.find_first_of(']', 1);
        parts->push_back(str.substr(1, nextOccurrence - 1));
        return parse(str.substr(nextOccurrence + 1, str.length() - 1), parts);
    }

    int nextOccurrence = str.find_first_of(' ');
    // End of string
    if (nextOccurrence == -1) {
        parts->push_back(str);
        return parts;
    }

    parts->push_back(str.substr(0, nextOccurrence));
    return parse(str.substr(nextOccurrence + 1, str.length() - 1), parts);
}


int main(int argc, char *argv[]) {
    vector<string> parts;
    ifstream fic;
    fic.open("../ressources/anonyme.log", ios_base::in);
    string line;

    while(getline(fic, line))
    {
        string l = line;
        vector<string> parts;
        parse(line, &parts);

        for (string p : parts) {
            cout << p << endl;
        }

        cout << "===" << endl;
    }
}
