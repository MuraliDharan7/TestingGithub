public class Main{
    public static void main(String[] args){
        int num =4;
        int result = mystery(num);
        System.out.println(result);
    }
    public static int mystery(int n){
        if(n==0){
            return 1;
        }
        else{
            return (n & 1) + mystery(n >> 1);
        }
    }
}