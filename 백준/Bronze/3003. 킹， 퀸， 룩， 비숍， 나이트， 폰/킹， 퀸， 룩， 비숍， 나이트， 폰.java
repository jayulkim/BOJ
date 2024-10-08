import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        StringBuilder sb = new StringBuilder();
        int ary1[] = {1,1,2,2,2,8};
        for (int i = 0; i < 6; i++)
        {
            int num1 = Integer.parseInt(st.nextToken());
            sb.append(ary1[i] - num1).append(" ");
        }
        System.out.println(sb);
    }
}