import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class subtask4{

    public static int readNumberFromFile(String filename) throws IOException {
        Scanner fileScanner = new Scanner(new File(filename));
        int num = fileScanner.nextInt();
        fileScanner.close();
        return num;
    }

    public static void writePatternToFile(String filename, String pattern) throws IOException {
        FileWriter writer = new FileWriter(filename);
        writer.write(pattern);
        writer.close();
    }

    public static String generatePattern(int n) {
        String pattern = "";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                pattern += " ";
            }
            for (int k = 0; k < 2 * i + 1; k++) {
                pattern += "*";
            }
            pattern += "\n";
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n - i - 1; j++) {
                pattern += " ";
            }
            for (int k = 0; k < 2 * i + 1; k++) {
                pattern += "*";
            }
            pattern += "\n";
        }

        return pattern;
    }

    public static void main(String[] args) throws IOException {
        int n = readNumberFromFile("input.txt");
        String pattern = generatePattern(n);
        writePatternToFile("output.txt", pattern);
    }
}
