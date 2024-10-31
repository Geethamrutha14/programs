 // finding the fractional knapsack...
 #include <bits/stdc++.h>
 using namespace std;
 bool compare_by_ratio(pair<int,int>&a, pair<int,int>&b)
 {
     return (double)a.first/a.second > (double)b.first/b.second;
 }
 int main()
 {
     int wt_of_snack; cin>>wt_of_snack;
     int profit=0;
     int n;
     cin>>n;
     vector<pair<int,int>>p; 
     vector<int>v(n),v1(n);  // v-value and v1-weight
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     for(int i=0;i<n;i++){
         cin>>v1[i];
         p.push_back(make_pair(v[i],v1[i]));
     }
     sort(p.begin(),p.end(),compare_by_ratio);
     for(int i=0;i<n;i++)
     {
         if(p[i].second <= wt_of_snack)
         {
             wt_of_snack = wt_of_snack - p[i].second;
             profit =  profit + p[i].first;
         }
         else {
             profit =  profit + p[i].first * (double(wt_of_snack) / p[i].second);
             wt_of_snack=0;
         }
     }
     cout<<profit<<endl;
     
     return 0;
 }