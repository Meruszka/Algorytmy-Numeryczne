



public class MonteCarlo {

    public static double prawdMonteCarlo(int len, int y, int n, long ilosc)
    {
        VotesMatrix matrix = new VotesMatrix(len, y, n);
        int max_kroki = 100;
        int kroki;
        int powtorzeniaTAK=0;


        for(long j = 0; j< ilosc; j++)
        {
            kroki = 0;
            VotesMatrix matrix1 = (VotesMatrix)matrix.clone();
            for(int i = 0; i<max_kroki; i++)
            {
                matrix1.algorytmGlosowania();
                kroki++;
                if (matrix1.czyMacierzJednolita())
                    break;
            }

            if(matrix1.czyMacierzJednolita() && matrix1.getElem(0)== VotesMatrix.Vote.Yes)
            {
                powtorzeniaTAK++;
                //System.out.println("TAK");
            }
            else if(matrix1.czyMacierzJednolita()&& matrix1.getElem(0)== VotesMatrix.Vote.No)
            {
                //System.out.println("NIE");
            }
            else if(matrix1.czyMacierzJednolita()&& matrix1.getElem(0)== VotesMatrix.Vote.Undecided)
            {
                //System.out.println("UND");
            }
            if (j==1000000)
                System.out.println(" 10^6");
            else if (j==10000000)
                System.out.println(" 10^7");
            else if (j==100000000)
                System.out.println(" 10^8");
            else if (j==10000000000L)
                System.out.println(" 10^10");

        }
        return (1.0d*powtorzeniaTAK)/ ilosc;
    }
}
