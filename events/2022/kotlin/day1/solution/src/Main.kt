import java.io.File

fun main() {
    val calories = File("./input/input.txt").inputStream()
    var elfCaloriesSum = mutableListOf<Int>()
    var calorieSum: Int = 0
    calories.bufferedReader().forEachLine {
        //println(it)
        val l = it.trim()
        if (l == "") {
            elfCaloriesSum.add(calorieSum)
            calorieSum = 0
        }else{
            calorieSum += l.toInt()
        }
    }

    // make sure last element is added
    elfCaloriesSum.add(elfCaloriesSum.size - 1,calorieSum)

    elfCaloriesSum.sort()

    println("===================")
    elfCaloriesSum.forEach { println(it) }
    println("==================")
    println("part 1 one solution")
    println(elfCaloriesSum[elfCaloriesSum.size - 1])

    println("part 2 solution:")
    var top3Calsum = 0
    for (i in 1..3){
        top3Calsum += elfCaloriesSum[elfCaloriesSum.size - i]
    }
    println(top3Calsum)
}