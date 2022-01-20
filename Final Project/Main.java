import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class Graph {
    private ArrayList<ArrayList<Node>> nodes;
    private ArrayList<ArrayList<Boolean>> marks;
    private Node root;
    private int size;

    public Graph() {
        this.nodes = new ArrayList<>();
        this.marks = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            nodes.add(new ArrayList<Node>());
            marks.add(new ArrayList<Boolean>());
        }
    }

    public ArrayList<ArrayList<Boolean>> getMarks() {
        return marks;
    }

    public static int getHashCodeByNode(Node node) {
        return node.getData() % 10;
    }

    public static int getHashCodeByNum(int num) {
        return num % 10;
    }

    public Node getNode(int num) {
        int hashCode = getHashCodeByNum(num);
        for (Node n : this.nodes.get(hashCode)) {
            if (n.getData() == num) {
                return n;
            }
        }
        return null;
    }

    public ArrayList<ArrayList<Node>> getNodes() {
        return nodes;
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void dfs(Node u, int kind) 
    {
        int t = 0;
        for(t = 0; t < this.nodes.get(getHashCodeByNode(u)).size() ; t++)
        {
            if(this.nodes.get(getHashCodeByNode(u)).get(t).getData() == u.getData())
            {
                break;
            }
        }
        this.marks.get(getHashCodeByNode(u)).set(t, true);
        if(kind == 0) 
        {
            System.out.print(u.getData() + " ");
        } 
        else if(kind == 1) 
        {
            dijkstra(u);
        } 
        else if(kind == 2)
        {   
            u.printDistances();
        }
        else
        {

        }
        for(int i = 0; i < u.getEdges().getSize(); i++) 
        {
            Node v = this.getNode(u.getEdges().getEdge(i).getDestination());
            int j = 0;
            for(j = 0; j < this.nodes.get(getHashCodeByNode(v)).size() ; j++)
            {
                if(this.nodes.get(getHashCodeByNode(v)).get(j).getData() == v.getData())
                {
                    break;
                }
            }
            if(this.marks.get(getHashCodeByNode(v)).get(j) == false) 
            {
                this.dfs(v, kind);
            }
        }
    }

    public void resetMarks() 
    {
        for (int i = 0; i < 10; i++) 
        {
            for(int j = 0; j < this.marks.get(i).size(); j++)
            {
                this.marks.get(i).set(j, false);
            }
        }
    }

    public void dijkstra(Node s) 
    {
        PriorityQueue<Pii> pq = new PriorityQueue<Pii>(this.size, new Pii());
        Pii pt = new Pii(0, s.getData());
        pq.add(pt);
        s.getDistances().get(getHashCodeByNode(s)).add(pt);
        for(int i = 0; i < 10; i++)
        {
            for(Node node : nodes.get(i))
            {
                if(node.getData() != s.getData())
                {
                    Pii p = new Pii(Integer.MAX_VALUE, node.getData());
                    pq.add(p);
                    s.getDistances().get(i).add(p);
                }
            }
        }
        while(pq.size() > 0)
        {
            Pii p = pq.remove();
            Node u = this.getNode(p.getS());
            for(int i = 0; i < u.getEdges().getSize(); i++)
            {
                int w = u.getEdges().getEdge(i).getWeight();
                Node v = this.getNode(u.getEdges().getEdge(i).getDestination());
                if(s.getDist(v.getData()) > s.getDist(u.getData()) + w)
                {
                    pq.remove(new Pii(s.getDist(v.getData()), v.getData()));
                    s.setDist(v.getData(), s.getDist(u.getData()) + w);
                    pq.add(new Pii(s.getDist(v.getData()), v.getData()));
                }
            }
        }
    }

    public void testGraph() 
    {
        System.out.println("--------------------------------------------------------");
        this.resetMarks();
        dfs(this.root, 0);
        System.out.println("\n--------------------------------------------------------");
    }

    public void dijkstraOnAll()
    {
        this.resetMarks();
        dfs(this.root, 1);
    }

    public void printAllDistances()
    {
        System.out.println("--------------------------------------------------------");
        this.resetMarks();
        dfs(this.root, 2);
        System.out.println("--------------------------------------------------------");
    }
}

class Pii implements Comparator<Pii> {
    private int f;
    private int s;

    public Pii()
    {

    }

