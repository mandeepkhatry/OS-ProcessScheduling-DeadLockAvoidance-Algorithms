#include<iostream>
#include<iomanip>
using namespace std;

void sort_data(int a[],int c[],int p[],int n){

    int temp1,temp2,temp3;
    for(int y=0;y<n-1;y++)
    {
        for(int z=0;z<n-1;z++)
            if(*(a+z)>*(a+z+1))
            {
                temp1=*(a+z);
                *(a+z)=*(a+z+1);
                *(a+z+1)=temp1;

                temp2=*(c+z);
                *(c+z)=*(c+z+1);
                *(c+z+1)=temp2;

                 temp3=*(p+z);
                *(p+z)=*(p+z+1);
                *(p+z+1)=temp3;

            }
    }

}

int main()
{
    int arrival_time[20], cpu_time[20],wt[20],tat[20],twt=0,ttat=0, ft[20],n,p[20];
    double avwt,avtat;

    cout<<"Enter no of process : ";
    cin>>n;

    for(int i=0;i<n;i++){
        p[i]=i;
        cout<<"Arrival time of process "<<i+1<<" is ";
        cin>>arrival_time[i];
    }

    for(int i=0;i<n;i++){
        cout<<"CPU time of process "<<i+1<<" is ";
        cin>>cpu_time[i];
    }

    cout<<endl<<"Table"<<endl;
    cout<<endl<<"ProcessNo"<<setw(20)<<"Arrival Time"<<setw(20)<<"CPU time"<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<p[i]<<setw(20)<<arrival_time[i]<<setw(20)<<cpu_time[i]<<endl;
    }

    cout<<endl;
    sort_data(arrival_time,cpu_time,p,n);


    cout<<endl<<"New Table after sorting "<<endl;
    cout<<endl<<"ProcessNo"<<setw(20)<<"Arrival Time"<<setw(20)<<"CPU time"<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<p[i]<<setw(20)<<arrival_time[i]<<setw(20)<<cpu_time[i]<<endl;
    }
    cout<<endl;

    ft[0]=arrival_time[0]+cpu_time[0];

    for(int i=1;i<n;i++){
        if(ft[i-1]>=arrival_time[i])
            ft[i] = ft[i-1]+cpu_time[i];
        else
            ft[i] = arrival_time[i]+cpu_time[i];
    }

    for(int i=0;i<n;i++){
        tat[i]=ft[i]-arrival_time[i];
    }

    for(int i=0;i<n;i++){
        wt[i]=tat[i]-cpu_time[i];
    }


    for(int i=0;i<n;i++){
        twt+=wt[i];
    }


    for(int i=0;i<n;i++){
        ttat+=tat[i];
    }

    avtat=double(ttat)/n;
    avwt=double(twt)/n;

    cout<<endl<<"New Table after FCFS "<<endl;
    cout<<endl<<"ProcessNo"<<setw(20)<<"Arrival Time"<<setw(20)<<"CPU time"<<setw(20)<<"Turn Around Time"<<setw(20)<<"Waiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<p[i]<<setw(20)<<arrival_time[i]<<setw(20)<<cpu_time[i]<<setw(20)<<tat[i]<<setw(20)<<wt[i]<<endl;
    }
    cout<<endl;

    cout<<"Average waiting time is "<<avwt<<endl;

    cout<<"Turn around time is "<<avtat<<endl;
    return 0;
}

