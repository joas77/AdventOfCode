import java.io.File
fun main(){
    println("part1 solution: ")
    part1("./input/input.txt")
    println("part2 solution: ")
    part2("./input/input.txt")
}

fun part1(inputPath: String) {
    val rucksacksData = File(inputPath).inputStream()

    var prioSum = 0
    rucksacksData.bufferedReader().forEachLine { line:String ->
        val firstHalf = line.substring(0, line.length / 2)
        val secondHalf = line.substring(line.length / 2)

        val commonItems = firstHalf.toSet().intersect(secondHalf.toSet())
        prioSum += sumPriorities(commonItems)
    }
    println("Total priority sum: $prioSum")
}

fun getPriority(item: Char): Int {
    return if (item.isLowerCase()) {
        item.code - 'a'.code + 1
    } else {
        item.code - 'A'.code + 27
    }
}

fun sumPriorities(items: Set<Char>): Int {
    var sum = 0
    for (item in items) {
        sum += getPriority(item)
    }

    return sum
}

fun part2(inputPath: String) {
    val rucksacksData = File(inputPath).inputStream()
    val lines = rucksacksData.bufferedReader().readLines()

    var prioSum = 0
    for (e in lines.withIndex()) {
        if((e.index + 1) % 3 == 0) {

            val (third, second, first ) = listOf(lines[e.index].toSet(),
                lines[e.index - 1].toSet(),
                lines[e.index - 2].toSet()
            )

            val commonItems = first.intersect(second).intersect(third)
            prioSum += sumPriorities(commonItems)
        }
    }

    println("Total priority sum: $prioSum")
}