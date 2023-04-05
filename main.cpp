#include <iostream>
#include "CPheadquarters.h"

using namespace std;
int main() {
    CPheadquarters CP;
    CP.read_files();

    int n;
    do{
        cout<<"T2.1 - Max number of trains between stations\n";
        cout<<"T2.2 -\n";
        cout<<"T2.3 -\n";
        cout<<"T2.4 -\n";
        cout<<"T3.1 -\n";
        cout<<"T4.1 -\n";
        cout<<"T4.2 -\n";
        cout<<"Insert your option:\n";
        cin>>n;
        if(n==1){
            cout<<"Insert station A\n";
            string a;
            cin>>a;
            cout<<"Insert station B\n";
            string b;
            cin>>b;
            CP.T2_1maxflow(a,b);
        }
        if(n==2){
            CP.T2_2maxflowAllStations();
        }
        if(n==3){

        }
        if(n==4){

        }
        if(n==5){

        }
        if(n==6){

        }
        if(n==7){

        }
        if(n>8){
            cout<<"Invalid option\n";
        }
    }
    while(n!=8);
}
