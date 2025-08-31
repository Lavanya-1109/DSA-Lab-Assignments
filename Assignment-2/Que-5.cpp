#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;

    vector<int> diag(n);
    for (int i=0;i<n;i++) diag[i] = i+1;
    cout << "Diagonal Matrix:\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) cout << (i==j ? diag[i] : 0) << " ";
        cout << endl;
    }

    
    vector<int> tri(3*n-2);
  
    for (int i=0;i<3*n-2;i++) tri[i]=i+1;
    cout << "\nTri-diagonal Matrix:\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) cout << tri[n-1+i] << " ";      
            else if (i==j+1) cout << tri[i-1] << " ";  
            else if (i+1==j) cout << tri[2*n-1+i] << " "; 
            else cout << 0 << " ";
        }
        cout << endl;
    }

  
    vector<int> low(n*(n+1)/2);
    for (int i=0;i<low.size();i++) low[i]=i+1;
    cout << "\nLower Triangular:\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i>=j) cout << low[i*(i+1)/2 + j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    
    vector<int> up(n*(n+1)/2);
    for (int i=0;i<up.size();i++) up[i]=i+1;
    cout << "\nUpper Triangular:\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i<=j) cout << up[i*n - i*(i-1)/2 + (j-i)] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    
    vector<int> sym(n*(n+1)/2);
    for (int i=0;i<sym.size();i++) sym[i]=i+1;
    cout << "\nSymmetric Matrix:\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i>=j) cout << sym[i*(i+1)/2 + j] << " ";
            else cout << sym[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }

    return 0;
}
