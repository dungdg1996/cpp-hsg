
#include <iostream>

using namespace std;

int main()
{
    int M, S;
    cin >> M >> S;

    if(M * 9 < S) {
        cout << "-1 -1";
        return 0;
    }

    // tinh so be
    string sobe = "";

    int tong = S - 1;
    int soChuSo = M;
    while(soChuSo > 0)
    {
        if(soChuSo == 1)
        {
            sobe = to_string(tong + 1) + sobe;
        }
        else
        {
            if(tong > 9)
            {
                sobe = "9" + sobe;
                tong = tong - 9;
            }
            else
            {
                sobe = to_string(tong) + sobe;
                tong = 0;
            }
        }
        soChuSo--;
    }
    
    // tin so lon
    string solon = "";
    tong = S;
    soChuSo = M;
    while(soChuSo > 0)
    {
        if(tong > 9)
        {
            solon =  solon + "9";
            tong = tong - 9;
        }
        else
        {
            solon = solon + to_string(tong);
            tong = 0;
        }
        soChuSo--;
    }
    cout << sobe << " " << solon;
}
