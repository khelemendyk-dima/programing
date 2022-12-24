public class Graph {
    public int[][] mas;
    Vertex[] vertexList;
    private final MyStack stack;
    private final MyQueue queue;
    private int currN;

    public Graph() {
        int MAX_SIZE = 10;
        vertexList = new Vertex[MAX_SIZE];
        mas = new int[MAX_SIZE][MAX_SIZE];
        stack = new MyStack();
        queue = new MyQueue();
        currN = 0;
    }

    public void addVertex(char name) {
        vertexList[currN++] = new Vertex(name);
    }

    public void addEdge(int start, int end, int val) {
        mas[start][end] = 1;
        mas[end][start] = val;
    }

    public int check(int vertex) {
        for (int i = 0; i < currN; i++) {
            if (mas[vertex][i] == 1 && !vertexList[i].isVisited) {
                return i;
            }
        }

        return -1;
    }

    public void passInDepth(int index) {
        System.out.println(vertexList[index].name);
        vertexList[index].isVisited = true;
        stack.push(index);

        while (!stack.isEmpty()) {
            int neighbor = check(stack.peek());

            if (neighbor == -1) {
                neighbor = stack.pop();
            } else {
                System.out.println(vertexList[neighbor].name);
                vertexList[neighbor].isVisited = true;
                stack.push(neighbor);
            }
        }

        for (int i = 0; i < currN; i++) {
            vertexList[i].isVisited = false;
        }
    }

    public void passInWidth(int index) {
        System.out.println(vertexList[index].name);
        vertexList[index].isVisited = true;
        queue.insert(index);

        int vertex;

        while (!queue.isEmpty()) {
            int temp = queue.remove();

            while ((vertex = check(temp)) != -1) {
                System.out.println(vertexList[vertex].name);
                vertexList[vertex].isVisited = true;
                queue.insert(vertex);
            }
        }

        for (int i = 0; i < currN; i++) {
            vertexList[i].isVisited = false;
        }
    }
}
