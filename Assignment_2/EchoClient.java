/* Filename: EchoClient.java
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 14th, 2019 8:30 PM
 * Program Title: Assignment 2 Question 1 - EchoClient
 * Program Description: The client portion of the Echo program written in java. The client sends input from the user to the socket and prints out the server's response
 */

import java.io.*;
import java.net.*;
import java.util.*;

public class EchoClient {
  public static void main(String[] args) {
    // Check if the arguments are correct, else print usage statement
    if (args.length != 1) {
      System.out.println("Usage: java EchoClient <hostname>");
      System.exit(1);
    }

    // Try with socket resources open a new socket to server
    try (
      Socket Sock = new Socket(args[0], 6013);
      PrintWriter out = new PrintWriter(Sock.getOutputStream(), true);
      InputStream in = Sock.getInputStream();
      BufferedReader bin = new BufferedReader(new InputStreamReader(in));
      BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))
    ) {
      String line;

      // While input in not null and escape character not entered send input to server
      while ((line = stdIn.readLine()) != null) {
        out.println(line);
        if (line.charAt(0) == '.'){
          Sock.close();
          System.exit(0);
        }
        System.out.println("Server: " + bin.readLine());
      }

    // Catch Socket IO errors
    } catch (IOException ioe) {
        System.err.println(ioe);
    }
  }
}
