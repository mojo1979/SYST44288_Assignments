/* Filename: EchoClient.java
 * Name(s): Daniel Nawrocki, John Mo
 * Created: October 8th, 2019 5:30 PM
 * Program Title: Assignment 3 Question 2 - EchoClient
 * Program Description: An Echo Client that connects to a multithreaded Echo Server
 */

 // Import Java Packages & Libraries
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
         // Prevent Ssending empty new lines
         if (line.length() != 0) {
           out.println(line);

           // Check for escape character '.'
           if (line.charAt(0) == '.'){
             Sock.close();
             System.exit(0);
           }

           //Print reply from server
           System.out.println("Server: " + bin.readLine());
         }
       }

     // Catch Socket IO errors
     } catch (IOException ioe) {
       System.err.println(ioe);
     }
   }
 }
