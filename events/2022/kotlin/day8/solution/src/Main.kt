import java.io.File

fun main() {
    val input = File("input/input.txt").readLines()
    val heightMap = HeightMap(input)

    printSeparation()
    val visibleTreesCount = heightMap.visibleMap().sumOf{ row -> row.count { it } }
    println("Solution part 1, visible trees = $visibleTreesCount")
    printSeparation()

    printMatrix(heightMap.data)
    printSeparation()
    //printMatrix(heightMap.visibleMap())
    //printMatrix(heightMap.sceneScoreMap())
    println("solution part 2,  highest scenic score possible for any tree: ${heightMap.sceneScoreMap().maxOf{it.max()}}")
}

fun printSeparation(){
    println("=".repeat(80))
}



