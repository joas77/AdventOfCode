import java.io.File

fun main() {
    val input = File("input/input.txt").readLines()
    val rope = Rope()
    println("Start: ${rope.positionHead}")
    for(l in input){
        val motions = l.trim().split(Regex("\\s+"))
        val direction = motions[0]
        val steps = motions[1].toInt()

        rope.motion(direction, steps)
        print("Going $direction, $steps steps: ")
        println(rope.positionHead)
        //rope.printPosition()
    }
}