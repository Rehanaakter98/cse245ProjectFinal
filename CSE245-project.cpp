#include<bits/stdc++.h>
#define ll long long int

using namespace std;
bool block[100][100], path[100][100];
int n, z;

bool maze(int r,int c)
{
    if(r==z && c==z)//
    {
        path[r][c]=true;
        return true;
    }
    else if(!block[r][c])
        return false;
    if(r<z)
    {
        if(maze(r+1,c))
        {
            path[r][c]=true;
            return true;
        }
    }
    if(c<z)
    {
        if(maze(r,c+1))
        {
            path[r][c]=true;
            return true;
        }
    }
    return false;
}
bool paths(int r,int c)
{
     if(r==0 && c==0)
     {
         cout<<"["<<r<<","<<c<<"] ";
         return 1;
     }
     if(path[r-1][c])
     {
         paths(r-1,c);
         cout<<"-> "<<"["<<r<<","<<c<<"] ";
         return 1;
     }
     if(path[r][c-1])
     {
         paths(r,c-1);
         cout<<"-> "<<"["<<r<<","<<c<<"] ";
         return 1;
     }
     return false;
}
int main()
{
    int i,j;
    cin>>n;//no of maze
    z=n-1;//no of home
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cin>>block[i][j];
    }
    path[0][0]=maze(0,0);
    cout<<endl<<"path of the matrix:"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    bool flag;
    cout<<"paths: ";
    flag=paths(z,z);
    cout<<endl<<endl;


    return 0;
}
