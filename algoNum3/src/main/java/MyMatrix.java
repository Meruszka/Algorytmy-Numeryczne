import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MyMatrix {
    protected double[][] matrix;
    protected int rows;
    private int columns;

    public MyMatrix() {
        this.matrix = new double[0][0];
    }

    public MyMatrix(int length) {
        this(length, length);
    }

    public MyMatrix(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        this.matrix = new double[rows][columns];
    }


    public MyMatrix czesciowyWybor(MyMatrix matrix, MyMatrix vector)
    {

        int n = vector.rows;
        for (int p = 0; p < n; p++)
        {

            przemiescNajwiekszyWiersz(matrix, vector, n, p, p);
            for (int i = p + 1; i < n; i++) {
                tworzTrojkatMacierzy(matrix, vector, n, p, i);
            }
        }

        MyMatrix resultVector = new MyMatrix(vector.rows, 1);

        liczUkladyRownanOdTylu(matrix, vector, n, resultVector);
        return resultVector;
    }



    private void przemiescNajwiekszyWiersz(MyMatrix matrix, MyMatrix vector, int n, int p, int max)
    {
        for (int i = p + 1; i < n; i++)
        {
            if (Math.abs(matrix.matrix[i][p]) > Math.abs(matrix.matrix[max][p]))
            {
                max = i;
            }
        }
        zamienWiersze(matrix, p, max);
        zamienWiersze(vector, p, max);
    }

    private void tworzTrojkatMacierzy(MyMatrix matrix, MyMatrix vector, int n, int p, int i)
    {
        double alpha = matrix.matrix[i][p] / matrix.matrix[p][p];
        vector.matrix[i][0] = (vector.matrix[i][0] - alpha * vector.matrix[p][0]);
        for (int j = p; j < n; j++)
        {
            matrix.matrix[i][j] = (matrix.matrix[i][j] - alpha * matrix.matrix[p][j]);
        }
    }

    private void liczUkladyRownanOdTylu(MyMatrix matrix, MyMatrix vector, int n, MyMatrix resultVector)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            double sum = 0.0;
            for (int j = i + 1; j < n; j++)
            {
                sum += matrix.matrix[i][j] * resultVector.matrix[j][0];
            }
            resultVector.matrix[i][0] = ((vector.matrix[i][0] - sum) / matrix.matrix[i][i]);

        }
    }


    public void zamienWiersze(MyMatrix finalMatrix, int row1, int row2)
    {
        if (row1 == row2)
        {
            return;
        }
        for (int i = 0; i < finalMatrix.columns; i++)
        {
            double tmp = finalMatrix.matrix[row1][i];
            finalMatrix.matrix[row1][i] = finalMatrix.matrix[row2][i];
            finalMatrix.matrix[row2][i] = tmp;
        }
    }


    public MyMatrix jacobs(MyMatrix A, MyMatrix b) {
        int i = 0, j = 0, k=0;
        int num = rows;
        MyMatrix M = new MyMatrix(rows);
        MyMatrix N = new MyMatrix(rows);
        MyMatrix x1 = new MyMatrix(rows, 1);
        MyMatrix x2 = new MyMatrix(rows, 1);


        //N = D^-1
        for (i=0; i<num; i++)
            N.matrix[i][0] = 1/A.matrix[i][i];

        //M = -D^-1 (L + U)
        for (i=0; i<num; i++)
            for (j=0; j<num; j++)
                if (i == j)
                    M.matrix[i][j] = 0;
                else
                    M.matrix[i][j] = -1*(A.matrix[i][j] * N.matrix[i][0]);

        //x
        for (i=0; i<num; i++)
            x1.matrix[i][0] = 0;

        int iter = 100;

        for (k=0; k<iter; k++) {
            for (i=0; i<num; i++) {
                x2.matrix[i][0] = N.matrix[i][0]*b.matrix[i][0];
                for (j=0; j<num; j++)
                    x2.matrix[i][0] += M.matrix[i][j]*x1.matrix[j][0];
            }
            for (i=0; i<num; i++)
                x1.matrix[i][0] = x2.matrix[i][0];
        }

        return x1;
    }

    public MyMatrix gaussSeidel(MyMatrix A, MyMatrix b)
    {

        int i = 0, j = 0, k=0;
        int num = rows;
        MyMatrix U = new MyMatrix(rows);
        MyMatrix L = new MyMatrix(rows);
        MyMatrix D = new MyMatrix(rows);
        MyMatrix x = new MyMatrix(rows, 1);

        // Divide A into L + D + U
        for (i=0; i<num; i++)
            for (j=0; j<num; j++) {
                if (i < j) {
                    U.matrix[i][j] = A.matrix[i][j];
                }
                else if (i > j) {
                    L.matrix[i][j] = A.matrix[i][j];
                }
                else {
                    D.matrix[i][j] = A.matrix[i][j];
                }
            }

        //D^-1
        for (i=0; i<num; i++)
            D.matrix[i][i] = 1/D.matrix[i][i];

        //D^-1 * b
        for (i=0; i<num; i++)
            b.matrix[i][0] *= D.matrix[i][i];

        //D^-1 * L
        for (i=0; i<num; i++)
            for (j=0; j<i; j++)
                L.matrix[i][j] *= D.matrix[i][i];

        //D^-1 * U
        for (i=0; i<num; i++)
            for (j=i+1; j<num; j++)
                U.matrix[i][j] *= D.matrix[i][i];

        //Initialize x
        for (i=0; i<num; i++)
            x.matrix[i][0] = 0;

        int iter=100;

        for (k=0; k<iter; k++)
            for (i=0; i<num; i++) {
                x.matrix[i][0] = b.matrix[i][0];                    // x = D^-1*b -
                for (j=0; j<i; j++)
                    x.matrix[i][0] -= L.matrix[i][j]*x.matrix[j][0];    // D^-1*L * x -
                for (j=i+1; j<num; j++)
                    x.matrix[i][0] -= U.matrix[i][j]*x.matrix[j][0];    // D^-1*U * x
            }

        return x;
    }

    public void wypelnianieWynikami()
    {
        int val=0;
        for (int i = 0; i < rows-1; i++)
        {
            val++;
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] =  0.0d;

            }
        }
        matrix[val][0]= 1.0d;

    }

    public void wczytajDane(Population p)
    {
        rows = p.getMatrix().length;
        columns =p.getMatrix()[0].length;
        matrix = new double[rows][columns];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = p.getMatrix()[i][j];
            }
        }
    }

    public void wczytajDane(ArrayList<Double> p)
    {
        matrix = new double[p.size()][1];
        for (int i = 0; i < p.size(); i++)
        {
            matrix[i][0] = p.get(i);
        }
    }

    public double errorCal(MyMatrix monte){
        double sum = 0;
        for(int i=0; i<this.rows; i++){
            sum += Math.abs(this.matrix[i][0] - monte.matrix[i][0]);
        }
        return sum/this.rows;
    }
}