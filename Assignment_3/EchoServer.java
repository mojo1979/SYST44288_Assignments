/* Filename: EchoServer.java
 * Name(s): Daniel Nawrocki, John Mo
 * Created: October 8th, 2019 5:30 PM
 * Program Title: Assignment 3 Question 2 - EchoServer
 * Program Description: A multithreaded Echo Server that replies to multiple clients
 */

 // Import Java Packages & Libraries
import java.io.*;
import java.net.*;
import java.util.*;

public class EchoServer {
  public static void main(String args[]) throws Exception {
    // Create a new server socket
    ServerSocket client = new ServerSocket(6013);
    while (true) {
      //Accept client connections
      Socket sock = client.accept();
      // Create and start a new thread for client connection
      new Thread(new serverThread(sock)).start();
    }
  }
}

class serverThread implements Runnable {
  //Specific socket for client connection
  private Socket threadSock;

  public serverThread(Socket sock) {
    // Get socket from constructor init
    threadSock = sock;
  }

  public void run() {
    // Try reading from the socket and reply to the socket connection
    try (
      PrintStream out = new PrintStream(threadSock.getOutputStream());
      InputStream inStream = threadSock.getInputStream();
      BufferedReader in = new BufferedReader(new InputStreamReader(inStream))
    ){
      String input;
      while(true) {
        input = in.readLine();
        out.println(input);
      }
      // Catch IO exceptions and print them to console
    } catch (IOException e) {
      System.out.println(e);
    }
  }
}
