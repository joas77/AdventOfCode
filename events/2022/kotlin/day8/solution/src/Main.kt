import java.io.File

fun main() {
    val input = File("input/input.txt").readLines()
    val heightMap = HeightMap(input)

    println("=".repeat(80))
    val visibleTreesCount = heightMap.visibleMap().sumOf{ row -> row.count { it } }
    println("Solution par 1 visible trees = $visibleTreesCount")
    println("=".repeat(80))

    //printMatrix(heightMap.data)
    //printMatrix(heightMap.visibleMap())
}



