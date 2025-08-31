#include <iostream>
using namespace std;

void print(int r[],int c[],int v[],int n){
    cout<<"Row Col Val\n";
    for(int i=1;i<=n;i++) cout<<r[i]<<" "<<c[i]<<" "<<v[i]<<"\n";
}

int main(){
    
    int r1[10]={3,0,0,1,2}, c1[10]={3,0,2,1,2}, v1[10]={4,5,6,3,6}; 
    int n1=5; 

    cout<<"Matrix A:\n"; print(r1,c1,v1,n1);

    // (a) Transpose
    cout<<"\nTranspose:\n";
    for(int i=1;i<=n1;i++) cout<<c1[i]<<" "<<r1[i]<<" "<<v1[i]<<"\n";

    // (b) Addition A+A
    cout<<"\nAddition (A+A):\n";
    for(int i=1;i<=n1;i++) cout<<r1[i]<<" "<<c1[i]<<" "<<2*v1[i]<<"\n";

    // (c) Multiplication (A*Aᵀ)
    int res[10][10]={0};
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n1;j++)
            if(c1[i]==c1[j]) res[r1[i]][r1[j]] += v1[i]*v1[j];

    cout<<"\nMultiplication (A*Aᵀ):\nRow Col Val\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(res[i][j]!=0) cout<<i<<" "<<j<<" "<<res[i][j]<<"\n";

    return 0;
}
