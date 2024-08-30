import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class subtask2 {

    public static String subtask2() throws IOException {
        File inputFile = new File("input.txt");
        Scanner fileReader = new Scanner(inputFile);
        StringBuilder content = new StringBuilder();
        
        while (fileReader.hasNextLine()) {
            content.append(fileReader.nextLine()).append("\n");
        }
        fileReader.close();
        
        FileWriter fileWriter = new FileWriter("output.txt");
        fileWriter.write(content.toString());
        fileWriter.close();
        
        File outputFile = new File("output.txt");
        fileReader = new Scanner(outputFile);
        StringBuilder finalContent = new StringBuilder();
        
        while (fileReader.hasNextLine()) {
            finalContent.append(fileReader.nextLine()).append("\n");
        }
        fileReader.close();
        
        return finalContent.toString().trim();
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Content of the file: \n");
            String inputContent = scanner.nextLine();
            
            FileWriter inputFileWriter = new FileWriter("input.txt");
            inputFileWriter.write(inputContent);
            inputFileWriter.close();
            
            System.out.println("printing output.txt...");
            String result = subtask2();
            System.out.println(result);
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}
