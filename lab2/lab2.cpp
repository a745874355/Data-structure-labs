/**************************************************/
/*                                                */
/*  Lab 2 Starter file                            */
/*                                                */
/*  Name:                                         */
/*  Student number:                               */
/*                                                */
/**************************************************/

unsigned int factorial (unsigned int n){
    unsigned rc = 1;
    if (n > 1)
    {
        rc *= n * factorial(n - 1); 
    }
    return rc;
}

double power (double base, unsigned int n){
    if(n == 0) return 1;
    double rc = base;
    if(n > 1){
        rc = base * power(base, n - 1);
    }
    return rc;  
}

//I have no idea why it works.
unsigned int fibonacci (unsigned int n){
	if(n == 0) return 0; // 1
    if(n == 1) return 1; // 1
    unsigned int result = 1; // 1, default result for fibo(2)
    //Ok.. I don't know why it works.
    n-=2; // 2, start doing fibo(n-2)
    for(; n > 0; n--){ // 2, after fibo(n - 2) done, seems like it starts doing fibo(n-3)????
                        // maybe cause it starts from fibo(2) so (fibo(n-2) + fibo(n-3)) works
        result += fibonacci(n); 
    }
    return result; // 1 
}

// unsigned int fibonacci(unsigned int n){
//     if(n<=1){
//         return n;
//     }
//     return fibonacci(n-1)+fibonacci(n-2);
// }


