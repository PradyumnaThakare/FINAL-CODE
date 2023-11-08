#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//compare v1 v2

bool compare(pair<int,int>a,pair<int,int>b){
    double v1=(double)a.first/a.second;
    double v2=(double)b.first/b.second;
    return v1>v2;
}

//main
int main(){
    int n;
    cin>>n;
    
    vector<pair<int ,int>>a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int w;
    cin>>w;
    sort(a.begin(),a.end(),compare);
    double ans=0;
    for(int i=0;i<n;i++){
        if(w>=a[i].second){
            ans=ans+a[i].first;
            w=w-a[i].second;
            continue;
        }
        double vw=(double) a[i].first/a[i].second ;
        ans=ans+vw*w;
        w=0;
        break;
    }
    cout<<ans;
}