/**************************************************/
/*                                                */
/*  Lab 1 Starter file                            */
/*                                                */
/*  Name: Shichao Wang                            */
/*  Student number: 106194152                     */
/*                                                */
/**************************************************/

unsigned int factorial (unsigned int n){ //Worst complex: O(n) = 2+4n
    unsigned int result = 1; // 1
    for(; n > 0; n--){ // 2n
        result *= n; // 2n
    }
    return result; // 1
}

double power (double base, unsigned int n){ //Worst complex: O(n) = 4n
    if(n == 0) return 1; //1
    double result = base; //1
    for(unsigned int i = n - 1; i > 0; i--){ // 1 + 2(n-1) = 1+2n-2 = 2n-1
        result *= base; //2n - 1
    }
    return result; //1
}
unsigned int fibonacci (unsigned int n){
	if(n == 0) return 0; // 1
    if(n == 1) return 1; // 1
    unsigned int result = 1; // 1
    n-=2; // 2
    for(; n >0;n--){ // 2
        result += fibonacci(n); 
    }
    return result; // 1 
}