import java.awt.dnd.Autoscroll;
import java.io.*;
import java.util.*;
public class Main
{
    static class Dict
    {
        String word;
        int count;
        public Dict(String w, int c)
        {
            this.word = w;
            this.count = c;
        }
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        Comparator<Dict> comparedict = new Comparator<Dict>()
        {
            @Override
            public int compare(Dict num1, Dict num2)
            {
                if (num1.count == num2.count)
                {
                    if (num1.word.length() == num2.word.length())
                    {
                        return num1.word.compareTo(num2.word);
                    }
                    else
                    {
                        return num2.word.length() - num1.word.length();
                    }
                }
                else
                {
                    return num2.count - num1.count;
                }
            }
        };
        int n = 0, m = 0;
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        Vector<String>v = new Vector<String>();
        Vector<Dict>result = new Vector<Dict>();
        for (int i = 0; i < n; i++)
        {
            String s = br.readLine();
            if (s.length() >= m)
            {
                v.add(s);
            }
        }
        Collections.sort(v, (s1, s2) -> s1.compareTo(s2));
        int count = 1;
        v.add(" ");
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (!Objects.equals(v.get(i), v.get(i + 1)))
            {
                Dict New = new Dict(v.get(i), count);
                result.add(New);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        Collections.sort(result, comparedict);
        for (Dict i : result)
        {
            sb.append(i.word).append("\n");
        }
        System.out.print(sb);
    }
}