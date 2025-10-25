
class HeightMap(droneData: List<String>) {
    val data: MutableList<MutableList<Int>> = mutableListOf()

    init{
        droneData.forEach {
            val row: MutableList<Int> = mutableListOf()
            it.forEach{ c -> row.add(c.digitToInt()) }
            data.add(row)
        }
    }

    fun visibleMap():Matrix<Boolean>{
        return data.mapIndexed { indexRow, row ->
            row.mapIndexed { indexCol, h ->

                // if tree is in the edge row or column it's visible
                if(isPositionAtEdge(indexCol, indexRow,row.size, data.size))
                    return@mapIndexed true

                val rowTrees = getRow(data, indexRow)
                val colTrees = getColumn(data, indexCol)

                val treesRightSide = rowTrees.subList(indexCol+1, row.size)
                val treesLeftSide = rowTrees.subList(0,indexCol)

                val treesUpSide = colTrees.subList(0,indexRow)
                val treesDownSide = colTrees.subList(indexRow+1, data.size)

                treesUpSide.all{it < h} ||
                treesLeftSide.all{it < h} || treesRightSide.all{it < h} ||
                        treesDownSide.all { it < h }
            }
        }
    }

    fun sceneScoreMap():Matrix<Int>{
        return data.mapIndexed { indexRow, row ->
            row.mapIndexed { indexCol, h ->

                // if tree is in the edge row or column it's visible
                if(isPositionAtEdge(indexCol, indexRow,row.size, data.size))
                    return@mapIndexed 0

                val rowTrees = getRow(data, indexRow)
                val colTrees = getColumn(data, indexCol)

                val treesRightSide = rowTrees.subList(indexCol+1, row.size)
                val treesLeftSide = rowTrees.subList(0,indexCol)

                val treesUpSide = colTrees.subList(0,indexRow)
                val treesDownSide = colTrees.subList(indexRow+1, data.size)

                0
            }
        }
    }
}


fun isPositionAtEdge(c:Int, r:Int, rowSize:Int, colSize:Int): Boolean{
    return (r - 1 < 0) ||  (r + 1 >= colSize) || (c + 1 >= rowSize) || (c - 1 < 0)
}