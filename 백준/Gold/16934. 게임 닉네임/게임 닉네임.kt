import java.io.*
import java.util.*
import kotlin.math.*

fun solve(n : Int, ary : Array<String>) : Array<String> {
    val prefixmap = TreeMap<String, Int>()
    val namemap = TreeMap<String, Int>()
    val result = Array(n){ "" }
    for (i in 0..<n) {
        var temp = ""
        var str = ""
        for (char in ary[i]) {
            temp += char
            if (prefixmap[temp] == null && str.isEmpty()) {
                str = temp
            }
            prefixmap[temp] = (prefixmap[temp] ?: 0) + 1
        }
        namemap[ary[i]] = (namemap[ary[i]] ?: 0) + 1
        result[i] = when {
            str.isNotEmpty() -> str
            namemap[ary[i]] == 1 -> ary[i]
            else -> ary[i] + namemap[ary[i]]
        }
    }
    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine()!!.toInt()
    val ary = Array(n){ "" }
    for (i in 0..<n) {
        ary[i] = br.readLine()
    }
    val result = solve(n, ary)
    for (i in 0..<n) {
        bw.write(result[i] + "\n")
    }
    bw.flush()
    bw.close()
}