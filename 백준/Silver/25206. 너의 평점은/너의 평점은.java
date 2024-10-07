import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

class student
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static double score (String str)
    {
        double result = 0;
        switch (str)
        {
            case "A+":
            {
                result = 4.5;
                break;
            }
            case "A0":
            {
                result = 4.0;
                break;
            }
            case "B+":
            {
                result = 3.5;
                break;
            }
            case "B0":
            {
                result = 3.0;
                break;
            }
            case "C+":
            {
                result = 2.5;
                break;
            }
            case "C0":
            {
                result = 2.0;
                break;
            }
            case "D+":
            {
                result = 1.5;
                break;
            }
            case "D0":
            {
                result = 1.0;
                break;
            }
            case "F":
            {
                result = 0.0;
                break;
            }
            default:
            {
                result = -1;
                break;
            }
        }
        return result;
    }
    public static void solve () throws IOException
    {
        double sum = 0;
        double sizesum = 0;
        for (int i = 0; i < 20; i++)
        {
            String str[] = br.readLine().split(" ");
            double score = score (str[2]);
            double size = Double.parseDouble(str[1]);
            if (score != -1)
            {
                sum += (score * size);
                sizesum += size;
            }
        }
        System.out.println(sum / sizesum);
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        student.solve();
    }
}