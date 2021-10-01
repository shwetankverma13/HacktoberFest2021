import java.util.*;
class connected_Comp
{
    private int V;
    private LinkedList <Integer> adj[];
    connected_Comp(int v)
    {

        V=v;
        adj=new LinkedList[v];
        for(int i=0;i<V;i++)
            adj[i]=new LinkedList();

    }

    void addEdge(int v,int w)
    {
        adj[v].add(w);
        adj[w].add(v);
    }

    void dfs_util(int v,boolean visited[])
    {
        visited[v]=true;
        //System.out.println(v);
        Iterator <Integer> i=adj[v].listIterator();
        int n;
        while(i.hasNext())
        {
            n=i.next();
            if(!visited[n])
                dfs_util(n,visited);
        }
    }

    void dfs(int v)
    {
        boolean visited[]=new boolean[V];
        int z=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfs_util(i,visited);
                z++;
            }
        }
        System.out.println(z);
    }

    static long pow(long p,long tt,long mod)
    {
        long ii,q,r;
        q=1l;
        r=p;
        while(tt>1)
        {
            for(ii=1l;2*ii<=tt;ii*=2l)
                p=((p%mod)*(p%mod))%mod;
            tt-=ii;
            q=((q%mod)*(p%mod))%mod;
            p=r;
        }
        if(tt==1)
            q=((q%mod)*(r%mod))%mod;
        return q;
    }

    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        int n,s,t,i;
        t=d.nextInt();

        while(t-->0)
        {
            n=d.nextInt();
            int a[]=new int[n];
            connected_Comp g=new connected_Comp(n);
            for(i=0;i<n;i++)
                a[i]=d.nextInt()-1;
            for(i=0;i<n;i++)
                g.addEdge(i,a[i]);
            g.dfs(n);
        }
    }
}
