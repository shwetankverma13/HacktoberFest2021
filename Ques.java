public class Ques
{
    public static int x=7;
    public static void main(String args[])
    {
        Ques a=new Ques();
        Ques b=new Ques();
        a.x=2;
        b.x=3;
        System.out.println(a.x);
        System.out.println(b.x);
        System.out.println(Ques.x);
        System.out.println(a.x+b.x+++Ques.x);
    }
}
