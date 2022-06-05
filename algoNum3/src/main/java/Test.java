import java.util.ArrayList;

public class Test {

    static int N = 150; // Wielkość początkowa

    public static void main(String[] args) {
        Population p = new Population(N);
        p.calculateP();
        MyMatrix monte = testMonteCarlo(p);

        long startTime = System.nanoTime();
        MyMatrix gauss = testCzesciowyGauss(p);
        long endTime = System.nanoTime();
        new csvWriter().toCSV(N, gauss.errorCal(monte), endTime-startTime,"Gauss");

        startTime = System.nanoTime();
        MyMatrix jacobs = testJacobs(p);
        endTime = System.nanoTime();
        new csvWriter().toCSV(N, jacobs.errorCal(monte), endTime-startTime,"Jacobs");

        startTime = System.nanoTime();
        MyMatrix seidel = testGaussSeidel(p);
        endTime = System.nanoTime();
        new csvWriter().toCSV(N, seidel.errorCal(monte), endTime-startTime,"GaussSeidel");
    }

    public static MyMatrix testMonteCarlo(Population p) {
        MyMatrix vector = new MyMatrix(p.getMatrix().length,1);
        ArrayList<Double> lista = new ArrayList<Double>();
        for(int y=0; y<=N; y++) {
            for(int n=0; n<=N-y; n++)
            {
                lista.add(MonteCarlo.prawdMonteCarlo(N, y, n, 100000));
            }
        }
        vector.wczytajDane(lista);
        return vector;
    }

    public static MyMatrix testCzesciowyGauss(Population p) {
        MyMatrix vector = new MyMatrix(p.getMatrix().length,1);
        vector.wypelnianieWynikami();
        MyMatrix matrix1 = new MyMatrix();
        matrix1.wczytajDane(p);

        return matrix1.czesciowyWybor(matrix1, vector);
    }

    public static MyMatrix testJacobs(Population p)
    {
        MyMatrix vector1 = new MyMatrix(p.getMatrix().length,1);
        vector1.wypelnianieWynikami();
        MyMatrix matrix2 = new MyMatrix(N);
        matrix2.wczytajDane(p);

        return matrix2.jacobs(matrix2, vector1);
    }

    public static MyMatrix testGaussSeidel(Population p)
    {
        MyMatrix vector2 = new MyMatrix(p.getMatrix().length,1);
        vector2.wypelnianieWynikami();
        MyMatrix matrix3 = new MyMatrix(N);
        matrix3.wczytajDane(p);
        return matrix3.gaussSeidel(matrix3, vector2);
    }
}
