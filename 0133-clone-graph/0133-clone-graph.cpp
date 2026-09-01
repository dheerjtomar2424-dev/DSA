class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (!node)
            return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        // Clone first node
        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {

                // Clone if not already created
                if (!mp.count(neighbor)) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                // Connect cloned nodes
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return mp[node];
    }
};