import java.io.*;

class AffineCipher {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        File input = new File("FILE PATH FOR INPUT");
        File output = new File("FILE PATH FOR OUTPUT");
        BufferedReader br1 = new BufferedReader(new FileReader(input));
        BufferedWriter or = new BufferedWriter(new FileWriter(output));
        System.out.println("Select 1 for Encryption and 2 for decryption: ");
        int choice = Integer.parseInt(br.readLine());
        if (choice == 1) {
            String pt = br1.readLine();

            System.out.print("Enter the value of a in Encryption formula (must be coprime to 26): ");
            int a = Integer.parseInt(br.readLine());
            if (!isCoprime(a, 26)) {
                System.out.println("!!Enter a value CoPrime to 26!!\nRun Again with proper value of A");
            } else {
                System.out.print("Enter the value of b in Encryption formula: ");
                int b = Integer.parseInt(br.readLine());

                or.write("Encrypted Ciphertext is: " + encryptMessage(pt.toCharArray(), a, b));

            }
        } else {
            String pt = br1.readLine();
            System.out.print("Enter the value of a in Encryption formula (must be coprime to 26): ");
            int a = Integer.parseInt(br.readLine());
            if (!isCoprime(a, 26)) {
                System.out.println("!!Enter a value CoPrime to 26!!\nRun Again with proper value of A");
            } else {
                System.out.print("Enter the value of b in Encryption formula: ");
                int b = Integer.parseInt(br.readLine());

                or.write("Decrypted Plaintext is: " + decryptCipher(pt, a, b));

            }
        }
        or.close();
    }

    static String encryptMessage(char[] msg, int a, int b) {
        
        String cipher = "";
        for (int i = 0; i < msg.length; i++) {
            if (msg[i] != ' ') {
                cipher = cipher + (char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A');
            } else {
                cipher += msg[i];
            }
        }
        return cipher;
    }

    static String decryptCipher(String cipher, int a, int b) {
        String msg = "";
        int a_inv = 0;
        int flag = 0;

        for (int i = 0; i < 26; i++) {
            flag = (a * i) % 26;
            if (flag == 1) {
                a_inv = i;
            }
        }
        for (int i = 0; i < cipher.length(); i++)  {
            if (cipher.charAt(i) != ' ') {
                msg = msg + (char) (((a_inv * ((cipher.charAt(i) + 'A' - b)) % 26)) + 'A');
            } else {
                msg += cipher.charAt(i);
            }
        }

        return msg;
    }

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static boolean isCoprime(int a , int b){
         if (gcd(a,b) == 1)
             return true;
         return false;
    }
}
