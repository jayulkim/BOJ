import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{
    static long ary[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    static long addmod(long x, long y, long num)
    {
        x %= num;
        y %= num;
        if (num - y <= x)
        {
            return x - (num - y);
        }
        else
        {
            return x + y;
        }
    }
    static long mulmod(long x, long y, long num)
    {
        x %= num;
        y %= num;
        long result = 0;
        while (y > 0)
        {
            if (y % 2 == 1)
            {
                result = addmod(result, x, num);
                result %= num;
            }
            x = addmod(x, x, num);
            x %= num;
            y /= 2;
        }
        return result;
    }
    static long powmod(long x, long y, long num)
    {
        x %= num;
        y %= num;
        long result = 1;
        while (y > 0)
        {
            if (y % 2 == 1)
            {
                result = mulmod(result, x, num);
                result %= num;
            }
            x = mulmod(x, x, num);
            x %= num;
            y /= 2;
        }
        return result;
    }
    static int milerlabin(long a, long num)
    {
        if (num == 1)
        {
            return 1;
        }
        if (num == 2)
        {
            return 0;
        }
        if (num == a)
        {
            return 0;
        }
        long num1 = num - 1;
        while (true)
        {
            long temp = powmod(a, num1, num);
            if (temp == num - 1)
            {
                return 0;
            }
            else
            {
                if (num1 % 2 == 0)
                {
                    num1 /= 2;
                }
                else
                {
                    if (temp == num - 1 || temp % num == 1)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
        }
    }
    static long gcd(long num1, long num2)
    {
        long temp = num1 % num2;
        while (temp > 0)
        {
            num1 = num2;
            num2 = temp;
            temp = num1 % num2;
        }
        return num2;
    }
    static int isprime(long num)
    {
        for (int i = 0; i < 12; i++)
        {
            if (milerlabin(ary[i], num) == 1)
            {
                return 1;
            }
        }
        return 0;
    }
    static long Random(long x, long c, long num)
    {
        return (mulmod(x, x, num) % num + c) % num;
    }
    static long pollardrho(long num)
    {
        if (num % 2 == 0)
        {
            return 2;
        }
        if (isprime(num) == 0)
        {
            return num;
        }
        long x = (long)(Math.random() * (num - 2)) + 1;
        long y = x;
        long c = (long)(Math.random() * 3) * 2 - 1;
        long d = 1;
        while (gcd(d,num) == 1)
        {
            x = Random(x, c, num) % num;
            y = Random(y, c, num) % num;
            y = Random(y, c, num) % num;
            d = Math.abs(x - y);
            if (gcd(d, num) == num)
            {
                return pollardrho(gcd(d, num));
            }
        }
        if (isprime(gcd(d, num)) == 0)
        {
            return gcd(d, num);
        }
        else
        {
            return pollardrho(gcd(d, num));
        }
    }
    static void oilerpi(long num)
    {
        long solve = 1;
        long result[] = new long[65];
        int index = 1;
        while (num > 1)
        {
            long num1 = pollardrho(num);
            result[index++] = num1;
            num /= num1;
        }
        Arrays.sort(result, 1, index);
        for (int i = 1; i < index; i++)
        {
            if (result[i] != result[i - 1])
            {
                solve *= (result[i] - 1);
            }
            else
            {
                solve *= result[i];
            }
        }
        System.out.print(solve);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long num1 = Long.parseLong(br.readLine());
        oilerpi(num1);
    }
}