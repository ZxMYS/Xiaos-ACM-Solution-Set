#include <stdio.h>
#include <math.h>

#define PROBLEM_ID      "ground"
#define MAXN            12
#define PI              3.1415926535897932384626433832795

typedef long double     realType;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const realType eps = 1e-9;

bool hilbert[1 << MAXN][1 << MAXN];
realType tanAlpha, volume;
int hilbertSize, alpha;

void buildHilbert(int order, int x, int y, int d, bool top) {
    if (order == 1) {
        hilbert[x][y] = top; 
        return;
    }
    int dd = (d + 1) % 4;
    int size = 1 << (order - 1);
    buildHilbert(order - 1, x, y, d, top);
    buildHilbert(order - 1, x + dx[d] * size, y + dy[d] * size, d, top);
    buildHilbert(order - 1, x + dx[d] * (size - 2) + dx[dd] * size, y + dy[d] * (size - 2) + dy[dd] * size, (d + 1) % 4, !top);
    buildHilbert(order - 1, x + dx[d] * size + dx[dd] * (size + size - 2), y + dy[d] * size + dy[dd] * (size + size - 2), (d + 3) % 4, !top);
    if (top) {
        int xx = x + dx[dd] * (size - 1);
        int yy = y + dy[dd] * (size - 1);
        for (int i = 0; i < size + size - 1; i++) {
            hilbert[xx][yy] = true;
            xx += dx[d];
            yy += dy[d];
        }
        xx = x + dx[d] * (size - 1) + dx[dd] * (size - 1);
        yy = y + dy[d] * (size - 1) + dy[dd] * (size - 1);
        for (int i = size - 1; i < size + size - 1; i++) {
            hilbert[xx][yy] = true;
            xx += dx[dd];
            yy += dy[dd];
        }
    } else {
        int xx = x + dx[d] * (size - 1);
        int yy = y + dy[d] * (size - 1);
        for (int i = 0; i < size - 1; i++) {
            hilbert[xx][yy] = true;
            xx += dx[dd];
            yy += dy[dd];
        }
    }
}

void calcTriangle(realType depth, int sign) {
    if (depth < eps) {
        return;
    }
    volume += sign * depth * depth / 2 / tanAlpha;
}

void calcVolume(realType depth) {
    if (alpha == 0) {
        volume += depth;
        return;
    }
    calcTriangle(depth, +1);
    calcTriangle(depth - 1.0, -1);
    calcTriangle(depth - tanAlpha, -1);
}

void process(int x, int y, int d, realType depth) {
    if (x < 0 || y < 0 || x >= hilbertSize || y >= hilbertSize || !hilbert[x][y]) {
        return;
    }
    if (depth > 1 + tanAlpha) {
        depth = 1 + tanAlpha;
    }
    if (depth < eps) {
        return;
    }
    calcVolume(depth);
    for (int dir = 0; dir < 4; dir++) {
        if (dir == d) {
            continue;
        }
        process(x + dx[dir], y + dy[dir], (dir + 2) % 4, depth - dy[dir] + dx[dir] * tanAlpha);
    }
}

int n;

int main() {
    freopen(PROBLEM_ID ".in", "r", stdin);
    freopen(PROBLEM_ID ".out", "w", stdout);

    scanf("%d %d", &n, &alpha);
    hilbertSize = (1 << n) - 1;
    tanAlpha = tan(alpha * PI / 180.0);
    buildHilbert(n, 0, 0, 0, true);

    int top = (1 << n) - 2;
    for (int i = 0; i <= top; i++) {
        if (hilbert[i][top]) {
            process(i, top, 1, 1.0);
        }
    }
    printf("%.6lf\n", volume);
    return 0;
}
