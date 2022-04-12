#include <iostream>
#include <fstream>

using namespace std;

const string INPUT_FILE = "HVDEP.INP";
const string OUTPUT_FILE = "HVDEP.OUT";
const int HANG[8][3][2] =
{
    // 3 hang ngang
    {{0,0}, {0,1}, {0,2}},
    {{1,0}, {1,1}, {1,2}},
    {{2,0}, {2,1}, {2,2}},
    // 3 hang doc
    {{0,0}, {1,0}, {2,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,2}, {1,2}, {2,2}},
    // 2 hang cheo
    {{0,0}, {1,1}, {2,2}},
    {{0,2}, {1,1}, {2,0}}
};

void docFile(int hv[3][3]);
void ghiFile(int hv[3][3]);
void calculate(int hv[3][3]);

int main()
{
    int hv[3][3];
    docFile(hv);
    calculate(hv);
    ghiFile(hv);
}



int tinhTong(int hv[3][3])
{
    for(int i = 0; i < 8; i++)
    {
        int x1 = HANG[i][0][0], y1 = HANG[i][0][1];
        int x2 = HANG[i][1][0], y2 = HANG[i][1][1];
        int x3 = HANG[i][2][0], y3 = HANG[i][2][1];
        if(
            hv[x1][y1] != 0
            && hv[x2][y2] != 0
            && hv[x3][y3] != 0
        )
        {
            return hv[x1][y1] + hv[x2][y2] + hv[x3][y3];
        }
    }
}

void calculate(int hv[3][3])
{
    int tong = tinhTong(hv);
    for(int i = 0; i < 8; i++)
    {
        int x1 = HANG[i][0][0], y1 = HANG[i][0][1];
        int x2 = HANG[i][1][0], y2 = HANG[i][1][1];
        int x3 = HANG[i][2][0], y3 = HANG[i][2][1];
        if(
            hv[x1][y1] == 0
            && hv[x2][y2] != 0
            && hv[x3][y3] != 0
        )
        {
            hv[x1][y1] = tong - hv[x2][y2] - hv[x3][y3];
        }
        if(
            hv[x1][y1] != 0
            && hv[x2][y2] == 0
            && hv[x3][y3] != 0
        )
        {
            hv[x2][y2] = tong - hv[x1][y1] - hv[x3][y3];
        }

        if(
            hv[x1][y1] != 0
            && hv[x2][y2] != 0
            && hv[x3][y3] == 0
        )
        {
            hv[x3][y3] = tong - hv[x1][y1] - hv[x2][y2];
        }

    }
}

void docFile(int hv[3][3])
{
    ifstream input(INPUT_FILE);
    input >> hv[0][0] >> hv[0][1] >> hv[0][2];
    input >> hv[1][0] >> hv[1][1] >> hv[1][2];
    input >> hv[2][0] >> hv[2][1] >> hv[2][2];
    input.close();
}

void ghiFile(int hv[3][3])
{
    ofstream output(OUTPUT_FILE);
    output << hv[0][0] << " " << hv[0][1] << " " << hv[0][2] << endl;
    output << hv[1][0] << " " << hv[1][1] << " " << hv[1][2] << endl;
    output << hv[2][0] << " " << hv[2][1] << " " << hv[2][2] << endl;
    output.close();
}

