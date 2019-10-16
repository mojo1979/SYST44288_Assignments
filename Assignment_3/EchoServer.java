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
   public static void main(String[] args) throws Exception {

     // Try with server socket resources to open a echo server
     try (
       ServerSocket sock =  new ServerSocket(6013);
       Socket client = sock.accept();

     ) {


     }
   }

   public void run(){
     try{
     PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
     InputStream inp = socket.getInputStream();
     BufferedReader in = new BufferedReader(new InputStreamReader(inp));
     String input;

     // Repeat whatever was sent to the server back out to the socket
     while(true){
        input = in.readLine();
        out.println(input);
     }
   }catch (IOException e) {
        System.out.println(e);
     }

   }
 }
