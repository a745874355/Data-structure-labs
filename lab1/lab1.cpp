/**************************************************/
/*                                                */
/*  Lab 1 Starter file                            */
/*                                                */
/*  Name: Shichao Wang                            */
/*  Student number: 106194152                     */
/*                                                */
/**************************************************/

unsigned int factorial (unsigned int n){
    unsigned int result = 1;
    for(; n > 0; n--){
        result *= n;
    }
    return result;
}

double power (double base, unsigned int n){
    double result = base;
    if(n == 0) return 1;
    for(unsigned int i = n - 1; i > 0; i--){
        result *= base;
    }
    return result;
}
unsigned int fibonacci (unsigned int n){
	
}