import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Locale;


public class csvWriter {
    public void toCSV(int n, double sum, long time, String filename){
        try (PrintWriter writer = new PrintWriter(new FileOutputStream(filename + ".csv", true))) {
            StringBuilder sb = new StringBuilder();
            // Headers
//            sb.append("n");
//            sb.append(",");
//            for(int i = 0; i < vector.rows-1; i++){
//                sb.append(i);
//                sb.append(',');
//            }
//            sb.append(vector.rows-1);
//            sb.append('\n');
            // Data
            sb.append(n);
            sb.append(",");
            sb.append(String.format(Locale.US, "%.16f", sum));
            sb.append(",");
            sb.append(time);
            sb.append('\n');
            writer.write(sb.toString());
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
