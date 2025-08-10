class RockPaperScissors(var name: String) {
    var defeats: String = ""
    var defeatedBy: String = ""
    var score: Int = 0
    init {
        when (name) {
            "rock" -> {
                defeats = "scissors"
                defeatedBy = "paper"
                score = 1
            }
            "paper" -> {
                defeats = "rock"
                defeatedBy = "scissors"
                score = 2
            }
            "scissors" -> {
                defeats = "paper"
                defeatedBy = "rock"
                score = 3
            }
            else -> {
                throw IllegalArgumentException("Invalid action: $name")
            }
        }
    }
}