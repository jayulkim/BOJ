import java.io.*
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    repeat(br.readLine().toInt()) {
        val (n, m, k) = br.readLine().split(" ").map{it.toInt()}
        val ary = IntArray(n + 1)
        for (i in 1..n) {
            ary[i] = br.readLine().toInt()
        }
        val inf = 1000000000L
        val dist = Array(m + 1) {LongArray(m + 1) {inf}}
        for (i in 1..k) {
            val (a, b, c) = br.readLine().split(" ").map{it.toInt()}
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
        var a = 0
        var b = Long.MAX_VALUE
        for (i in 1..m) {
            var sum = 0L
            var find = false
            for (j in 1..n) {
                val d = dist[ary[j]][i]
                if (d == inf) {
                    find = true
                    break
                }
                sum += d * d
            }
            if (b > sum && !find) {
                b = sum
                a = i
            }
        }
        bw.write("$a $b\n")
    }
    bw.flush()
    bw.close()
}