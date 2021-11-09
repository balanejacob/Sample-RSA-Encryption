
#include <stdio.h>
#include <string.h>
#include <math.h>

void decrypt(int p,int q,char string[]){
	int n,z,e,d,i,length;
	double m,c;
	char decrypted[100]="";
	
	printf("\n\nEncrypted Text: \n >> %s",string);
	
	length=strlen(string);
	
	n=p*q;
	e=7;
	z=(p-1)*(q-1);
	d=10;
	while(((d*e)-1)%z!=0){
		d++;
	}
	
	printf("\nPlain Text: \n >> ");
	
	for(i=0;i<length;i++){
		c=string[i];
		m=pow(c,d);
		m=fmod(m,n);
		decrypted[i]=(int)m;
	}
	printf("%s\n",decrypted);
}

void display_c(char a){
	printf("%c",a);
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
	int n,z,e,d,i,length;
	double m,c;
	char encrypted[100]="";
	
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
		encrypted[i]=(char)c;
	}
	printf("%s\n",encrypted);
	
	decrypt(p,q,encrypted);
}

int main(){
	rsa_encryption(11,13,"ENCRYPTION");
	rsa_encryption(11,13,"RASTAMAN");
	return 0;
}


 
