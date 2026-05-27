#include <iostream>
using namespace std;

void in_ra(int x[], int k) {
    cout << "[ ";
    for (int i = 0; i < k; i++) {
        cout << x[i];
        if (i < k - 1) {
            cout << ", ";
        }
    }
    cout << " ]\n";
}

void sua_dong(int x[], int k, int i) {
    int max_vi_tri = i; 
    int tr = 2 * i + 1; 
    int ph = 2 * i + 2; 

    if (tr < k) {
        if (x[tr] > x[max_vi_tri]) {
            max_vi_tri = tr;
        }
    }
    
    if (ph < k) {
        if (x[ph] > x[max_vi_tri]) {
            max_vi_tri = ph;
        }
    }

    if (max_vi_tri != i) {
        int luu = x[i]; 
        x[i] = x[max_vi_tri]; 
        x[max_vi_tri] = luu;
        
        sua_dong(x, k, max_vi_tri);
    }
}

void build_dong(int x[], int k) {
    for (int i = k / 2 - 1; i >= 0; i--) {
        sua_dong(x, k, i);
        cout << "vi tri i = " << i << ": "; 
        in_ra(x, k);
    }
}

void sap_xep(int x[], int k) {
    int dem = 1; 
    for (int i = k - 1; i > 0; i--) {
        int luu = x[0]; 
        x[0] = x[i]; 
        x[i] = luu;

        sua_dong(x, i, 0);

        cout << "Buoc " << dem << ": "; 
        in_ra(x, k);
        dem = dem + 1; 
    }
}

int main() {
    int x[] = {11, 54, 32, 106, 38, 78, 208, 16, 89, 17, 39, 15};
    int k = 12;

    cout << "Mang goc: ";
    in_ra(x, k);

    cout << "\n--> TAO DONG:\n";
    build_dong(x, k); 

    cout << "\n--> SAP XEP:\n"; 
    sap_xep(x, k);

    return 0;
}
