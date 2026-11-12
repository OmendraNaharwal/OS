#include <bits/stdc++.h>
using namespace std;

void SSTF(vector<int> a, int head) {
    int h=head,total=0;
    cout<<"\nSSTF: "<<h;

    while(!a.empty()) {
        int k=0;
        for(int i=1;i<a.size();i++)
            if(abs(a[i]-h)<abs(a[k]-h))
                k=i;

        total+=abs(a[k]-h);
        h=a[k];
        cout<<" -> "<<h;
        a.erase(a.begin()+k);
    }
    cout<<"\nTotal Head Movement = "<<total<<endl;
}

void SCAN(vector<int> a, int head) {
    sort(a.begin(),a.end());
    int h=head,total=0;
    cout<<"\nSCAN: "<<h;

    for(int x:a)
        if(x>=head) {
            total+=abs(x-h);
            h=x;
            cout<<" -> "<<h;
        }

    total+=abs(199-h);
    h=199;
    cout<<" -> "<<h;

    for(int i=a.size()-1;i>=0;i--)
        if(a[i]<head) {
            total+=abs(a[i]-h);
            h=a[i];
            cout<<" -> "<<h;
        }

    cout<<"\nTotal Head Movement = "<<total<<endl;
}

void CLOOK(vector<int> a, int head) {
    sort(a.begin(),a.end());
    int h=head,total=0;
    cout<<"\nC-LOOK: "<<h;

    for(int x:a)
        if(x>=head) {
            total+=abs(x-h);
            h=x;
            cout<<" -> "<<h;
        }

    for(int x:a)
        if(x<head) {
            if(h==head) {
                total+=abs(a[0]-h);
                h=a[0];
                cout<<" -> "<<h;
            }
            total+=abs(x-h);
            h=x;
            cout<<" -> "<<h;
        }

    cout<<"\nTotal Head Movement = "<<total<<endl;
}

int main() {
    int n,head;
    cout<<"Enter number of requests: ";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter requests: ";
    for(int &x:a) cin>>x;

    cout<<"Enter head position: ";
    cin>>head;

    SSTF(a,head);
    SCAN(a,head);
    CLOOK(a,head);

    return 0;
}
