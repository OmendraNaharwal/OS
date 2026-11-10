#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

void sortArray(int a[], int n) {
    sort(a, a+n);
}

void zombie() {
    if(fork()==0) exit(0);
    else { sleep(10); wait(NULL); }
}

void orphan() {
    if(fork()==0) {
        sleep(5);
        cout<<"Child PID: "<<getpid()<<"\nPPID: "<<getppid();
    }
    else exit(0);
}

int main() {
    int ch;
    cout<<"1.Fork Wait\n2.Zombie\n3.Orphan\n";
    cin>>ch;

    if(ch==1) {
        int n,a[20];
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];

        if(fork()==0) {
            sortArray(a,n);
            cout<<"Child: ";
            for(int x:a) cout<<x<<" ";
            exit(0);
        } else {
            sortArray(a,n);
            cout<<"Parent: ";
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            wait(NULL);
        }
    }
    else if(ch==2) zombie();
    else if(ch==3) orphan();

    return 0;
}
