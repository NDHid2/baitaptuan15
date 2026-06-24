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
