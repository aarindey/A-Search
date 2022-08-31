#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
    vector<int> heuristicVal(n+1);
    for(int i=1;i<=n;i++){
        cin>>heuristicVal[i];
    }
    int source,destination;
    cin>>source>>destination;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    // f(n) = g(n) + h(n)
    // [ F(n) , Path Cost , NodeNum]
    pq.push({0,0,source});
    int ans=-1;
    while(!pq.empty())
    {
        vector<int> node=pq.top();
        pq.pop();
        
        int fn=node[0];
        int pathCost=node[1];
        int nodeNum=node[2];
        
        if(nodeNum==destination){
            ans=pathCost;
            break;
        }
        
        for(auto &it : graph[nodeNum])
        {
            int adjNodeNum=it.first;
            int edgeWt=it.second;
            pq.push({pathCost+edgeWt+heuristicVal[adjNodeNum],pathCost+edgeWt,adjNodeNum});
        }
    }
    cout<<ans<<endl;
    return 0;
}
