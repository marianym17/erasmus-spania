#include <iostream>
#include <random>

using namespace std;

int main() 
{
    int n,k=10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist (1,100);
    int num=dist(gen);
 do{
    cout << "Introduce un numero: ";
    cin>>n;
    k--;
    if(n>num) {
        cout<<"too big"<<endl;
    } else if(n<num) {
        cout<<"too small"<<endl;
    } else {
        cout<<"you guessed in "<<k<<" chances"<<endl;
        break;
    }
        
 }while (n!=num && k>0);
 }