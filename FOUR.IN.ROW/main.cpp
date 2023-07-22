#include <iostream>
#include <graphics.h>
using namespace std;
main()
{
    int x=7,y=6;
    int t = x*y;
    cout<<t;
    int four=0;
    int click=2,color;
    int* arr=new int[x];

    int** arr2=new int*[y];
    for(int i=0;i<y;i++)
        arr2[i]=new int[x];

    for(int i=0;i<x;i++)
        arr[i]=0;
    initwindow(600,600);
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
        {
             rectangle(i*50,j*50,(i+1)*50,(j+1)*50);
        }

    while(!kbhit())
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int a=mousex()/50;
            int b=mousey()/50;
            //cout<<a<<" "<<b<<endl;

            if(click%2==0)
            {
             setfillstyle(1,3);
             color=0;
            }
            else
            {
             setfillstyle(1,4);
             color=1;
            }
            for(int k=1;k<=x;k++)
            {
            if(a==k && b>=1 && b<=6)
            {

                fillellipse((k+0.5)*50,(y+0.5-arr[k-1])*50,20,20);
                clearmouseclick(WM_LBUTTONDOWN);


                arr2[y-1-arr[k-1]][k-1]=color;
                //
                int p=y-1-arr[k-1];
                int q=k-1;
                while(t>0)
                {
                    four=0;
                    for(int i=p,j=q+1;j<=6;j++)
                    {
                        if(arr2[i][j]==arr2[p][q])
                        four++;
                        if(four==3)
                        {
                            if(arr2[p][q]==0)
                            cout<<"BLUE WINS!";
                            else
                            cout<<"RED WINS!";
                            return 0;

                        }
                    }
                    four=0;
                 for(int i=p,j=q-1;j>=0;j--)
                    {
                        if(arr2[i][j]==arr2[p][q])
                        four++;
                        if(four==3)
                        {
                            if(arr2[p][q]==0)
                            cout<<"BLUE WINS!";
                            else
                            cout<<"RED WINS!";
                            return 0;

                        }
                    }
                    four=0;
                    for(int i=p-1,j=q;i>=0;i--)
                    {
                        if(arr2[i][j]==arr2[p][q])
                        four++;
                        if(four==3)
                        {
                            if(arr2[p][q]==0)
                            cout<<"BLUE WINS!";
                            else
                            cout<<"RED WINS!";
                            return 0;

                        }
                    }
                    four=0;
                    for(int i=p+1,j=q;i<=5;i++)
                    {
                        if(arr2[i][j]==arr2[p][q])
                        four++;
                        if(four==3)
                        {
                            if(arr2[p][q]==0)
                            cout<<"BLUE WINS!";
                            else
                            cout<<"RED WINS!";
                            return 0;

                        }
                    }
                    four=0;
                    for(int i=p+1,j=q+1;i<=5,j<=6;i++,j++)
                    {
                        if(arr2[i][j]==arr2[p][q])
                        four++;
                        if(four==3)
                        {
                            if(arr2[p][q]==0)
                            cout<<"BLUE WINS!";
                            else
                            cout<<"RED WINS!";
                            return 0;

                        }
                    }
                    four=0;
                    for(int i=p-1,j=q-1;i>=0,j>=0;i--,j--)
                    {
                        if(arr2[i][j]==arr2[p][q])
                        four++;
                        if(four==3)
                        {
                            if(arr2[p][q]==0)
                            cout<<"BLUE WINS!";
                            else
                            cout<<"RED WINS!";
                            return 0;

                        }
                    }

                    t--;
                }
                if(t==0)
                    cout<<"Pot";
                //
                if(arr[k-1]<y-1)
                arr[k-1]++;
            }
            }
            click++;
        }

    }
	getch();

 for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
             cout<<arr2[i][j]<<" ";
        }
           cout<<endl;
    }
}
