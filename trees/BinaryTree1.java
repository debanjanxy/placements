import java.util.Stack;

class Node
{
    int data;
    Node left,right;
    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}

class BinaryTree1
{
    Node root;
    void iterativePreorder()
    {
        Node node = root;
        if(node==null)
        {
            return;
        }
        Stack<Node> stack = new Stack<Node>();
        stack.push(root);
        while(stack.empty()==false)
        {
            node = stack.pop();
            System.out.print(node.data+" ");
            if(node.right != null)
            {
                stack.push(node.right);
            }
            if(node.left != null)
            {
                stack.push(node.left);
            }
        }
        System.out.println();
    }

    public static void main(String args[])
    {
        BinaryTree1 tree = new BinaryTree1();
        tree.root = new Node(1);
        tree.root.left = new Node(5);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(7);
        tree.root.right.right = new Node(9);
        tree.iterativePreorder();
    }
}
