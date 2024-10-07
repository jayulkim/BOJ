import java.io.*;
import java.util.Deque;
import java.util.LinkedList;

class questack
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Deque<Integer> dq = new LinkedList<>();
    static StringBuilder sb = new StringBuilder();
    public static int Return(int m)
    {
        dq.addFirst(m);
        return dq.pollLast();
    }
    public static void solve() throws IOException
    {
        String str = br.readLine();
        int[] map = new int[Integer.parseInt(str)];
        String[] str1 = br.readLine().split(" ");
        for (int i = 0; i < Integer.parseInt(str); i++)
        {
            map[i] = Integer.parseInt(str1[i]);
        }
        String[] str2 = br.readLine().split(" ");
        for (int i = 0; i < Integer.parseInt(str); i++)
        {
            if (map[i] == 0)
            {
                dq.addLast(Integer.parseInt(str2[i]));
            }
        }
        String str3 = br.readLine();
        String[] str4 = br.readLine().split(" ");
        for (int i = 0; i < Integer.parseInt(str3); i++)
        {
            sb.append(Return(Integer.parseInt(str4[i])));
            sb.append(" ");
        }
        System.out.println(sb);
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        questack.solve();
    }
}