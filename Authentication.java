import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.security.MessageDigest;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
 
class Credentials {
    public static void Credentials(String original) throws Exception {
        MessageDigest md = MessageDigest.getInstance("MD5");
        md.update(original.getBytes());
        byte[] digest = md.digest();
         
        StringBuffer sb = new StringBuffer();
        for (byte b : digest) {
            sb.append(String.format("%02x", b & 0xff));
        }
        return;
    }
}
 
public class Authentication {
 
    public static void main(String[] args) throws Exception {
        Map<String, String> credentials = new HashMap<>();
        credentials.put("griffin.keyes", "108de81c31bf9c622f76876b74e9285f");
        credentials.put("rosario.dawson", "3e34baa4ee2ff767af8c120a496742b5");
        credentials.put("bernie.gorilla", "a584efafa8f9ea7fe5cf18442f32b07b");
        credentials.put("donald.monkey",    "17b1b7d8a706696ed220bc414f729ad3");
        credentials.put("jerome.grizzlybear",   "3adea92111e6307f8f2aae4721e77900");
        credentials.put("bruce.grizzlybear",    "0d107d09f5bbe40cade3de5c71e9e9b7");
 
         
        boolean success = false;
        BufferedReader scnr = new BufferedReader(new InputStreamReader(System.in));
        String userName = null;
     
    for (int i = 0; i < 3; ++i){
        System.out.println("Enter username:");
        userName = scnr.readLine();
        System.out.println("Enter password:");
        String password1 = scnr.readLine();
        }
    String hash = credentials.get(userName);
        String password1;
        String zookeeper     = "griffin.keyes";
        String zookeeper1    = "donald.monkey";
        String veterinarian  = "bernie.gorilla";
        String veterinarian1 = "jerome.grizzlybear";
        String Admin         = "rosario.dawson";
        String Admin1        = "bruce.grizzlybear";
        String password;
 
         
      if (userName.equals(zookeeper)) {                        
            System.out.println("Please enter password");          
            System.out.println();
             
             
            System.out.println("Hello, Zookeeper!\n" +
                    "\n" + "As zookeeper, you have access to all of the"
                    + " animals'" + " information and their" + " daily"
                    + " monitoring logs. This " + "allows you to track their "
                    + "feeding habits, habitat conditions, and general welfare.");
            System.out.println();
        }
         
        if (userName.equals(zookeeper1)) {
            System.out.println("Please enter password");
            System.out.println();
             
            System.out.println("Hello, Zookeeper!\n" +
                    "\n" + "As zookeeper, you have access to all of the"
                    + " animals'" + " information and their" + " daily"
                    + " monitoring logs. This " + "allows you to track their "
                    + "feeding habits, habitat conditions, and general welfare.");
            System.out.println();
        }
         
        if (userName.equals(veterinarian)) {
            System.out.println("Please enter password");
            System.out.println();
             
            System.out.println("Hello, Veterinarian!\n" + "\n" + "As "
                    + "veterinarian, you have access to all of the animals'"
                    + " health records. This allows you to view each animal's "
                    + "medical history and current treatments/illnesses "
                    + "(if any), and to maintain a vaccination log.");
            System.out.println();
        }
         
        if (userName.equals(veterinarian1)) {
            System.out.println("Please enter password");
            System.out.println();
             
            System.out.println("Hello, Veterinarian!\n" + "\n" + "As "
                    + "veterinarian, you have access to all of the animals'"
                    + " health records. This allows you to view each animal's "
                    + "medical history and current treatments/illnesses "
                    + "(if any), and to maintain a vaccination log.");
            System.out.println();
        }
         
        if (userName.equals(Admin)) {
            System.out.println("Please enter password");
            System.out.println();
             
            System.out.println("Hello, System Admin!\n" + "\n" + "As"
                    + " administrator, you have access to the zoo's main "
                    + "computer system.  This allows you to monitor users in "
                    + "the system and their roles.");
            System.out.println();
        }
         
        if (userName.equals(Admin1)) {
            System.out.println("Please enter password");
            System.out.println();
             
            System.out.println("Hello, System Admin!\n" + "\n" + "As"
                    + " administrator, you have access to the zoo's main "
                    + "computer system.  This allows you to monitor users in "
                    + "the system and their roles.");
            System.out.println();
        }
          
        else {
            System.out.println("Please enter correct login information!");                    
                 
        }
 
         
    }
}