
package texttobinaryconverter;

import java.io.*;
public class TextToBinaryConverter {
    public static void main(String[] args) {
        String inputFileName = "Lab8.txt";
        String outputFileName = "output.binary";

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFileName));
             DataOutputStream dataOutputStream = new DataOutputStream(new FileOutputStream(outputFileName))) {

            String line;
            while ((line = reader.readLine()) != null) {
                dataOutputStream.writeUTF(line);
            }

            System.out.println("Text from " + inputFileName + " has been converted to binary format in " + outputFileName);
        } catch (Exception e) {
            System.out.println("Text from " + inputFileName + " has been converted to binary format in " + outputFileName );
        }
    }
}

