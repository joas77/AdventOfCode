import java.io.File

fun main() {
    val strategy = "./input/input.txt"
    println("Part 1 solution")
    part1(strategy)
    println("Part 2 solution")
    part2(strategy)
}

fun gameScoreCalculator(opponentAction: RockPaperScissors, myAction: RockPaperScissors): Int {
    return if (myAction.defeats == opponentAction.name) { // win
        6
    } else if (opponentAction.defeats == myAction.name) { // lose
        0
    } else { // draw
        3
    }
}

fun part1(filePath: String) {
    val strategy = File("./input/input.txt").inputStream()
    val opponentActionToPoints = mapOf(
        "A" to RockPaperScissors("rock"),
        "B" to RockPaperScissors("paper"),
        "C" to RockPaperScissors("scissors")
    )

    val myActionToPoints = mapOf(
        "X" to RockPaperScissors("rock"),
        "Y" to RockPaperScissors("paper"),
        "Z" to RockPaperScissors("scissors")
    )

    var totalScore = 0
    strategy.bufferedReader().forEachLine {
        val (opponent, me) = it.split("\\s+".toRegex())
        val opponentAction = opponentActionToPoints[opponent]
        val myAction = myActionToPoints[me]
        totalScore += gameScoreCalculator(opponentAction!!, myAction!!) + myAction.score
    }
    println("Total score: $totalScore")
}

fun part2(filePath: String) {
    val strategy = File("./input/input.txt").inputStream()
    val opponentActionToPoints = mapOf(
        "A" to RockPaperScissors("rock"),
        "B" to RockPaperScissors("paper"),
        "C" to RockPaperScissors("scissors")
    )

    val expectedResult = mapOf(
        "X" to "lose",
        "Y" to "draw",
        "Z" to "win"
    )

    var totalScore = 0
    strategy.bufferedReader().forEachLine {
        val (opponent, me) = it.split("\\s+".toRegex())
        val opponentAction = opponentActionToPoints[opponent]
        val expectedOutcome = expectedResult[me]

        val myAction = when (expectedOutcome) {
            "win" -> RockPaperScissors(opponentAction!!.defeatedBy)
            "lose" -> RockPaperScissors(opponentAction!!.defeats)
            "draw" -> opponentAction
            else -> throw IllegalArgumentException("Invalid expected outcome: $expectedOutcome")
        }
        totalScore += gameScoreCalculator(opponentAction!!, myAction!!) + myAction.score
    }
    println("Total score: $totalScore")
}
