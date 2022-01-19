class Graph 
{


    public void dfs(int s)
    {

    }

    public void dijksta(int s)
    {
        
    }
}

class Node 
{
    private int data;
    private Adj edges;
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

    public pushBack(Edge newEdge)
    {
        this.getBack().setNextEdge(newEdge);
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