typealias Matrix<T> = List<List<T>>

fun<T> printMatrix(matrix: Matrix<T>){
    for (row in matrix) {
        for (e in row) {
            print("$e ")
        }
        println()
    }
}

fun<T> getRow(matrix: Matrix<T>, index:Int):List<T>{
    return matrix[index]
}

fun<T> getColumn(matrix: Matrix<T>, indexCol:Int):List<T> {
    return  matrix.map { row -> row[indexCol] }
}