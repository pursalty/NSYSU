#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// 建議將 solve 改為從 cin 讀取，以配合自動評分腳本
void solve(string outFileName)
{
    int n, k;
    if (!(cin >> n >> k))
        return; // 從標準輸入讀取 n 和 k [cite: 9-11]

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = (n - i - 1) * n + j + 1; // 由下而上、由左而右編號 [cite: 10]
        }
    }

    // --- Phase 1: Initialization (DSU) ---
    vector<int> parent(n * n + 1);
    for (int i = 1; i <= n * n; i++)
        parent[i] = i;

    auto find = [&](auto self, int x) -> int
    {
        return parent[x] == x ? x : (parent[x] = self(self, parent[x]));
    };

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v; // 讀取合併操作 [cite: 12]
        int rootU = find(find, u);
        int rootV = find(find, v);
        if (rootU != rootV)
            parent[rootU] = rootV;
    }

    // --- Phase 2: Conquest ---
    int ID, p;
    cin >> ID >> p; // 讀取起始點與移動步數 [cite: 14-15]

    vector<bool> isConquested(n * n + 1, false);
    isConquested[ID] = true;

    int currID = ID;
    string move;
    cin >> move; // 讀取方向 [cite: 16]

    for (int i = 0; i < p; i++)
    {
        char dir = move[i];
        int r = (currID - 1) / n;
        int c = (currID - 1) % n;

        int nr = r, nc = c;
        if (dir == 'U')
            nr++;
        else if (dir == 'D')
            nr--;
        else if (dir == 'L')
            nc--;
        else if (dir == 'R')
            nc++;

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) // 邊界檢查 [cite: 46]
        {
            int nextID = nr * n + nc + 1;
            if (isConquested[nextID])
            { // 退休機制 [cite: 48]
                currID = nextID;
                break;
            }
            isConquested[nextID] = true;
            currID = nextID;
        }
    }

    // --- Phase 3: SVG 輸出 (嚴格遵循 5 步流程) [cite: 178-183] ---
    const int cellSize = 80;
    const int offset = 30;
    ofstream svg(outFileName);

    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\""
        << n * cellSize + offset * 2 << "\" height=\""
        << n * cellSize + offset * 2 << "\">" << endl;

    // 1. Draw the white background
    svg << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl;

    // 2. Fill each cell with a color [cite: 181]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int id = grid[i][j];
            int x = offset + j * cellSize;
            int y = offset + i * cellSize;
            string fillColor = isConquested[id] ? "#FFD700" : "white";
            svg << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << cellSize
                << "\" height=\"" << cellSize << "\" fill=\"" << fillColor << "\" />" << endl;
        }
    }

    // 3. Draw the outer border of the board [cite: 182]
    svg << "<rect x=\"" << offset << "\" y=\"" << offset << "\" width=\"" << n * cellSize
        << "\" height=\"" << n * cellSize << "\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" />" << endl;

    // 4. Draw only the boundaries between different regions [cite: 183]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int id = grid[i][j];
            int x = offset + j * cellSize;
            int y = offset + i * cellSize;

            if (j + 1 < n && find(find, id) != find(find, grid[i][j + 1]))
            {
                svg << "<line x1=\"" << x + cellSize << "\" y1=\"" << y
                    << "\" x2=\"" << x + cellSize << "\" y2=\"" << y + cellSize
                    << "\" stroke=\"black\" stroke-width=\"2\" />" << endl;
            }
            if (i + 1 < n && find(find, id) != find(find, grid[i + 1][j]))
            {
                svg << "<line x1=\"" << x << "\" y1=\"" << y + cellSize
                    << "\" x2=\"" << x + cellSize << "\" y2=\"" << y + cellSize
                    << "\" stroke=\"black\" stroke-width=\"2\" />" << endl;
            }
        }
    }

    // 5. Draw the cell labels [cite: 183]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = offset + j * cellSize + cellSize / 2;
            int y = offset + i * cellSize + cellSize / 2;
            svg << "<text x=\"" << x << "\" y=\"" << y << "\" font-family=\"Arial\" font-size=\"20\" "
                << "text-anchor=\"middle\" dominant-baseline=\"middle\" fill=\"gray\">"
                << grid[i][j] << "</text>" << endl;
        }
    }

    svg << "</svg>" << endl;
    svg.close();
}

int main(int argc, char *argv[])
{
    string outFile = "result.svg";
    if (argc >= 2)
        outFile = argv[1]; // 接受指令列參數指定輸出檔名 [cite: 241-243]

    // 執行一次 solve，從 cin 讀取
    solve(outFile);

    return 0;
}