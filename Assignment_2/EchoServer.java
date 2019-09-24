/* Filename: EchoServer.java
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 14th, 2019 8:30 PM
 * Program Title: Assignment 2 Question 1 - EchoServer
 * Program Description:
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class EchoServer {
  // Global Variables
  public static void main(String[] args) {
try{
    ServerSocket socket = new ServerSocket(6013);

    while (true) {
        Socket clientserver = socket.accept();
        PrintWriter printout = new PrintWriter(clientserver.getOutputStream(), true);
        printout.println(new java.util.Date().toString());
        clientserver.close();
      }
}


  catch (IOException ioe) {
System.err.println(ioe);
  }
}
}
