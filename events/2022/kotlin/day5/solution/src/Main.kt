import java.io.File

fun main() {
    val input = File("input/input.txt").readLines()
    solution(input){ stackCount, src, dest, stacks ->
        repeat(stackCount) {
            move(src, dest, stacks)
        }
    }
    println("=====================")
    println("part2 solution")
    solution(input){stackCount, src, dest, stacks ->
        val tempStack : StackCrate = mutableListOf()
        repeat(stackCount){
            tempStack.add(stacks[src-1].removeLast())
        }

        repeat(stackCount){
            stacks[dest-1].add(tempStack.removeLast())
        }
    }
}

fun processInput(lines: List<String>): Pair<MutableList<String>, MutableList<String>> {
    val stackArrangement : MutableList<String>  = mutableListOf()
    val instructions : MutableList<String> = mutableListOf()
    var readingInstructions = false
    for(l in lines) {
        if(l == "") {
            readingInstructions = true
            continue
        }

        if(!readingInstructions) {
            stackArrangement.add(l)
        } else {
            instructions.add(l)
        }
    }

    return Pair(stackArrangement, instructions)
}

typealias StackCrate = MutableList<Char>
typealias StacksOfCrates = MutableList<StackCrate>

fun createStacks(arrangement: List<String>): StacksOfCrates {
    val numberOfStacks = arrangement.last().trim().split(" ").last().toInt()
    val stacks: StacksOfCrates = MutableList(numberOfStacks){
        mutableListOf()
    }

    for(l in arrangement.reversed()) {
        val r = Regex("\\[[A-Z]\\]|\\s{4}")

        r.findAll(l)
        .forEachIndexed { index , matchResult ->
            val crate = matchResult.value.trim()
            // println("Found crate: $crate")
            if(crate.isNotEmpty()) {
                stacks[index].add(crate[1])
            }
        }

    }
    return stacks
}

fun solution(lines: List<String>, craneMover: (Int, Int, Int, StacksOfCrates) -> Unit) {
    val(stackArrangement, instructions) = processInput(lines)
    //stackArrangement.forEach { println(it) }
    val stacks = createStacks(stackArrangement)
    println(stacks)
    craneOperation(stacks, instructions, craneMover)

    println(stacks)
    println("Top crates: ${topCrates(stacks)}")
}

fun craneOperation(stacks: StacksOfCrates,
                   instructions: List<String>,
                   craneMover: (Int, Int, Int, StacksOfCrates) -> Unit) {

    for(ins in instructions) {
        val(stackCount, src, dest) = Regex("\\d+").findAll(ins).map { it.value.toInt() }.toList()
        // println("${stackCount}, ${src}, ${dest}")
        craneMover(stackCount, src, dest, stacks)

    }
}

fun move(from: Int, to: Int, stacks: StacksOfCrates) {
    val moved = stacks[from-1].removeLast()
    stacks[to-1].add(moved)
}

fun topCrates(stacks: StacksOfCrates): String {
    return stacks.map { it.lastOrNull() ?: ' ' }.joinToString("")
}
