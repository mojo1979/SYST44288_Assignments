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
    try {
      /* make connection to server socket */
      Socket socket = new Socket("127.0.0.1",6013);
      InputStream input = socket.getInputStream();
      BufferedReader bin = new
      BufferedReader(new InputStreamReader(input));
      /* read the date from the socket */
      String line;
      while ( (line = bin.readLine()) != null)
      System.out.println(line);
     /* close the socket connection*/
      socket.close();
    }
    catch (IOException ioe) {
      System.err.println(ioe);
    }
  }
}
