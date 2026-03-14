#include <stdio.h>


long long inverso_modular(long long a, long long m) {
    long long m0 = m;
    long long x0 = 0;
    long long x1 = 1;
    
    long long valor_a = a;
    long long valor_m = m;

   
    if (a % m == 0) {
        return -1; 
    }

  
    while (valor_a > 1 && valor_m != 0) {
        
        long long q = valor_a / valor_m;
        
        long long t = valor_m;
        
        
        valor_m = valor_a % valor_m;
        valor_a = t;
        
        
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    
    if (valor_a != 1) {
        return -1;
    }

    
    long long resultado = x1 % m0;
    if (resultado < 0) {
        resultado += m0;
    }

    return resultado;
}

int main() {
    long long a = 2689;
    long long m = 3120;

    long long inverso = inverso_modular(a, m);

    if (inverso == -1) {
        printf("No existe el inverso modular para a=%lld y m=%lld\n", a, m);
    } else {
        printf("El inverso modular de %lld mod %lld es: %lld\n", a, m, inverso);
    }

    return 0;
}