

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
    try {
               ServerSocket sock =  new ServerSocket(6013);
               Socket client = sock.accept();
               PrintWriter out = new PrintWriter(client.getOutputStream(), true);
               InputStream inp = client.getInputStream();
               BufferedReader in = new BufferedReader(new InputStreamReader(inp));
               String input;
               
              while(true){
                input = in.readLine();
                out.println(input);

             }
           }    catch (IOException ioe) {

                System.err.println(ioe);
           }
       }
   }
