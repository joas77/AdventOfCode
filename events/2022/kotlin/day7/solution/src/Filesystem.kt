class Filesystem {
    var root : Node = DirNode("/")
    var current = root
    var totalDiskUsage = 0

    fun addFile(name: String, size: Int) {
        current.addChild(FileNode(name, size))
        totalDiskUsage+=size
    }

    fun mkdir(name: String) {
        current.addChild(DirNode(name))
    }

    private fun print(node: Node, depth: Int = 0) {
        println("  ".repeat(depth) + "- ${node.name} (${if(node.isDir()) "dir" else "file, size=${node.size}"})")
        for(child in node.children) {
            print(child, depth + 1)
        }
    }

    fun traverse(node:Node=root, depth:Int=0, action: (Node, depth: Int) -> Int) {
        action(node, depth)
        for(child in node.children) {
            traverse(child, depth+1, action)
        }
    }

    fun print() {
        traverse(root) { node, depth ->
            println("    ".repeat(depth) + "- ${node.name} (${if(node.isDir()) "dir" else "file, size=${node.size}"})")
            0
        }
    }

    fun cd(name: String) {
        current = if(name == "..") {
            current.parent ?: current
        } else {
            current.children.find { it.name == name } ?: current
        }
    }
}

open class Node(var name: String){
    var size = 0
    var parent: Node? = null
    var children: MutableList<Node> = mutableListOf()

    fun addChild(child: Node){
        child.parent = this
        children.add(child)
    }

    fun isDir(): Boolean {
        return this is DirNode
    }
}

class FileNode(name: String, size: Int): Node(name){
    init {
        this.size = size
    }
}

class DirNode(name: String): Node(name){
    init {
        this.size = 0
    }
}