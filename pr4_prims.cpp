#include<iostream>
#include<climits>
using namespace std;

class prims
{
    private:
    int n;
    int mat[10][10];
    public:
    prims()
    {
        cout<<"enter number of vertices";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for (int j;j<n;j++)
            {
                mat[i][j]=0;
            }
        }
    }
    void create()
    {
        int v1,v2,ans,cost;
        do
        {
        cout<<"enter edge and cost";
        cin>>v1>>v2>>cost;
        mat[v1][v2]=cost;
        mat[v2][v1]=cost;
        cout<<"add ane more(0,1)";
        cin>>ans;
        }while(ans==1);
    }
    void display()
    {
        for (int i=0;i<n;i++)
        {
            cout<<"\n";
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<"\t";
            }
        }
    }
    
    void mst()
    {
        int selected[10];
        int mincost=0;
        
        for(int i=0;i<n;i++)
        {
            selected[i]=0;
        }
        selected[0]=1;
        int edgecnt=0;
        while(edgecnt<n-1)
        {
            int min=INT_MAX;
            int x=0;
            int y=0;
            for(int i=0;i<n;i++)
            {
                if (selected[i])
                {
                    for(int j=0;j<n;j++)
                    {
                        if(!selected[j] && mat[i][j])
                        {
                            if(mat [i][j] < min)
                            {
                                min=mat[i][j];
                                x=i;
                                y=j;
                            }
                        }
                    }
                }
            }
            cout<<"\nedge"<<edgecnt+1<<" x "<<x<<"-"<<" y "<<y<<" cost "<<min<<endl;
                mincost+=min;
                selected[y] = 1;
                edgecnt++;
        }
        cout<<"mincost:"<<mincost;
    }
    
};

int main()
{
    prims p;
    p.create();
    p.display();
    p.mst();
}