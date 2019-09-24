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

  }
  catch (IOException ioe) {
  System.err.println(ioe);
  }
  }

}
