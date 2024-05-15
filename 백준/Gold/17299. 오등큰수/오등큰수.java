import java.io.BufferedReader;
import java.io.IOException;
import java.sql.SQLOutput;
import java.io.*;
import java.util.Stack;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        int n = Integer.parseInt(str);
        String[] str1 = br.readLine().split(" ");
        Integer[] frequency = new Integer[1000001];
        int[] result = new int[n];
        for (int i = 0; i < frequency.length; i++)
        {
            frequency[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            frequency[Integer.parseInt(str1[i])]++;
        }
        Stack<Integer> stack = new Stack<Integer>();
        Stack<Integer> stack1 = new Stack<Integer>();
        for (int i = n - 1; i >= 0; i--)
        {
            if (stack.isEmpty())
            {
                result[i] = -1;
                stack.push(frequency[Integer.parseInt(str1[i])]);
                stack1.push(Integer.parseInt(str1[i]));
            }
            else
            {
                while (!stack.isEmpty() && stack.peek() <= frequency[Integer.parseInt(str1[i])])
                {
                    stack.pop();
                    stack1.pop();
                }
                if (stack.isEmpty())
                {
                    result[i] = -1;
                }
                else
                {
                    result[i] = stack1.peek();
                }
                stack.push(frequency[Integer.parseInt(str1[i])]);
                stack1.push(Integer.parseInt(str1[i]));
            }
        }
        for (int i = 0; i < n; i++)
        {
            sb.append(result[i]).append(" ");
        }
        System.out.println(sb);
    }
}