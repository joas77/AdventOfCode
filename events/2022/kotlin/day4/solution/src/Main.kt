import java.io.File

fun main() {
    val input = File("./input/input.txt").inputStream().bufferedReader().readLines()
    part1(input)
    part2(input)
}

fun part1(input: List<String>) {
    var overlaps = 0
    for(l in input){
        val ranges = lineToRanges(l)
        overlaps += if (
            ranges[0].containsAll(ranges[1])  || ranges[1].containsAll(ranges[0])
            ) 1 else 0

    }
    println("Overlaps: $overlaps")
}

fun lineToRanges(line: String): List<Set<Int>> {
    return line.split(",")
        .map {
            it.split("-").map { num -> num.toInt() }
        }
        .map { it[0]..it[1] }
        .map { it.toSet() }
}

fun part2(input: List<String>) {
    var overlaps = 0
    for(l in input){
        val ranges = lineToRanges(l)
        overlaps += if (
            ranges[0].intersect(ranges[1]).isNotEmpty()
            ) 1 else 0
    }
    println("Overlaps: $overlaps")
}