    public Pii(int f, int s) {
        this.f = f;
        this.s = s;
    }

    public int getF() {
        return f;
    }

    public void setF(int f) {
        this.f = f;
    }

    public int getS() {
        return s;
    }

    public void setS(int s) {
        this.s = s;
    }

    @Override
    public int compare(Pii p1, Pii p2) {
        if (p1.getF() == p2.getF()) {
            if (p1.getS() == p2.getS()) {
                return 0;
            } else if (p1.getS() < p2.getS()) {
                return -1;
            } else {
                return 1;
            }
        } else if (p1.getF() < p2.getF()) {
            return -1;
        } else {
            return 1;
        }
    }

    @Override
    public boolean equals(Object o) 
    {
        if(o == this)
        {
            return true;
        }
        if (!(o instanceof Pii)) 
        {
            return false;
        }
        Pii p = (Pii)o;
        if(p.getF() == this.f && p.getS() == this.s)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class Node {
    private int data;
    private Adj edges;
    private ArrayList<ArrayList<Pii>> dist; // first : node distance        second : node num

    public Node(int data) {
        this.data = data;
        this.edges = new Adj();
        this.dist = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            this.dist.add(new ArrayList<Pii>());
        }
    }

    public int getData() {
        return data;
    }

    public Adj getEdges() {
        return edges;
    }

    public ArrayList<ArrayList<Pii>> getDistances() {
        return dist;
    }

    public int getDist(int i) 
    {
        for(Pii p : this.dist.get(Graph.getHashCodeByNum(i)))
        {
            if(p.getS() == i)
            {
                return p.getF();
            }
        }
        return Integer.MAX_VALUE;
    }

    public void setDist(int i, int w) 
    {
        for(Pii p : this.dist.get(Graph.getHashCodeByNum(i)))
        {
            if(p.getS() == i)
            {
                p.setF(w);
            }
        }
    }

    public void printDistances()
    {
        System.out.println("-----------------");
        System.out.println(this.data + " : ");
        for(int i = 0; i < 10; i++)
        {
            for(Pii p : this.dist.get(i))
            {
                System.out.println(this.data + " -> " + p.getS() + " : " + p.getF());
            }
        }
        System.out.println("-----------------");
    }
}

class Adj {
    private int size;
    private Edge front;
    private Edge back;

    public Adj() {
        this.size = 0;
        this.front = null;
        this.back = null;
    }

    public void pushBackEdge(Edge newEdge) {
        if (this.back == null) {
            this.back = newEdge;
            this.front = newEdge;
        } else {
            this.getBack().setNextEdge(newEdge);
            this.back = newEdge;
        }
        size++;
    }

    public Edge getEdge(int i) {
        if (i < 0 || i >= this.size) {
            return null;
        }
        Edge cur = this.front;
        for (int j = 0; j < i; j++) {
            cur = cur.getNextEdge();
        }
        return cur;
    }

    public Edge getBack() {
        return back;
    }

    public int getSize() {
        return size;
    }

    public Edge getFront() {
        return front;
    }
}

class Edge {
    private int destination;
    private int weight;
    private Edge nextEdge;

    public Edge(int destination, int weight) {
        this.destination = destination;
        this.weight = weight;
        this.nextEdge = null;
    }

    public int getDestination() {
        return destination;
    }

    public int getWeight() {
        return weight;
    }

    public Edge getNextEdge() {
        return nextEdge;
    }

    public void setNextEdge(Edge nextEdge) {
        this.nextEdge = nextEdge;
    }
}

public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph();
        Scanner input = new Scanner(System.in);
        int n, m;
        n = input.nextInt();
        m = input.nextInt();
        for (int i = 0; i < n; i++) {
            int x = input.nextInt();
            Node newNode = new Node(x);
            graph.setRoot(newNode);
            graph.getNodes().get(Graph.getHashCodeByNum(x)).add(newNode);
            graph.getMarks().get(Graph.getHashCodeByNum(x)).add(false);
            graph.setSize(graph.getSize() + 1);
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            u = input.nextInt();
            v = input.nextInt();
            w = input.nextInt();
            graph.getNode(u).getEdges().pushBackEdge(new Edge(v, w));
            graph.getNode(v).getEdges().pushBackEdge(new Edge(u, w));
        }
        graph.dijkstraOnAll();
    }
}