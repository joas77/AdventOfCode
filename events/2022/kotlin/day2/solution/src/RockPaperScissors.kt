class RockPaperScissors(var name: String) {
    var defeats: String = ""
    var score: Int = 0
    init {
        when (name) {
            "rock" -> {
                defeats = "scissors"
                score = 1
            }
            "paper" -> {
                defeats = "rock"
                score = 2
            }
            "scissors" -> {
                defeats = "paper"
                score = 3
            }
            else -> {
                throw IllegalArgumentException("Invalid action: $name")
            }
        }
    }
}