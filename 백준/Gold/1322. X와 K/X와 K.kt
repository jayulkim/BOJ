import java.io.*
import java.util.*
import kotlin.math.*

fun solve(n : Long, m : Long) : Long {
    var result = 0L
    val list = mutableListOf<Long>()
    for (i in 0..60) {
        if ((n shr i) and 1L == 0L) {
            list.add(1L shl i)
        }
    }
    for (i in 0..<list.size) {
        if ((m shr i) and 1L == 1L) {
            result += list[i]
        }
    }
    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = br.readLine()!!.split(" ").map{ it.toLong() }
    bw.write("${solve(n, m)}")
    bw.flush()
    bw.close()
}