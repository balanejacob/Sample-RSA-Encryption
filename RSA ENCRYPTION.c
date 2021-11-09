
#include <stdio.h>
#include <string.h>
#include <math.h>



void display_c(double a){
	printf("%d",(int)a);
}

int gcd(int a, int b){
    int temp;
    while (1){
        temp = a%b;
        if (temp == 0)
          return b;
        a = b;
        b = temp;
    }
}


void rsa_encryption(int p,int q,char string[]){
	int n,z,e,d=1,i,length;
	double m,c;
	
	printf("\n\nPlain Text: \n >> %s",string);
	
	length=strlen(string);
	
	n=p*q;
	e=2;
	z=(p-1)*(q-1);
	
	while(e<z){
		if (gcd(e,z)==1)
	        break;
	    else
	        e++;
	}
	
	d=10;
	
	while(((d*e)-1)%z!=0){
		d++;
	}
	
	printf("\nCypher Text: \n >> ");
	
	for(i=0;i<length;i++){
		m=string[i];
		c=pow(m,e);
		c=fmod(c,n);
		display_c(c);
	}
	
}

int main(){
	rsa_encryption(5,7,"encrypt");
	rsa_encryption(3,5,"secure");
	return 0;
}


 
