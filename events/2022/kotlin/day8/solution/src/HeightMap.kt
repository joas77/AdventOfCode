
class HeightMap(droneData: List<String>) {
    val data: MutableList<MutableList<Int>> = mutableListOf()

    init{
        droneData.forEach {
            val row: MutableList<Int> = mutableListOf()
            it.forEach{ c -> row.add(c.digitToInt()) }
            data.add(row)
        }
    }

    private fun get4SidesTrees(data:Matrix<Int>, indexRow:Int, indexCol:Int):Matrix<Int>{
        val rowTrees = getRow(data, indexRow)
        val colTrees = getColumn(data, indexCol)

        val treesRightSide = rowTrees.subList(indexCol+1, rowTrees.size)
        val treesLeftSide = rowTrees.subList(0,indexCol)

        val treesUpSide = colTrees.subList(0,indexRow)
        val treesDownSide = colTrees.subList(indexRow+1, data.size)

        return listOf(treesUpSide, treesDownSide, treesLeftSide, treesRightSide)
    }

    fun visibleMap():Matrix<Boolean>{
        return data.mapIndexed { indexRow, row ->
            row.mapIndexed { indexCol, h ->

                // if tree is in the edge row or column it's visible
                if(isPositionAtEdge(indexCol, indexRow,row.size, data.size))
                    return@mapIndexed true

                val allSideTrees = get4SidesTrees(data, indexRow, indexCol)
                val treesUpSide = allSideTrees[0]
                val treesDownSide = allSideTrees[1]
                val treesLeftSide = allSideTrees[2]
                val treesRightSide = allSideTrees[3]

                treesUpSide.all{it < h} ||
                treesLeftSide.all{it < h} || treesRightSide.all{it < h} ||
                        treesDownSide.all { it < h }
            }
        }
    }

    private fun viewScore(trees:List<Int>, h:Int):Int{
        var viewTreesCount = 0
        for(t in trees){
            if(t < h) {
                viewTreesCount++
            }else{
                viewTreesCount++
                break
            }
        }
        return viewTreesCount
    }

    fun sceneScoreMap():Matrix<Int>{
        return data.mapIndexed { indexRow, row ->
            row.mapIndexed { indexCol, h ->

                // if tree is in the edge row or column it's visible
                if(isPositionAtEdge(indexCol, indexRow,row.size, data.size))
                    return@mapIndexed 0

                val allSideTrees = get4SidesTrees(data, indexRow, indexCol)
                val treesUpSide = allSideTrees[0]
                val treesDownSide = allSideTrees[1]
                val treesLeftSide = allSideTrees[2]
                val treesRightSide = allSideTrees[3]

                val upViewScore = viewScore(treesUpSide.reversed(), h)
                val downViewScore = viewScore(treesDownSide, h)
                val leftViewScore = viewScore(treesLeftSide.reversed(), h)
                val rightViewScore = viewScore(treesRightSide, h)

                upViewScore * downViewScore * leftViewScore * rightViewScore
            }
        }
    }
}


fun isPositionAtEdge(c:Int, r:Int, rowSize:Int, colSize:Int): Boolean{
    return (r - 1 < 0) ||  (r + 1 >= colSize) || (c + 1 >= rowSize) || (c - 1 < 0)
}