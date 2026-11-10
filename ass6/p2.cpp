#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {
    int a = open("p1", O_RDONLY);
    char c;
    string s;
    int ch = 0, w = 0, l = 0;

    while (read(a, &c, 1) > 0) {
        if (c == '\0') {
            if (s == "END") break;
            ch += s.size();
            stringstream ss(s);
            string x;
            while (ss >> x) w++;
            l++;
            s.clear();
        } else s += c;
    }
    close(a);

    ofstream f("out.txt");
    f << "Characters: " << ch << "\nWords: " << w << "\nLines: " << l;
    f.close();

    a = open("p2", O_WRONLY);
    ifstream in("out.txt");
    while (in.get(c)) write(a, &c, 1);
    close(a);
}
