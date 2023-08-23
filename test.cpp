class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    void insert(int val)
    {
        if (val <= value)
        {
            if (left == nullptr)
            {
                left = new TreeNode(val);
            }
            else
            {
                left->insert(val);
            }
        }
        else
        {
            if (right == nullptr)
            {
                right = new TreeNode(val);
            }
            else
            {
                right->insert(val);
            }
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->insert(3);
    root->insert(8);
    root->insert(2);
    root->insert(4);
    root->insert(7);
    root->insert(9);

    // Now the tree should look like:
    //       5
    //     /   \
    //    3     8
    //   / \   / \
    //  2   4 7   9

    return 0;
}
