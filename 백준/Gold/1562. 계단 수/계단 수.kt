import java.io.*
import kotlin.math.*
typealias ii = Int
typealias ll = Long
typealias ld = Double

fun dfs(dp: Array<Array<LongArray>>, len : ii, temp : ii, prev : ii, end : ii, mod : ll) : ll {
    if (len == end) {
        if (temp == (1 shl 10) - 1) {
            return 1
        }
        return 0
    }
    if (dp[len][temp][prev] != -1L) {
        return dp[len][temp][prev]
    }
    var weight = 0L
    for (i in 0..9) {
        if (abs(prev - i) == 1) {
            weight += dfs(dp, len + 1, temp or (1 shl i), i, end, mod) % mod
            weight %= mod
        }
    }
    dp[len][temp][prev] = weight
    return weight
}

fun solve(n : ii) : ll {
    var result = 0L
    val dp = Array(n) { Array(1 shl 10) { LongArray(10){ -1 } } }
    val mod = 1000000000L
    for (i in 1..9) {
        result += dfs(dp, 1, 1 shl i, i, n, mod)
        result %= mod
    }
    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    var result = solve(n)
    bw.write("$result")
    bw.flush()
    bw.close()
}