class Solution {
public:
    void clone(UndirectedGraphNode *cur, unordered_map<int, UndirectedGraphNode *> &nodes)
    {
        if(nodes.find(cur->label)==nodes.end())
        {
            UndirectedGraphNode *hold=new UndirectedGraphNode(cur->label);
            nodes[cur->label] = hold;
        }
        for(UndirectedGraphNode * tmp: cur->neighbors)
        {
            if(nodes.find(tmp->label)==nodes.end())
            {
                clone(tmp,nodes);
            }
            nodes[cur->label]->neighbors.push_back(nodes[tmp->label]);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==0)
           return 0;
        unordered_map<int, UndirectedGraphNode *> a;
        clone(node,a);
        return a[node->label];
    }
};