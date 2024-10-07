import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class search
{
    public static int findup(int n)
    {
        int count = 1;
        while (n > 2 * count * count - count)
        {
            count++;
        }
        if (2 * count * count - count - n + 1 > 2 * count - 1)
        {
            return 2 * (2 * count - 1) - (2 * count * count - count - n + 1);
        }
        else
        {
            return 2 * count * count - count - n + 1;
        }
    }
    public static int finddown(int n)
    {
        int count = 1;
        while (n > 2 * count * count + count)
        {
            count++;
        }
        if (2 * count * count + count - n + 1 > 2 * count)
        {
            return 4 * count - (2 * count * count + count - n + 1);
        }
        else
        {
            return 2 * count * count + count - n + 1;
        }
    }
    public static void solve(int n)
    {
        System.out.print(findup(n) + "/" + finddown(n));
    }
}

public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException
    {
        String str = br.readLine();
        int num1 = Integer.parseInt(str);
        search.solve(num1);
    }
}

