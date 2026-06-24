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

// Tim duong di ngan nhat (theo so canh) bang BFS
// Tra ve so canh cua duong di ngan nhat, hoac -1 neu khong co duong.
// Duong di duoc luu trong path (neu can)

int bfsShortestPath(int a[][N], int start, int target, vector<int>& path)
{
    vector<int> parent(N, -1);   // luu dinh cha de truy vet
    vector<bool> visited(N, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == target)
            break;

        for (int v = 0; v < N; v++)
        {
            if (a[u][v] == 1 && !visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[target])
        return -1;   // khong co duong di

    // Truy vet duong di tu target ve start
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    return path.size() - 1;   // so canh = so dinh - 1
}

int main()
{
    int a[N][N] = {0};

    
    themCanh(a, 0, 1);   // Ha Noi - Son Tay
    themCanh(a, 0, 2);   // Ha Noi - Hoa Binh
    themCanh(a, 0, 3);   // Ha Noi - Phu Ly
    themCanh(a, 0, 5);   // Ha Noi - Hai Duong
    themCanh(a, 0, 9);   // Ha Noi - Bac Ninh
    themCanh(a, 0, 10);  // Ha Noi - Thai Nguyen

    themCanh(a, 3, 4);   // Phu Ly - Hung Yen
    themCanh(a, 4, 5);   // Hung Yen - Hai Duong

    themCanh(a, 5, 6);   // Hai Duong - Hai Phong

    themCanh(a, 6, 7);   // Hai Phong - Uong Bi

    themCanh(a, 7, 8);   // Uong Bi - Bac Giang
    themCanh(a, 8, 9);   // Bac Giang - Bac Ninh

    themCanh(a, 9, 7);   // Bac Ninh - Uong Bi

    string startName, targetName;
    cout << "Nhap ten diem bat dau: ";
    getline(cin, startName);
    cout << "Nhap ten diem ket thuc: ";
    getline(cin, targetName);

    // Tim chi so tuong ung trong danh sach
    int start = -1, target = -1;
    for (int i = 0; i < N; i++)
    {
        if (city[i] == startName) start = i;
        if (city[i] == targetName) target = i;
    }

    if (start == -1 || target == -1)
    {
        cout << "Khong tim thay dia diem!\n";
        return 0;
    }

    // Tim duong di ngan nhat
    vector<int> path;
    int soCanh = bfsShortestPath(a, start, target, path);

    if (soCanh == -1)
        cout << "Khong co duong di!\n";
    else
        cout  << "duong di ngan nhat la " <<soCanh << endl;   

    return 0;
}
