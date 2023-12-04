#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void colorFill(vector<vector<int>> &image, vector<vector<int>> &modImg, int sr, int sc, int color, int oldColor)
    {
        int n = image.size();
        int m = image[0].size();

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        if (sr < 0 || sc < 0 || sr >= n || sc >= m)
        {
            return;
        }
        if (modImg[sr][sc] != oldColor)
        {
            return;
        }

        modImg[sr][sc] = color;
        for (int i = 0; i < 4; i++)
        {
            int fr = sr + row[i];
            int fc = sc + col[i];
            colorFill(image, modImg, fr, fc, color, oldColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];
        vector<vector<int>> modImg = image;
        if (oldColor == color)
            return image;
        colorFill(image, modImg, sr, sc, color, oldColor);
        return modImg;
    }
};