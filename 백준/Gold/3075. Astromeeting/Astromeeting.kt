import java.io.*
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    repeat(br.readLine().toInt()) {
        var (n, m, k) = br.readLine().split(" ").map{it.toInt()}
        var ary = IntArray(n + 1)
        for (i in 1..n) {
            ary[i] = br.readLine().toInt()
        }
        var dist = Array(m + 1) {LongArray(m + 1) {1e7.toLong()}}
        for (i in 1..k) {
            var (a, b, c) = br.readLine().split(" ").map{it.toInt()}
            dist[a][b] = minOf(dist[a][b], c.toLong())
            dist[b][a] = minOf(dist[b][a], c.toLong())
        }
        for (i in 1..m) {
            dist[i][i] = 0
        }
        for (i in 1..m) {
            for (j in 1..m) {
                for (k in 1..m) {
                    dist[j][k] = minOf(dist[j][k], dist[j][i] + dist[i][k])
                }
            }
        }
        var a = 1e18.toLong()
        var b = 1e18.toLong()
        for (i in 1..m.toLong()) {
            var sum = 0L
            for (j in 1..n) {
                sum += dist[ary[j]][i.toInt()] * dist[ary[j]][i.toInt()]
            }
            if (b > sum) {
                b = sum
                a = i
            }
        }
        bw.write("$a $b\n")
    }
    bw.flush()
    bw.close()
}