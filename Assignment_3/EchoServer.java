/* Filename: EchoServer.java
 * Name(s): Daniel Nawrocki, John Mo
 * Created: October 8th, 2019 5:30 PM
 * Program Title: Assignment 3 Question 2 - EchoServer
 * Program Description:
 */
import java.io.*;
import java.net.*;
import java.util.*;
public class EchoServer implements Runnable {
   Socket socket;
   EchoServer(Socket csocket) {
      this.socket = socket;
   }
   public static void main(String args[]) throws Exception {
      ServerSocket client = new ServerSocket(6013);

      while (true) {
         Socket sock = client.accept();
         new Thread(new threads(sock)).start();
      }
   }
   public void run() {
      try {
         PrintStream out = new PrintStream(socket.getOutputStream());
         InputStream inp = socket.getInputStream();
         BufferedReader in = new BufferedReader(new InputStreamReader(inp));
         String input;
         while(true) {
           input = in.readLine();
           out.println(input);
         }
        // pstream.close();
        // csocket.close();
      } catch (IOException e) {
         System.out.println(e);
      }
   }
}
