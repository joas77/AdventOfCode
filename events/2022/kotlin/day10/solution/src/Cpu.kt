class Cpu {
    private var registerX = 1
    private var cycleCount = 0
    private var breakCycles : MutableSet<Int> = mutableSetOf()
    private var _signalStrengthSum=0
    val signalStrengthSum
        get() = _signalStrengthSum


    fun executeInstruction(instruction:String){
        if(instruction=="noop")
            noop()
        else if(instruction.startsWith("addx")) {
            val x = instruction.split(" ")[1]
            addx(x.toInt())
        }

    }
    fun noop(){
        cycleCount ++
        debug()
    }

    fun addx(value: Int){
        cycleCount ++
        debug()
        cycleCount ++
        registerX += value
        debug()
    }

    fun signalStrength():Int{
        return cycleCount * registerX
    }

    fun addBreaksAtCycles(cycles:Set<Int>){
        breakCycles.addAll(cycles)
    }

    fun debug(){
        if(cycleCount in breakCycles){
            _signalStrengthSum += signalStrength()
            println("Cycle: $cycleCount, register X: $registerX, signal strength: ${signalStrength()}")
        }
    }


}