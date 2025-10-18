import java.io.File
typealias DirEntry = Pair<String, Int>
fun main() {
    val input =  File("input/input.txt").readLines()

    val fs = Filesystem()

    for(l in input) {
        if(isCmdPrompt(l)){
            val parts = l.split(" ")
            when(parts[1]){
                "cd" -> fs.cd(parts[2])
                "ls" -> continue // do nothing
            }
        }else{
            val parts = l.split(" ")
            if(parts[0] == "dir"){
                fs.mkdir(parts[1])
            }else {
                fs.addFile(parts[1], parts[0].toInt())
            }
        }
    }

    fs.print()
    val dirSizes = mutableListOf<DirEntry>()

    printSeparator()
    sumDirs(fs.root, 0, dirSizes)
    dirSizes.sortBy { it.second }
    println(dirSizes)
    println("Solution to part 1:")

    println("Sum of dirs less than 100k: ${dirSizes.sumOf { if (it.second < 100_000) it.second else 0 }}")
    printSeparator()

    val totalDiskSpace = 70_000_000
    val neededSpace = 30_000_000

    val availableSpace = totalDiskSpace - fs.totalDiskUsage
    val needToFree = neededSpace - availableSpace

    println("Available space: $availableSpace")
    println("Need to free up at least $needToFree")
    println("Solution to part 2:")
    dirSizes.find { it.second >= needToFree }?.let {
        println("Delete dir ${it.first} of size ${it.second}")
    }
    printSeparator()
}

fun printSeparator() {
    println("=".repeat(80))
}

fun isCmdPrompt(line: String): Boolean {
    return line.startsWith("$ ")
}

fun sumDirs(node: Node, size:Int=0, dirList: MutableList<DirEntry>):Int {
    var dirSize = 0
    for (child in node.children) {
        dirSize += sumDirs(child, child.size, dirList)
    }

    if (node.isDir()) {
        println("Dir ${node.name} size $dirSize")
        dirList.add(DirEntry(node.name, dirSize))
    }
    return dirSize + size
}