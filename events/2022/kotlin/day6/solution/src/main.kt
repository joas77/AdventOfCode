import java.io.File
fun main() {
    val input = File("input/input.txt").readLines()[0].trim()
    solution(input, 4)
    solution(input, 14)
}

fun solution(dataStream: String, markerSize:Int) {
    println(dataStream)
    var i = 0
    while ( i <dataStream.length -1) {
        val windowStream = dataStream.substring(i..<i+markerSize).toSet()
        if (windowStream.size == markerSize) {
            println("Marker found at index: ${i + markerSize}, ${dataStream.substring(i..<i + markerSize)}")
            break
            // i+= 4
        }
        else {
            i++
        }
    }
}