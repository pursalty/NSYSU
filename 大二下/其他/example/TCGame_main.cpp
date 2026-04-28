#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

//DSU
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }
};

void solve(string outFileName) {
    int n, k;
    if (!(cin >> n >> k)) return; 

    //grid
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = (n - i - 1) * n + j + 1;
        }
    }

    DSU dsu(n * n);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v; 
        dsu.unite(u, v);
    }

    //conquest
    int startID, p;
    cin >> startID >> p; 
    
    vector<char> moves;
    for (int i = 0; i < p; i++) {
        char moveChar;
        cin >> moveChar;
        moves.push_back(moveChar);
    }

    set<int> ownedRoots;
    set<int> activeRoots;

    int startRoot = dsu.find(startID);
    ownedRoots.insert(startRoot);
    activeRoots.insert(startRoot);

    for (char dir : moves) {
        set<int> nextActiveRoots; 
        set<int> newlyOwnedRoots; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int currID = grid[i][j];
                int currRoot = dsu.find(currID);

                if (activeRoots.count(currRoot)) {
                    int nr = i, nc = j;
                    if (dir == 'U') nr--;
                    else if (dir == 'D') nr++;
                    else if (dir == 'L') nc--;
                    else if (dir == 'R') nc++;

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                        nextActiveRoots.insert(currRoot);
                    } else {
                        int nextID = grid[nr][nc];
                        int nextRoot = dsu.find(nextID);

                        if (!ownedRoots.count(nextRoot)) {
                            newlyOwnedRoots.insert(nextRoot);
                            nextActiveRoots.insert(nextRoot);
                        }
                    }
                }
            }
        }

        for (int root : newlyOwnedRoots) {
            ownedRoots.insert(root);
        }
        activeRoots = nextActiveRoots;
    }

    //SVG
    const int cellSize = 80;
    const int offset = 30;
    ofstream svg(outFileName);

    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\""
        << n * cellSize + offset * 2 << "\" height=\""
        << n * cellSize + offset * 2 << "\">" << endl;

    svg << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int currentID = grid[i][j]; 
            string color = ownedRoots.count(dsu.find(currentID)) ? "#FFD700" : "white";
            svg << "<rect x=\"" << offset + j * cellSize << "\" y=\"" << offset + i * cellSize 
                << "\" width=\"" << cellSize << "\" height=\"" << cellSize << "\" fill=\"" << color << "\" />" << endl;
        }
    }

    svg << "<rect x=\"" << offset << "\" y=\"" << offset << "\" width=\"" << n * cellSize 
        << "\" height=\"" << n * cellSize << "\" fill=\"none\" stroke=\"black\" stroke-width=\"3\" />" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = offset + j * cellSize;
            int y = offset + i * cellSize;
            int rootSelf = dsu.find(grid[i][j]);

            if (j + 1 < n && rootSelf != dsu.find(grid[i][j + 1])) {
                svg << "<line x1=\"" << x + cellSize << "\" y1=\"" << y 
                    << "\" x2=\"" << x + cellSize << "\" y2=\"" << y + cellSize 
                    << "\" stroke=\"black\" stroke-width=\"2\" />" << endl;
            }
            if (i + 1 < n && rootSelf != dsu.find(grid[i + 1][j])) {
                svg << "<line x1=\"" << x << "\" y1=\"" << y + cellSize 
                    << "\" x2=\"" << x + cellSize << "\" y2=\"" << y + cellSize 
                    << "\" stroke=\"black\" stroke-width=\"2\" />" << endl;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            svg << "<text x=\"" << offset + j * cellSize + cellSize / 2 
                << "\" y=\"" << offset + i * cellSize + cellSize / 2 
                << "\" font-family=\"Arial\" font-size=\"24\" text-anchor=\"middle\" "
                << "dominant-baseline=\"middle\" fill=\"gray\">" << grid[i][j] << "</text>" << endl;
        }
    }

    svg << "</svg>" << endl;
    svg.close();
}

int main(int argc, char* argv[]) {
    string outFile = "result.svg";
    if (argc >= 2) outFile = argv[1]; 
    solve(outFile);
    return 0;
}
