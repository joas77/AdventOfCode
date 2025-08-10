import java.io.File
import java.io.FileInputStream

fun main() {
    val strategy = File("./input/input.txt").inputStream()
    println("Part 1 solution")
    part1(strategy)
    println("Part 2 solution")
    //part2(strategy)
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

fun part1(fileStream: FileInputStream) {
    val strategy = fileStream
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
        println("$opponent $me")
        val opponentAction = opponentActionToPoints[opponent]
        val myAction = myActionToPoints[me]
        var roundScore = 0
        roundScore += if( myAction!!.defeats == opponentAction!!.name ) { // win
            6
        } else if ( opponentAction.defeats == myAction.name ) { // lose
            0
        } else { // draw
            3
        }
        roundScore += myAction.score
        totalScore += roundScore
    }
    println("Total score: $totalScore")
}

fun part2(fileStream: FileInputStream) {
    val strategy = fileStream
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

    }
    println("Total score: $totalScore")
}
