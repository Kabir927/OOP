#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter The size of Array: ";
    cin>>size;

    int** arr = new int*[size];
    for(int i=0; i<size; i++){
        arr[i]=new int;
        cout<<"Enter Element "<<i+1<<": ";
        cin>>*(arr[i]);
    }
    cout<<endl;
    for(int i=0; i<size; i++){
        cout<<"ELement "<<i+1<<": "<<*(arr[i])<<endl;
    }

    for(int i=0; i<size; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}