#include<iostream>
#include<string.h>
#include<climits>
using namespace std;
 int mindistance(int distance[], bool stat[]) {
     int minimum= INT_MAX, ind;
     for(int k=0; k<13; k++)
     {
         if(stat[k]==false && distance[k]<=minimum)
           {
             minimum=distance[k];
             ind=k;
            }
     }
     return ind;
     
 }
 void dijkstra(int graph[13][13], int source, string stations[12])
 {
     int distance[13];
     bool stat[13];
     for(int k=0; k<13; k++)
     {
         distance[k]=INT_MAX;
         stat[k]=false;
     }
    distance[source]=0;
    for(int k=0;k<13;k++)
    {
        int m= mindistance(distance,stat);
        stat[m] = true;
        for(int k=0;k<13;k++)
        {
            if(!stat[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m] + graph[m][k]<distance[k])
            distance[k]= distance[m]+graph[m][k];
        }
    }
    cout<<" MINIMUM NUMBER OF BUS STATION FROM "<< stations[source] <<" TO EVERY STATION "<<endl;
    for(int k=0;k<13;k++)
    {
        cout<<" MINIMUM BUS STATIONS FROM " << stations[source] << " TO "<<stations[k]<<" IS "<<distance[k]<<" Km only :) "<<endl;
    }
 }
 int main()
 {
     int graph[13][13]={
         {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
};
 
 int source;
 string stations[13]={"CBS","Ashok stambha","RK(ravivar karanja)","Panchavati","Nimani","Adgaon Naka","Aurangabad Naka","Tapovan","Kapaleswar Nagar","Nandur Naka","Jail Road","Bytco","Nashik Road Railway Station"};
 cout<<"Enter the Source Bus Station:-"<<endl;
 for(int i=0;i<13;i++)
 {
      cout<<"Enter"<<i<<" for "<<stations[i]<<endl;
     
 }
 cout<<"\nPls Enter Your Choice:-->"<<endl;
 cin>>source;
 dijkstra( graph, source, stations);
 return 0;
 }