import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{
    static void solve(long num)
    {
        System.out.println(4 * num);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long num1 = Long.parseLong(br.readLine());
        solve(num1);
    }
}