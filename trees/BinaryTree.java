import java.util.Stack;
class Node
{
    int data;
    Node left, right;
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;
    void inOrder()
    {
        if(root==null)
        {
            return;
        }
        Stack<Node> stack = new Stack<Node>();
        Node node = root;
        while(node != null)
        {
            stack.push(node);
            node = node.left;
        }
        while(stack.size()>0)
        {
            node = stack.pop();
            System.out.print(node.data+" ");
            if(node.right != null)
            {
                node = node.right;
                while(node != null)
                {
                    stack.push(node);
                    node = node.left;
                }
            }
        }
        System.out.println();
    }

    public static void main(String args[])
    {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(5);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(7);
        tree.root.right.right = new Node(9);
        tree.inOrder();
    }
}
