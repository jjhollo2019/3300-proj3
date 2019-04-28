//     *********************************
//     *    Matrix Multiply Project    *
//     *                               *
//     *********************************

//     ** MAIN PROGRAM  **


//     *************************************************
//     ** Any changes you make to this code must      **
//     ** maintain the correctness of the matrix      **
//     ** multiply computed by the original version.
//     **					      **
//     ** An implementation with incorrect results for**
//     ** matrix C earns zero point for this project. **
//     ** 
//     ** To print matrix compile with -DPRINT_MATRIX **
//     ** e.g., g++ -DPRINT_MATRIX                    **
//     **                                             **
//     ** A sample Makefile is provided.
//     ** You may assume m = n = k for your matrices  **
//     *************************************************

#include <stdio.h>
#include <stdlib.h>

double **dmatrix(int nrl,int nrh,int ncl,int nch);
void nerror(char *error_text);

int main(int argc, char** argv)  {
 
      int l,m,n,k;
      int i,j;
      double **A, **B, **C;


     //  ****************************************************
     //  * The following allows matrix parameters to be     *
     //  * entered on the command line to take advantage    *
     //  * of dynamically allocated memory.  You may modify *
     //  * or remove it as you wish.                        *
     //  ****************************************************

     if (argc != 4) {
       nerror("Usage:  <executable> <m-value> <n-value> <k-value>");
     }
      m = atoi(argv[1]);
      n = atoi(argv[2]);
      k = atoi(argv[3]);

      // *********************************************************
      // * Call the dmatrix() subroutine to dynamically allocate *
      // * storage for the matrix sizes specified by m, n, and k *  
      // *********************************************************

      A=dmatrix(0,m-1,0,k-1);
      B=dmatrix(0,k-1,0,n-1);
      C=dmatrix(0,m-1,0,n-1);

      // *********************************************************
      //  * Initialize matrix elements so compiler does not      *
      //  * optimize out                                         *
      // *********************************************************

      for(i=0;i<m;i+=5) {
        for(j=0;j<k;j+=5) {
          A[i][j] = i+j+4.0;
          A[i+1][j] = (i+1)+j+4.0;
          A[i+2][j] = (i+2)+j+4.0;
          A[i+3][j] = (i+3)+j+4.0;
          A[i+4][j] = (i+4)+j+4.0;
        }
        for(j=0;j<k;j+=5) {
          A[i][j+1] = i+(j+1)+4.0;
          A[i+1][j+1] = (i+1)+(j+1)+4.0;
          A[i+2][j+1] = (i+2)+(j+1)+4.0;
          A[i+3][j+1] = (i+3)+(j+1)+4.0;
          A[i+4][j+1] = (i+4)+(j+1)+4.0;
        }
        for(j=0;j<k;j+=5) {
          A[i][j+2] = i+(j+2)+4.0;
          A[i+1][j+2] = (i+1)+(j+2)+4.0;
          A[i+2][j+2] = (i+2)+(j+2)+4.0;
          A[i+3][j+2] = (i+3)+(j+2)+4.0;
          A[i+4][j+2] = (i+4)+(j+2)+4.0;
        }
        for(j=0;j<k;j+=5) {
          A[i][j+3] = i+(j+3)+4.0;
          A[i+1][j+3] = (i+1)+(j+3)+4.0;
          A[i+2][j+3] = (i+2)+(j+3)+4.0;
          A[i+3][j+3] = (i+3)+(j+3)+4.0;
          A[i+4][j+3] = (i+4)+(j+3)+4.0;
        }
        for(j=0;j<k;j+=5) {
          A[i][j+4] = i+(j+4)+4.0;
          A[i+1][j+4] = (i+1)+(j+4)+4.0;
          A[i+2][j+4] = (i+2)+(j+4)+4.0;
          A[i+3][j+4] = (i+3)+(j+4)+4.0;
          A[i+4][j+4] = (i+4)+(j+4)+4.0;
        }
      }

      for(i=0;i<m;i+=5) {
        for(j=0;j<k;j+=5) {
          B[i][j] = i+j+5.0;
          B[i+1][j] = (i+1)+j+5.0;
          B[i+2][j] = (i+2)+j+5.0;
          B[i+3][j] = (i+3)+j+5.0;
          B[i+4][j] = (i+4)+j+5.0;
        }
        for(j=0;j<k;j+=5) {
          B[i][j+1] = i+(j+1)+5.0;
          B[i+1][j+1] = (i+1)+(j+1)+5.0;
          B[i+2][j+1] = (i+2)+(j+1)+5.0;
          B[i+3][j+1] = (i+3)+(j+1)+5.0;
          B[i+4][j+1] = (i+4)+(j+1)+5.0;
        }
        for(j=0;j<k;j+=5) {
          B[i][j+2] = i+(j+2)+5.0;
          B[i+1][j+2] = (i+1)+(j+2)+5.0;
          B[i+2][j+2] = (i+2)+(j+2)+5.0;
          B[i+3][j+2] = (i+3)+(j+2)+5.0;
          B[i+4][j+2] = (i+4)+(j+2)+5.0;
        }
        for(j=0;j<k;j+=5) {
          B[i][j+3] = i+(j+3)+5.0;
          B[i+1][j+3] = (i+1)+(j+3)+5.0;
          B[i+2][j+3] = (i+2)+(j+3)+5.0;
          B[i+3][j+3] = (i+3)+(j+3)+5.0;
          B[i+4][j+3] = (i+4)+(j+3)+5.0;
        }
        for(j=0;j<k;j+=5) {
          B[i][j+4] = i+(j+4)+5.0;
          B[i+1][j+4] = (i+1)+(j+4)+5.0;
          B[i+2][j+4] = (i+2)+(j+4)+5.0;
          B[i+3][j+4] = (i+3)+(j+4)+5.0;
          B[i+4][j+4] = (i+4)+(j+4)+5.0;
        }
      }

      for(i=0;i<m;i+=5) {
        for(j=0;j<k;j+=5) {
          C[i][j] = 0.0;
          C[i+1][j] = 0.0;
          C[i+2][j] = 0.0;
          C[i+3][j] = 0.0;
          C[i+4][j] = 0.0;
        }
        for(j=0;j<k;j+=5) {
          C[i][j+1] = 0.0;
          C[i+1][j+1] = 0.0;
          C[i+2][j+1] = 0.0;
          C[i+3][j+1] = 0.0;
          C[i+4][j+1] = 0.0;
        }
        for(j=0;j<k;j+=5) {
          C[i][j+2] = 0.0;
          C[i+1][j+2] = 0.0;
          C[i+2][j+2] = 0.0;
          C[i+3][j+2] = 0.0;
          C[i+4][j+2] = 0.0;
        }
        for(j=0;j<k;j+=5) {
          C[i][j+3] = 0.0;
          C[i+1][j+3] = 0.0;
          C[i+2][j+3] = 0.0;
          C[i+3][j+3] = 0.0;
          C[i+4][j+3] = 0.0;
        }
        for(j=0;j<k;j+=5) {
          C[i][j+4] = 0.0;
          C[i+1][j+4] = 0.0;
          C[i+2][j+4] = 0.0;
          C[i+3][j+4] = 0.0;
          C[i+4][j+4] = 0.0;
        }
      }
          
      // ******************************
      // * Start embedded timing here *
      // ******************************

      // **********************************
      // * Perform simple matrix multiply *
      // **********************************
      for(i=0;i<m;i+=5) {
        for(l=0;l<k;l+=5) {
          for(j=0;j<n;j+=5) {
            C[i][j]   = C[i][j]   + B[l][j]*A[i][l];
            C[i+1][j] = C[i+1][j] + B[l][j]*A[i+1][l];
            C[i+2][j] = C[i+2][j] + B[l][j]*A[i+2][l];
            C[i+3][j] = C[i+3][j] + B[l][j]*A[i+3][l];
            C[i+4][j] = C[i+4][j] + B[l][j]*A[i+4][l];

            C[i][j]   = C[i][j]   + B[l+1][j]*A[i][l+1];
            C[i+1][j] = C[i+1][j] + B[l+1][j]*A[i+1][l+1];
            C[i+2][j] = C[i+2][j] + B[l+1][j]*A[i+2][l+1];
            C[i+3][j] = C[i+3][j] + B[l+1][j]*A[i+3][l+1];
            C[i+4][j] = C[i+4][j] + B[l+1][j]*A[i+4][l+1];

            C[i][j]   = C[i][j]   + B[l+2][j]*A[i][l+2];
            C[i+1][j] = C[i+1][j] + B[l+2][j]*A[i+1][l+2];
            C[i+2][j] = C[i+2][j] + B[l+2][j]*A[i+2][l+2];
            C[i+3][j] = C[i+3][j] + B[l+2][j]*A[i+3][l+2];
            C[i+4][j] = C[i+4][j] + B[l+2][j]*A[i+4][l+2];

            C[i][j]   = C[i][j]   + B[l+3][j]*A[i][l+3];
            C[i+1][j] = C[i+1][j] + B[l+3][j]*A[i+1][l+3];
            C[i+2][j] = C[i+2][j] + B[l+3][j]*A[i+2][l+3];
            C[i+3][j] = C[i+3][j] + B[l+3][j]*A[i+3][l+3];
            C[i+4][j] = C[i+4][j] + B[l+3][j]*A[i+4][l+3];

            C[i][j]   = C[i][j]   + B[l+4][j]*A[i][l+4];
            C[i+1][j] = C[i+1][j] + B[l+4][j]*A[i+1][l+4];
            C[i+2][j] = C[i+2][j] + B[l+4][j]*A[i+2][l+4];
            C[i+3][j] = C[i+3][j] + B[l+4][j]*A[i+3][l+4];
            C[i+4][j] = C[i+4][j] + B[l+4][j]*A[i+4][l+4];



            C[i][j+1]   = C[i][j+1]   + B[l][j+1]*A[i][l];
            C[i+1][j+1] = C[i+1][j+1] + B[l][j+1]*A[i+1][l];
            C[i+2][j+1] = C[i+2][j+1] + B[l][j+1]*A[i+2][l];
            C[i+3][j+1] = C[i+3][j+1] + B[l][j+1]*A[i+3][l];
            C[i+4][j+1] = C[i+4][j+1] + B[l][j+1]*A[i+4][l];

            C[i][j+1]   = C[i][j+1]   + B[l+1][j+1]*A[i][l+1];
            C[i+1][j+1] = C[i+1][j+1] + B[l+1][j+1]*A[i+1][l+1];
            C[i+2][j+1] = C[i+2][j+1] + B[l+1][j+1]*A[i+2][l+1];
            C[i+3][j+1] = C[i+3][j+1] + B[l+1][j+1]*A[i+3][l+1];
            C[i+4][j+1] = C[i+4][j+1] + B[l+1][j+1]*A[i+4][l+1];

            C[i][j+1]   = C[i][j+1]   + B[l+2][j+1]*A[i][l+2];
            C[i+1][j+1] = C[i+1][j+1] + B[l+2][j+1]*A[i+1][l+2];
            C[i+2][j+1] = C[i+2][j+1] + B[l+2][j+1]*A[i+2][l+2];
            C[i+3][j+1] = C[i+3][j+1] + B[l+2][j+1]*A[i+3][l+2];
            C[i+4][j+1] = C[i+4][j+1] + B[l+2][j+1]*A[i+4][l+2];

            C[i][j+1]   = C[i][j+1]   + B[l+3][j+1]*A[i][l+3];
            C[i+1][j+1] = C[i+1][j+1] + B[l+3][j+1]*A[i+1][l+3];
            C[i+2][j+1] = C[i+2][j+1] + B[l+3][j+1]*A[i+2][l+3];
            C[i+3][j+1] = C[i+3][j+1] + B[l+3][j+1]*A[i+3][l+3];
            C[i+4][j+1] = C[i+4][j+1] + B[l+3][j+1]*A[i+4][l+3];

            C[i][j+1]   = C[i][j+1]   + B[l+4][j+1]*A[i][l+4];
            C[i+1][j+1] = C[i+1][j+1] + B[l+4][j+1]*A[i+1][l+4];
            C[i+2][j+1] = C[i+2][j+1] + B[l+4][j+1]*A[i+2][l+4];
            C[i+3][j+1] = C[i+3][j+1] + B[l+4][j+1]*A[i+3][l+4];
            C[i+4][j+1] = C[i+4][j+1] + B[l+4][j+1]*A[i+4][l+4];



            C[i][j+2]   = C[i][j+2]   + B[l][j+2]*A[i][l];
            C[i+1][j+2] = C[i+1][j+2] + B[l][j+2]*A[i+1][l];
            C[i+2][j+2] = C[i+2][j+2] + B[l][j+2]*A[i+2][l];
            C[i+3][j+2] = C[i+3][j+2] + B[l][j+2]*A[i+3][l];
            C[i+4][j+2] = C[i+4][j+2] + B[l][j+2]*A[i+4][l];

            C[i][j+2]   = C[i][j+2]   + B[l+1][j+2]*A[i][l+1];
            C[i+1][j+2] = C[i+1][j+2] + B[l+1][j+2]*A[i+1][l+1];
            C[i+2][j+2] = C[i+2][j+2] + B[l+1][j+2]*A[i+2][l+1];
            C[i+3][j+2] = C[i+3][j+2] + B[l+1][j+2]*A[i+3][l+1];
            C[i+4][j+2] = C[i+4][j+2] + B[l+1][j+2]*A[i+4][l+1];

            C[i][j+2]   = C[i][j+2]   + B[l+2][j+2]*A[i][l+2];
            C[i+1][j+2] = C[i+1][j+2] + B[l+2][j+2]*A[i+1][l+2];
            C[i+2][j+2] = C[i+2][j+2] + B[l+2][j+2]*A[i+2][l+2];
            C[i+3][j+2] = C[i+3][j+2] + B[l+2][j+2]*A[i+3][l+2];
            C[i+4][j+2] = C[i+4][j+2] + B[l+2][j+2]*A[i+4][l+2];

            C[i][j+2]   = C[i][j+2]   + B[l+3][j+2]*A[i][l+3];
            C[i+1][j+2] = C[i+1][j+2] + B[l+3][j+2]*A[i+1][l+3];
            C[i+2][j+2] = C[i+2][j+2] + B[l+3][j+2]*A[i+2][l+3];
            C[i+3][j+2] = C[i+3][j+2] + B[l+3][j+2]*A[i+3][l+3];
            C[i+4][j+2] = C[i+4][j+2] + B[l+3][j+2]*A[i+4][l+3];

            C[i][j+2]   = C[i][j+2]   + B[l+4][j+2]*A[i][l+4];
            C[i+1][j+2] = C[i+1][j+2] + B[l+4][j+2]*A[i+1][l+4];
            C[i+2][j+2] = C[i+2][j+2] + B[l+4][j+2]*A[i+2][l+4];
            C[i+3][j+2] = C[i+3][j+2] + B[l+4][j+2]*A[i+3][l+4];
            C[i+4][j+2] = C[i+4][j+2] + B[l+4][j+2]*A[i+4][l+4];



            C[i][j+3]   = C[i][j+3]   + B[l][j+3]*A[i][l];
            C[i+1][j+3] = C[i+1][j+3] + B[l][j+3]*A[i+1][l];
            C[i+2][j+3] = C[i+2][j+3] + B[l][j+3]*A[i+2][l];
            C[i+3][j+3] = C[i+3][j+3] + B[l][j+3]*A[i+3][l];
            C[i+4][j+3] = C[i+4][j+3] + B[l][j+3]*A[i+4][l];

            C[i][j+3]   = C[i][j+3]   + B[l+1][j+3]*A[i][l+1];
            C[i+1][j+3] = C[i+1][j+3] + B[l+1][j+3]*A[i+1][l+1];
            C[i+2][j+3] = C[i+2][j+3] + B[l+1][j+3]*A[i+2][l+1];
            C[i+3][j+3] = C[i+3][j+3] + B[l+1][j+3]*A[i+3][l+1];
            C[i+4][j+3] = C[i+4][j+3] + B[l+1][j+3]*A[i+4][l+1];

            C[i][j+3]   = C[i][j+3]   + B[l+2][j+3]*A[i][l+2];
            C[i+1][j+3] = C[i+1][j+3] + B[l+2][j+3]*A[i+1][l+2];
            C[i+2][j+3] = C[i+2][j+3] + B[l+2][j+3]*A[i+2][l+2];
            C[i+3][j+3] = C[i+3][j+3] + B[l+2][j+3]*A[i+3][l+2];
            C[i+4][j+3] = C[i+4][j+3] + B[l+2][j+3]*A[i+4][l+2];

            C[i][j+3]   = C[i][j+3]   + B[l+3][j+3]*A[i][l+3];
            C[i+1][j+3] = C[i+1][j+3] + B[l+3][j+3]*A[i+1][l+3];
            C[i+2][j+3] = C[i+2][j+3] + B[l+3][j+3]*A[i+2][l+3];
            C[i+3][j+3] = C[i+3][j+3] + B[l+3][j+3]*A[i+3][l+3];
            C[i+4][j+3] = C[i+4][j+3] + B[l+3][j+3]*A[i+4][l+3];

            C[i][j+3]   = C[i][j+3]   + B[l+4][j+3]*A[i][l+4];
            C[i+1][j+3] = C[i+1][j+3] + B[l+4][j+3]*A[i+1][l+4];
            C[i+2][j+3] = C[i+2][j+3] + B[l+4][j+3]*A[i+2][l+4];
            C[i+3][j+3] = C[i+3][j+3] + B[l+4][j+3]*A[i+3][l+4];
            C[i+4][j+3] = C[i+4][j+3] + B[l+4][j+3]*A[i+4][l+4];



            C[i][j+4]   = C[i][j+4]   + B[l][j+4]*A[i][l];
            C[i+1][j+4] = C[i+1][j+4] + B[l][j+4]*A[i+1][l];
            C[i+2][j+4] = C[i+2][j+4] + B[l][j+4]*A[i+2][l];
            C[i+3][j+4] = C[i+3][j+4] + B[l][j+4]*A[i+3][l];
            C[i+4][j+4] = C[i+4][j+4] + B[l][j+4]*A[i+4][l];

            C[i][j+4]   = C[i][j+4]   + B[l+1][j+4]*A[i][l+1];
            C[i+1][j+4] = C[i+1][j+4] + B[l+1][j+4]*A[i+1][l+1];
            C[i+2][j+4] = C[i+2][j+4] + B[l+1][j+4]*A[i+2][l+1];
            C[i+3][j+4] = C[i+3][j+4] + B[l+1][j+4]*A[i+3][l+1];
            C[i+4][j+4] = C[i+4][j+4] + B[l+1][j+4]*A[i+4][l+1];

            C[i][j+4]   = C[i][j+4]   + B[l+2][j+4]*A[i][l+2];
            C[i+1][j+4] = C[i+1][j+4] + B[l+2][j+4]*A[i+1][l+2];
            C[i+2][j+4] = C[i+2][j+4] + B[l+2][j+4]*A[i+2][l+2];
            C[i+3][j+4] = C[i+3][j+4] + B[l+2][j+4]*A[i+3][l+2];
            C[i+4][j+4] = C[i+4][j+4] + B[l+2][j+4]*A[i+4][l+2];

            C[i][j+4]   = C[i][j+4]   + B[l+3][j+4]*A[i][l+3];
            C[i+1][j+4] = C[i+1][j+4] + B[l+3][j+4]*A[i+1][l+3];
            C[i+2][j+4] = C[i+2][j+4] + B[l+3][j+4]*A[i+2][l+3];
            C[i+3][j+4] = C[i+3][j+4] + B[l+3][j+4]*A[i+3][l+3];
            C[i+4][j+4] = C[i+4][j+4] + B[l+3][j+4]*A[i+4][l+3];

            C[i][j+4]   = C[i][j+4]   + B[l+4][j+4]*A[i][l+4];
            C[i+1][j+4] = C[i+1][j+4] + B[l+4][j+4]*A[i+1][l+4];
            C[i+2][j+4] = C[i+2][j+4] + B[l+4][j+4]*A[i+2][l+4];
            C[i+3][j+4] = C[i+3][j+4] + B[l+4][j+4]*A[i+3][l+4];
            C[i+4][j+4] = C[i+4][j+4] + B[l+4][j+4]*A[i+4][l+4];
          }
        }
      }
      // ******************************
      // * Stop embedded timing here  *
      // ******************************

      // **************************************************
      // * Print out a 10 x 10 matrix for testing only    *
      // * Comment out when timing                        *
      // **************************************************

 #ifdef PRINT_MATRIX
      fprintf(stdout, "Here is the matrix A:\n\n");
      for(i=0;i<m;i++) {
        for(j=0;j<k;j++) {
          fprintf(stdout, "%10.2f ",A[i][j]);
        }
        fprintf(stdout, "\n");
      }
      fprintf(stdout, "Here is the matrix B:\n\n");
      for(i=0;i<k;i++) {
        for(j=0;j<n;j++) {
          fprintf(stdout, "%10.2f",B[i][j]);
        }
        fprintf(stdout, "\n");
      }
      fprintf(stdout, "Here is the matrix C:\n\n");
      for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
          fprintf(stdout, "%10.2f",C[i][j]);
        }
        fprintf(stdout, "\n");
      }
#endif        
        
}
//     **  END MAIN PROGRAM  **

//     ********************************************************
//     *******    BEGIN SUBROUTINES    ************************
//     ********************************************************

double **dmatrix(int nrl,int nrh,int ncl,int nch)
// Allocates a double matrix with range [nrl..nrh][ncl..nch]
{
  int i;
  double **m;

//    Allocate pointers to rows
  m=(double **) malloc((unsigned)(nrh-nrl+1)*sizeof(double *));
  if (!m) nerror("allocation failure in malloc in dmatrix()");
  m -= nrl;
//    Allocate rows and set pointers to them
  for(i=nrl;i<=nrh;i++) {
    m[i]=(double*) malloc((unsigned) (nch-ncl+1)*sizeof(double));
    if (!m[i]) nerror("allocaion failure in malloc in dmatrix()");
    m[i] -= ncl;
  }
  return m;
}

void nerror(char *error_text)
{
  void exit();
  fprintf(stderr, "Run-time error...\n");
  fprintf(stderr,"%s\n",error_text);
  fprintf(stderr,"Exiting...\n");
  exit(1);
}
