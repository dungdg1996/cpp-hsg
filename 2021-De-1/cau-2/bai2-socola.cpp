#include <iostream>
#include <fstream>

using namespace std;

void sapxep(long p[], long c[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n -1; j++) {
            if(p[i] > p[j]) {
                // doi cho cua P
                long temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                // doi cho cua C
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

long tinhTong(long p[], long c[], int n, long k) {
    long tongTien = 0;
    long tongSoKeo = 0;
    bool hetTien = false;
    for(int i = 0; i < n; i++) {
        long soKeoCanLay = 0;
        // neu con tien
        if(tongTien + p[i] * c[i] <= k) {
            soKeoCanLay = c[i];
        } 
        // neu het tien
        else {
            soKeoCanLay = (k - tongTien) / p[i];
            hetTien = true;
        }
        tongTien += p[i] * c[i];
        tongSoKeo += soKeoCanLay;
        // het tien thi dung lai
        if(hetTien) break;
    }
    return tongSoKeo;
}

int main() {

    int n = 0;
    long k = 0;

    // 1. doc file
    ifstream input("SOCOLA.INP");
    input >> n >> k;
    long p[n], c[n];
    for(int i = 0; i < n; i++) {
        input >> p[i] >> c[i];
    }
    input.close();

    // 2. sap xep c va p the chieu tang dan cua c
    sapxep(p, c, n);

    // 3. Tinh so keo
    cout << tinhTong(p, c, n, k);
}
