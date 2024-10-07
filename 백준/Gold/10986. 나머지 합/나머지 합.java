import java.io.BufferedReader;
import java.io.IOException;
import java.sql.SQLOutput;
import java.io.*;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]), m = Integer.parseInt(str[1]);
        long[] ary = new long[n];
        long[] sum = new long[n];
        long[] result = new long[m + 1];
        long count = 0;
        String[] str1 = br.readLine().split(" ");
        for (int i = 0; i < n; i++)
        {
           ary[i] = Integer.parseInt(str1[i]);
        }
        sum[0] = ary[0] % m;
        if(sum[0] == 0)
        {
            count++;
        }
        result[(int)sum[0] % (int)m]++;
        for (int i = 1; i < n; i++)
        {
            sum[i] = (sum[i - 1] % m + ary[i] % m) % m;
            if(sum[i] == 0)
            {
                count++;
            }
            result[(int)sum[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            if (result[i] != 0)
            {
                count += (result[i] - 1) * result[i] / 2;
            }
        }
        System.out.println(count);
    }
}