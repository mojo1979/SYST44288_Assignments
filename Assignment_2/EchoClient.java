/* Filename: EchoClient.java
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 14th, 2019 8:30 PM
 * Program Title: Assignment 2 Question 1 - EchoClient
 * Program Description:
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class EchoClient {
  // Global Variables
  public static void main(String[] args) {
    try (
        Socket Sock = new Socket(args[0], 6013);
        PrintWriter out = new PrintWriter(Sock.getOutputStream(), true);
        InputStream in = Sock.getInputStream();
        BufferedReader bin =new BufferedReader(new InputStreamReader(in));
        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))
    ) {
        String line;
        while ((line = stdIn.readLine()) != null) {
            out.println(line);
            if (line.charAt(0) == '.'){
              break;
            }
            System.out.println("Server: " + bin.readLine());
            }
        Sock.close();
    }  catch (IOException ioe) {
System.err.println(ioe);
}
}
}
