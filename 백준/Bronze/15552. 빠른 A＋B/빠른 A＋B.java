import java.io.*;

public class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException
    {
        String str = br.readLine();
        for (int i = 0; i < Integer.parseInt(str); i++)
        {
            String[] str1 = br.readLine().split(" ");
            sb.append(Integer.parseInt(str1[0]) + Integer.parseInt(str1[1])).append('\n');
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}

