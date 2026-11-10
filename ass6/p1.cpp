#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main() {
    mkfifo("p1", 0666);
    mkfifo("p2", 0666);

    int a = open("p1", O_WRONLY);
    string s;
    while (getline(cin, s)) {
        write(a, s.c_str(), s.size() + 1);
        if (s == "END") break;
    }
    close(a);

    a = open("p2", O_RDONLY);
    char c;
    while (read(a, &c, 1) > 0) cout << c;
    close(a);
}
