#include<iostream>
#include<iomanip>
#include<vector>
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
    int n;
    double avwt,avtat;

    vector <int> process;
    vector <int> queue;


    cout<<"Enter no of process : ";
    cin>>n;
    int arrival_time[n], cpu_time[n],wt[n],tat[n],twt=0,ttat=0, ft[n],p[n];

    for(int i=0;i<n;i++){
        p[i]=i;
        cout<<"Arrival time of process "<<i<<" is ";
        cin>>arrival_time[i];
        process.push_back(i);
    }

    for(int i=0;i<n;i++){
        cout<<"CPU time of process "<<i<<" is ";
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


    ft[0] = arrival_time[0]+cpu_time[0];
    process.erase(process.begin());


    int k,j=0;
    int minimum;

    while(1){

    k=j;
    for(int a=0;a<process.size();a++){
        if(ft[j]>=arrival_time[process[a]])
            queue.push_back(process[a]);
    }
/*
    cout<<"After "<<ft[j]<<" time processes in queue are ";

    cout<<"[";
    for(int a=0;a<queue.size();a++){
        cout<<queue[a]<<", ";
    }
    cout<<"]"<<endl;
*/
    if(queue.size()>0&&process.size()>0){
        //find min cpu time to execute
        minimum=INT_MAX;; // execution time of queue[0] which holds index of at,cpu_time,p
        for(int i=0;i<queue.size();i++){
            if(cpu_time[queue[i]]<minimum){
                minimum = cpu_time[queue[i]];
                j=queue[i];
            }
        }
        //cout<<"Process having minimum execution time is "<<j<<" So "<<j<<"is executed."<<endl;
        ft[j] = ft[k] + cpu_time[j];
        //cout<<"Finish time of j is "<<ft[j]<<endl;
        //erase where content is j in process
        for(int m=0; m<process.size();m++){
            if(process[m]==j){
                process.erase(process.begin()+m);
                break;
            }
        }
        /*
        cout<<"Remaining processes :"<<endl;
        for(int a=0;a<process.size();a++){
        cout<<process[a]<<", ";
        }
        cout<<endl;
        */

        }

    queue.clear();
    if(process.size()==0)
        break;
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

    cout<<"Turn around time is "<<avtat<<endl;
    cout<<"Average waiting time is "<<avwt<<endl;
    return 0;
}


