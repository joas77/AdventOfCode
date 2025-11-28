import kotlin.math.abs
import kotlin.math.max

class Rope {

    val positionHead = Position(0,0)
    val positionTail = Position(0,0)

    private fun isTouching(): Boolean {
        return chebyshevDistance(positionHead, positionTail) <= 1
    }

    fun motion(direction:String, steps:Int){
        when(direction){
            "U"->up(steps)
            "D"->down(steps)
            "L"->left(steps)
            "R"->right(steps)
            else->println("instruction not recognized")
        }
    }

    fun up(steps:Int){
        repeat(steps) {
            positionHead.y++
            if(!isTouching()){
                // different row
                if(positionHead.y != positionTail.y){
                    // move diagonally
                }else{

                }
            }
        }
    }
    fun down(steps:Int){
        repeat(steps) {
            positionHead.y--
        }
    }

    fun left(steps:Int){
        repeat(steps){
            positionHead.x--
        }
    }

    fun right(steps: Int){
        repeat(steps){
            positionHead.x++
        }
    }

    fun printPosition() {
        if(positionHead.x>0)
            print(".".repeat(positionHead.x - 1))
        println("H")
        repeat(positionHead.y-1){
            println(".".repeat(positionHead.x))
        }
    }
}

data class Position(var x:Int, var y:Int)

private fun chebyshevDistance(a:Position, b:Position):Int{
    return max(abs(b.x - a.x), abs(b.y - a.y))
}