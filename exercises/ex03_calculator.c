#include <stdio.h>

// funções SECUNDÁRIAS
float adicao(float a, float b) {
	float res = a+b;
	return res;
}

float subtracao(float a, float b) {
	float res = a-b;
	return res;
}

float multiplicacao(float a, float b) {
	float res = a*b;
	return res;
}

float divisao(float a, float b) {
	float res = a/b;
	return res;
}

float inverso(float n) {
	float res = 1/n;
	return res;
}

float quadrado(float n) {
	float res = n*n;
	return res;
}

float raiz(float n) {
	float y = 1.0, vabs = 1;
	
	// tolerância do erro para sair da aproximação
	float tol = 0.001; 

	// realiza sucessivas aproximações para obter raiz SEM USAR FUNÇÃO pronta de biblioteca
    while ( vabs > tol)
    {
        y = (y +n/y)/2.0;
        vabs = (n/y -y);
        if(vabs < 0){
            vabs = vabs*(-1);
        }
    }
	return y;
}


// função PRINCIPAL
int main() {
	float num1, num2, resultado;
	char oper, cont = 0;
    
    while(1){
	    printf("Enter the mathematical operation: ");
        scanf("%c", &oper);
        
        // solicita número 1
        if(cont == 0){
            printf("Enter the first number: ");
            scanf("%f", &num1 );
        }
        else{
            num1 = resultado;
        }
    
	    if ( (oper != 'i') && (oper != 'q') && (oper != 'r') && (oper != '=') ){
            // solicita número 2
            printf("Enter the second number: ");
	        scanf("%f", &num2 );
	    }
	    
	    switch (oper) {
	        case '+':
	            resultado = adicao(num1, num2);
	            break;
	        case '-':
	            resultado = subtracao(num1, num2);
	            break;
	        case '*':
	            resultado = multiplicacao(num1, num2);
	            break;
	        case '/':
	            resultado = divisao(num1, num2);
	            break;
	        case 'i':
	            resultado = inverso(num1);
	            break;
	        case 'q':
	            resultado = quadrado(num1);
	            break;
	        case 'r':
	            resultado = raiz(num1);
	            break;
        }
        printf("The result is %.2f\n", resultado);
        cont ++;
        
        // encerra se '=' foi digitado
        if(oper == '='){
            return 0;
        }
        
        // solução para limpar buffer de entrada e 'enters' não impactarem no scanf em próxima iteração  
        getchar();
    }
}