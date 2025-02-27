#include<iostream>
using namespace std;
int main(){
    int n;

    cout<<"Enter number if lines:";
    cin>>n;
    int count=n;
    for(int i=0;i<n;i++){
        for(int j=1;j<=i;j++){

            cout<<" ";

        }
        for( int j=count;j>1;j--){
            cout<<i+1;
        }

        cout<<"\n";
        count--;
    }


    return 0;
}