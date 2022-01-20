import java.util.ArrayList;
import java.util.Scanner;

class Graph 
{
    private ArrayList<ArrayList<Node>> nodes;
    private Boolean markState;
    private Node root;

    public Graph()
    {
        this.markState = false;
        this.nodes = new ArrayList<>();
        for(int i = 0; i < 10; i++)
        {
            nodes.add(new ArrayList<Node>());
        }
    }

    public int getHashCodeByNode(Node node)
    {
        return node.getData() % 10;
    }

    public int getHashCodeByNum(int num)
    {
        return num % 10;
    }

    public Node getNode(int num)
    {
        int hashCode = getHashCodeByNum(num);
        for(Node n : this.nodes.get(hashCode))
        {
            if(n.getData() == num)
            {
                return n;
            }
        }
        return null;
    }

    public ArrayList<ArrayList<Node>> getNodes() 
    {
        return nodes;
    }

    public Boolean getMarkState() 
    {
        return markState;
    }

    public void changeMarkState()
    {
        this.markState = !this.markState;
    }

    public Node getRoot() 
    {
        return root;
    }

    public void setRoot(Node root) 
    {
        this.root = root;
    }

    public void dfs(Node u, Boolean test)
    {
        if(test == true)
        {
            System.out.println(u.getData() + " ");
        }
        else
        {
            dijkstra(u);
        }
        u.changeMark();
        for(int i = 0; i < u.getEdges().getSize(); i++)
        {
            Node v = this.getNode(u.getEdges().getEdge(i).getDestination());
            if(v.getMark() == this.markState)
            {
                System.out.println(u.getData() + " -> " + v.getData());
                this.dfs(v, test);
            }
        }
    }

    public void dijkstra(Node s)
    {
        
    }

    public void testGraph()
    {
        dfs(this.root, true);
        System.out.println();
        this.changeMarkState();
    }
}

class Node 
{
    private int data;
    private Adj edges;
    private Boolean mark;

    public Node(int data)
    {
        this.data = data;
        this.edges = new Adj();
        this.mark = false;
    }

    public int getData() 
    {
        return data;
    }

    public Adj getEdges() 
    {
        return edges;
    }

    public Boolean getMark() 
    {
        return mark;
    }

    public void changeMark()
    {
        this.mark = !this.mark;
    }
}

class Adj
{
    private int size;
    private Edge front;
    private Edge back;

    public Adj()
    {
        this.size = 0;
        this.front = null;
        this.back = null;
    }

    public void pushBackEdge(Edge newEdge)
    {
        if(this.back == null)
        {
            this.back = newEdge;
            this.front = newEdge;
        }
        else
        {
            this.getBack().setNextEdge(newEdge);
            this.back = newEdge;
        }
        size++;
    }

    public Edge getEdge(int i)
    {
        if(i < 0 || i >= this.size)
        {
            return null;
        }
        Edge cur = this.front;
        for(int j = 0; j < i; j++)
        {
            cur = cur.getNextEdge();
        }
        return cur;
    }

    public Edge getBack() 
    {
        return back;
    }

    public int getSize() 
    {
        return size;
    }

    public Edge getFront() 
    {
        return front;
    }
}

class Edge
{
    private int destination;
    private int weight;
    private Edge nextEdge;

    public Edge(int destination, int weight)
    {
        this.destination = destination;
        this.weight = weight;
        this.nextEdge = null;
    }

    public int getDestination() 
    {
        return destination;
    }

    public int getWeight() 
    {
        return weight;
    }

    public Edge getNextEdge() 
    {
        return nextEdge;
    }

    public void setNextEdge(Edge nextEdge) 
    {
        this.nextEdge = nextEdge;
    }
}

public class Main 
{
    public static void main(String[] args) 
    {
        Graph graph = new Graph();
        Scanner input = new Scanner(System.in);
        int n, m;
        n = input.nextInt();
        m = input.nextInt();
        for(int i = 0; i < n; i++)
        {
            int x = input.nextInt();
            Node newNode = new Node(x);
            graph.setRoot(newNode);
            graph.getNodes().get(graph.getHashCodeByNum(x)).add(newNode);
        }  
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            u = input.nextInt();
            v = input.nextInt();
            w = input.nextInt();
            graph.getNode(u).getEdges().pushBackEdge(new Edge(v, w));
            graph.getNode(v).getEdges().pushBackEdge(new Edge(u, w));
        }
        graph.testGraph();
        //System.out.println(graph.getNode(7).getEdges().getEdge(0).getDestination());
    }
}