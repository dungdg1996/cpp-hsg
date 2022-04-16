#include <iostream>
#include <fstream>

using namespace std;

const string KY_HIEU[] = {"VV", "DD", "LL", "MMM","CCC","XXX","III","MM","CC","XX","II","CM","CD","XC","XL","IX","IV","M","D","C","L","X","V","I"};
const int GIA_TRI[] = {10000, 10000, 10000, 3000,300,30,3,2000,200,20,2,900,400,90,40,9,4,1000,500,100,50,10,5,1};

bool find(string s, string x) {
    return s.find(x) != string::npos;
}


int main() {
    ifstream fin("LAMA.INP");
    string s;
    fin >> s;
    fin.close();

    bool ketQua = true;

    int giaTriCu = 9999;
    while(s.size() > 0) {
        for(int i = 0; i < 24; i++) {
            int dodai = KY_HIEU[i].size();
            if(s.size() >= dodai && s.substr(0, dodai) == KY_HIEU[i]) {
                s = s.substr(dodai);
                if(GIA_TRI[i] > giaTriCu) {
                    ketQua = false;
                } else {
                    giaTriCu = GIA_TRI[i];
                }
                break;
            }
        }
    }

    ofstream fout("LAMA.OUT");
    if(ketQua) {
        fout << "CO";
    } else {
        fout << "KHONG";
    }
    fout.close();
}
