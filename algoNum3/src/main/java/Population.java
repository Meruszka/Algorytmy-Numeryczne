public class Population {
    static final char sub0='\u2080';
    static final char sub1='\u2081';
    static final char sub2='\u2082';
    static final char sub3='\u2083';
    static final char sub4='\u2084';
    static final char sub5='\u2085';
    static final char sub6='\u2086';
    static final char sub7='\u2087';
    static final char sub8='\u2088';
    static final char sub9='\u2089';

    public static char[] subs = {sub0, sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9};


    private int N;
    private double matrix[][];
    private int sum;

    public Population(int n) {
        super();
        N = n;

        //number of P's
        int s = ((N+2)*(N+1))/2;
        sum = s;

        matrix = new double[s][s];
    }

    public void calculateP() {
        int row = 0;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N-i; j++) {
                calculateP(row,i,j);
                row++;
            }
        }
    }

    public void calculateP(int row, int y1, int n1) {
        double a1 = 0;
        double a2 = 0;
        double a3 = 0;
        double a4 = 0;

        double u = N-y1-n1; // Ilość głosów na nie wiem

        //calculate P
        if (((double) y1 >0) && ((double) n1 >0)) {
            a1=-2*((double) y1 /N)*((double) n1 /(N-1));
            putP(row, y1-1, n1-1, a1);
        }
        if (y1<N) {
            a4=-2*((double) y1 /N)*(u/(N-1));
            putP(row, y1+1, n1, a4);
        }

        if (n1<N) {
            a3=-2*((double) n1 /N)*(u/(N-1));
            putP(row, y1, n1+1, a3);
        }

        a2=1-((double) y1 * (double) y1 - (double) y1)/(N*N-N)-((double) n1 * (double) n1 - (double) n1)/(N*N-N)-(u*u-u)/(N*N-N);
        if ((a2 == 0) && ((y1==0) || (y1>=N)))
            a2 = 1;
        putP(row, y1, n1, a2);
    }

    public void putP(int row, int y, int n, double val) {
        //int col = y*N+n;
        int d = ((2+N-y)*(N+1-y))/2;
        int col = sum-d+n;


        if ((col>=0) && (row>=0)) {
            if ((row< matrix.length) && (col<matrix[row].length)) {
                matrix[row][col] = val;
            }
        }
    }

    public int getN() {
        return N;
    }

    public double[][] getMatrix() {
        return matrix;
    }

    public void printMatrix() {
        printMatrix(matrix);
    }

    public static void printMatrix(double [][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.format("%+1.3f\t", matrix[i][j]);
            }
            System.out.println();
        }
    }

    public static String indexedStr(String text, int i, int j) {
        return text+subs[i]+','+subs[j];
    }

}
