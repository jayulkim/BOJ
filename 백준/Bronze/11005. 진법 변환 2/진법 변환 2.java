import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

class change
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    public static void mod(int num1, int num2)
    {
        while (num1 > 0)
        {
            int temp = num1 % num2;
            if (temp <= 9)
            {
                sb.append(temp);
            }
            else
            {
                sb.append((char)('A' + (temp - 10)));
            }
            num1 /= num2;
        }
    }
    public static void solve () throws IOException
    {
        String str[] = br.readLine().split(" ");
        mod(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
        System.out.println(sb.reverse());
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        change.solve();
    }
}