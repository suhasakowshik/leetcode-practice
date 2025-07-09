#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

void queryNode(int nodeID,unordered_map<int,std::pair<double,double>>& nodes)
{
    auto it = nodes.find(nodeID);
    if(it!=nodes.end())
    {
        cout<<"Node "<<nodeID<<" coordinates: ("<<it->second.first<<" , "<<it->second.second<<")\n";
    }
    else
    {
        cout<<"Node "<<nodeID<<" not found.\n";
    }
}

int main()
{
    unordered_map<int,std::pair<double,double>> nodes;

    // Insert nodes
    nodes[1] = {0.0, 0.0};
    nodes[2] = {1.0, 0.0};
    nodes[3] = {0.0, 1.0};

    // Query
    queryNode(2, nodes);
    queryNode(5, nodes);

    return 0;
}