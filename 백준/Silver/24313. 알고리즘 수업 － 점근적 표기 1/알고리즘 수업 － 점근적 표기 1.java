import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class bigO
{
    public static void solve(int a1, int a0, int c, int n0)
    {
        if (a1 > c)
        {
            System.out.print(0);
            return;
        }
        else if (a1 == c)
        {
            if (a0 <= 0)
            {
                System.out.println(1);
                return;
            }
            else
            {
                System.out.println(0);
                return;
            }
        }
        else
        {
            if (a0 <= n0 * (c - a1))
            {
                System.out.println(1);
                return;
            }
            else
            {
                System.out.println(0);
                return;
            }
        }
    }

}

public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException
    {
        int a1 = 0, a0 = 0, c = 0, n0 = 0;
        String[] str = br.readLine().split(" ");
        a1 = Integer.parseInt(str[0]);
        a0 = Integer.parseInt(str[1]);
        String str1 = br.readLine();
        c = Integer.parseInt(str1);
        String str2 = br.readLine();
        n0 = Integer.parseInt(str2);
        bigO.solve(a1, a0, c, n0);
    }
}

