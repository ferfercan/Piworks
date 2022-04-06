#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>
#define ii pair<int, int>
#define mp make_pair
#define st first
#define nd second
using namespace std;

int mat[1005][1005];
int N;

bool isPrime(int n)
{

  if (n == 1 || n == 2)
    return 1;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return 0;
  }

  return 1;
}

ii dp[1005][1005];

ii f(int x, int y)
{

  if (x == N)
    return mp(x, mat[x][y]);

  if (dp[x][y].nd != -1)
    return dp[x][y];

  ii a(mp(0, 0)), b(mp(0, 0));
  if (!isPrime(mat[x + 1][y]))
    a = f(x + 1, y);
  if (!isPrime(mat[x + 1][y + 1]))
    b = f(x + 1, y + 1);

  if (a.first > b.first)
    return dp[x][y] = mp(a.st, (a.nd + mat[x][y]));
  else if (a.first < b.first)
    return dp[x][y] = mp(b.st, (b.nd + mat[x][y]));
  else if (a.first == 0)
    return dp[x][y] = mp(x, (max(a.nd, b.nd) + mat[x][y]));
  else
    return dp[x][y] = mp(a.st, (max(a.nd, b.nd) + mat[x][y]));
}

int main()
{
  // implementation and reading read from input.txt

  ifstream inp("input.txt");
  memset(dp, -1, sizeof(dp));

  for (int i = 1; i; i++)
  {
    inp >> mat[i][1];
    if (inp.eof())
      break;
    for (int j = 2; j <= i; j++)
      inp >> mat[i][j];
    N = i;
  }
  ii res = f(1, 1);
  cout << "depth of pyramind ->" << res.first << "\nmaxsum-> " << res.second << endl;

  return 0;
}
