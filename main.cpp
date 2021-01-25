#include <iostream>
#include <cmath> 

using namespace std;

double * read_poly1(int &n1){ // the return value of the function is a double  pointer variable -> So coeff is a pointer of a double variable
  cout << "The degree of the polynomial: ";
  cin >> n1;
  double * coeff1 =new double[n1+1]; //allocating an array of n+1 double  
  for(int i=0;i<=n1;i++){ //allocating data to each memory space that we declared previously with double *coeff = new double [n+1]
    cout << "coefficient of degree " << i << ": ";
    cin >> coeff1[i];
  }
  return coeff1;
}

void print_poly1(double *coeff1, int n1){
  int i;
  cout << coeff1[0];
  if(n1>0)
    cout << " + ";
  for(i=1;i<n1;i++)
    cout << coeff1[i] << "*x^" << i << " + ";
  if(n1>0)
    cout << coeff1[n1] << "*x^" << i; // for the last coefficient of the last degree (nth) 
  cout << endl;
}

//ex1. calculation of the polynomial value for a certain position x (returns a real number)
double calculation_poly(double *coeff1, int n1, double x){
  int i;
  double y; // declaration of the result under the variable y 
  y=coeff1[0];

  if(n1>0)
  {
    for(i=1;i<=n1;i++)
    {
      y = y + coeff1[i]*pow(x,i);
    }
  }
  cout << "For x = " << x <<" , the result of the first polynomial is " << y;
  return y;
}

//ex2.Sum of two polynomials 
double * poly_sum (double * poly1, int degree1, double * poly2, int degree2, int & degree_max)
{
   //setting the maximum degree (degree_max) of the polynomial result 
   if( degree1 >  degree2)
   {
     degree_max = degree1;
   }
   else {
     degree_max = degree2;
   }

   //once the max. degree for the polynomial result is knowm, we allocate some memory space with degree_max + 1 because of degree 0 
   double * result_table = new double[degree_max+1];

   int idx1 = 0;
   int idx2 = 0;

   for(int idx_r = 0; idx_r<= degree_max; idx_r++)
   {
      if(idx1 <= degree1 && idx2 <= degree2)
      {
        result_table[idx_r] = poly1[idx1] + poly2[idx2];
        idx1++;
        idx2++;        
      }
      else if( idx2>degree2 && idx1 <= degree1 ){
        result_table[idx_r] = poly1[idx1];
        idx1++;
      } 
      else if( idx1>degree1 && idx2 <= degree2 ){
        result_table[idx_r] = poly2[idx2];
        idx2++;
      } 
   }

  return result_table;
} 

//ex3. Polynomial multiplication  

double * poly_mult(double * poly1, int degree1, double * poly2, int degree2, int & degree_result){
    degree_result = degree1 + degree2;
    double *coeff_m = new double[degree_result+1];
    for(int idx_m= 0; idx_m<=degree_result; idx_m++){
        coeff_m[idx_m] = 0; //initialize the array with 0 
    }
    
    for(int idx1=0; idx1<=degree1; idx1++){
        for (int idx2=0; idx2<=degree2; idx2++){
            coeff_m[idx1+idx2] += poly1[idx1] * poly2[idx2];
        }
    }
    return coeff_m;
}

int main()
{
  double *poly1, *poly2, *result_sum_poly, *result_mult_poly;  
  int degree1, degree2, degree_result;  
  double x;

  poly1=read_poly1(degree1);
  print_poly1(poly1,degree1);
  poly2= read_poly1 (degree2);
  print_poly1(poly2,degree2);

  // ex1. Enter x to calculate the polynomial 
  cout << "\n" << "Enter x: "; 
  cin >> x; 
  calculation_poly(poly1, degree1, x);
  cout << endl; 

// ex2. Polynomial sum   
  result_sum_poly = poly_sum(poly1,degree1, poly2, degree2, degree_result);
  cout << endl;

  cout << "the sum of the two polynomial is: ";
  print_poly1(result_sum_poly,degree_result);
  cout << endl; 

 //ex3. polynomial multiplication 
 result_mult_poly = poly_mult(poly1, degree1, poly2, degree2, degree_result);
 cout << endl;

  cout << "the multiplication of the two polynomials is: ";
  print_poly1(result_mult_poly,degree_result);

 
  delete[] poly1;
  delete[] poly2;
  delete[] result_sum_poly;
  delete[]result_mult_poly;
  return 0;

  
}