#include <iostream>
#include <random>

using namespace std;

int main() 
{
    int n,k=0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist (1,100);
    int num=dist(gen);
 do{
    cout << "Introduce un numero: ";
    cin>>n;
    if(n>num) {
        cout<<"too big"<<endl; k++;
    } else if(n<num) {
        cout<<"too small"<<endl;k++;
    } else {
        cout<<"you guessed "<<k<<" chances"<<endl;
        break;
    }
        
 }while (n!=num && k>0);
 
 }