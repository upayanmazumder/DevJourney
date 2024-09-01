package Java.Basics;

public class swap {
    
    public static void main(String[] args){
        
        String x="water";
        String y="Kool-Aid";
        String temp;

        System.out.println("Pre-swap x: "+x);
        System.out.println("Pre-swap y: "+y);

        System.out.println("Swapping...");

        temp=x;
        x=y;
        y=temp;

        System.out.println("Swapped!");
        
        System.out.println("Post-swap x: "+x);
        System.out.println("Post-swap y: "+y);
        
    }
}