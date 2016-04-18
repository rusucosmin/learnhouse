#include<queue>
#include<cstdio>
#include<cstring>
#include<fstream>

using namespace std;

ifstream cin("muzeu.in");
ofstream cout("muzeu.out");

int m[251][251];
queue< pair<int, int> > Q;
int i,j,n,g,h;
char s;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

int main()
{
    cin >> n;
    cin.get();
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            cin.get(s);
            if( s == '\n')
                cin.get(s);
            if(s=='#')
                m[i][j]=-2;
            else
                if(s=='P')
                    Q.push(make_pair(i, j)) ,m[i][j]=0;
            else m[i][j] = -1;
        }
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        for(int i = 0 ; i < 4 ; ++ i)
        {
            int xnou = x + dx[i];
            int ynou = y + dy[i];
            if( xnou >= 1 && xnou <=n && ynou >= 1 && ynou <= n)   // daca nu am iesit din matrice
            {
                if( m[xnou][ynou] > m[x][y] + 1 || m[xnou][ynou] == -1)
                    m[xnou][ynou] = m[x][y] + 1,
                    Q.push(make_pair(xnou, ynou));
            }
        }
    }
    for(i=1; i<=n; ++i, cout << '\n')
        for(j=1; j<=n; ++j)
            cout<<m[i][j]<<" ";
}
