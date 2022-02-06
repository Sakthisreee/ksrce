import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner ipt=new Scanner(System.in);
		int row;
		int col;
        System.out.println("Enter no of rows: ");
		row=ipt.nextInt();
        System.out.println("Enter no of columns: ");
		col=ipt.nextInt();
	  int arr[][]=new int [row][col];
      System.out.println("Enter array elements: ");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=ipt.nextInt();
        }
    }
    
    
    int max=0,start=0,mid=0,ones=0,row_max=0;
    int end=col-1;
    for(int i=0;i<row;i++){
        while(arr[i][col-1]!=0 && mid>=0 && mid<col){
           
            mid=(start+end)/2;
            if(arr[i][mid]==1){
                if( mid==0 || arr[i][mid-1]==0 ){
                    ones=col-mid;
                    break;
                }
                else{
                    end=mid-1;
                }

            }
           if(arr[i][mid]<1){
                start=mid+1;
            }
        }
        if(ones>max){
            max=ones;
            row_max=i;
        
        }
        start=0;
        end=col-1;
        
    }
    
    System.out.print("Row with maximum ones: "+(row_max+1));
    

	}
}
