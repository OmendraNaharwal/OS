#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    if (fork() == 0) {
        close(p1[1]);
        close(p2[0]);

        char file[100], c;
        read(p1[0], file, sizeof(file));

        ifstream f(file);
        while (f.get(c)) write(p2[1], &c, 1);

        close(p1[0]);
        close(p2[1]);
    } else {
        close(p1[0]);
        close(p2[1]);

        string file;
        cout << "Enter file name: ";
        cin >> file;

        write(p1[1], file.c_str(), file.size() + 1);

        char c;
        cout << "\nFile contents:\n";
        while (read(p2[0], &c, 1) > 0) cout << c;

        close(p1[1]);
        close(p2[0]);
        wait(NULL);
    }
    return 0;
}
