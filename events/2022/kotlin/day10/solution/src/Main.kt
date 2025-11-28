import java.io.File
fun main() {
    val input = File("input/input.txt").readLines()
    val cpu = Cpu()
    val cycles = setOf(
        20,
        60,
        100,
        140,
        180,
        218,
        219,
        220
    )
    cpu.addBreaksAtCycles(cycles)
    input.forEachIndexed { i, instruction->
        //println(instruction)
        cpu.executeInstruction(instruction)
    }

    println(cpu.signalStrengthSum)

}