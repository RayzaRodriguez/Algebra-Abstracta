#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
//int n = 100000000;
int n = 100000;
vector<int> lista(n,0);
vector<int> primos;
void criba(int limite);
int getMod(int d,int a);
int main(){
    criba(n);
    vector<int>::iterator i;
    for(i=primos.begin();i<primos.end();i++)
        cout<<*i<<" ";
    return 0;
}
void criba(int limite){
    int c;
    primos.push_back(2);
    primos.push_back(3);
    lista[9]=1;
    for(int i = 5; i < sqrt(limite);i+=2){
        if(lista[i]==0){
            primos.push_back(i);
            for(int j = (i+2);j<limite;j+=2){
                if(getMod(j,i)==0){
                    lista[j]=1;
                }
            }
        }
        c=i;
    }
    for(int f = c;f<limite;f+=2){
        if(lista[f]==0){
            primos.push_back(f);
        }
    }
}
int getMod(int d,int a){
    int q = d/a;
    int r = d-(q*a);
    if(r<0){
        r+=a;
    }
    return r;
}
