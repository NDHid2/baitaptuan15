#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 11;
string city[N] =
{
    "Ha Noi",       
    "Son Tay",      
    "Hoa Binh",     
    "Phu Ly",       
    "Hung Yen",     
    "Hai Duong",    
    "Hai Phong",    
    "Uong Bi",      
    "Bac Giang",    
    "Bac Ninh",     
    "Thai Nguyen"   
};

// Ham them canh vo huong vao ma tran ke
void themCanh(int a[][N], int u, int v)
{
    a[u][v] = 1;
    a[v][u] = 1;
}

