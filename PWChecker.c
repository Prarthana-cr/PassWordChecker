#include <stdio.h>
#include<string.h>
int main() {
   char password[30];
   int upper_count=0,lower_count=0,digit_count=0,special_count=0;
   
   printf("-----PASSWORD STRENGTH CHECKER-----\n");
   printf("Enter your password:");
   fgets(password,sizeof(password),stdin);
   password[strcspn(password,"\n")]='\0';
   
   int pw_length=strlen(password);
   
   for(int i=0;i<pw_length;i++){
       if(password[i]==' '){
           printf("Passwords should not contain spaces.");
           return 0;
       }else if(password[i]>='A' && password[i]<='Z'){
           upper_count=1;
       }else if(password[i]>='a' && password[i]<='z'){
           lower_count=1;
       }else if(password[i]>='0' && password[i]<='9'){
           digit_count=1;
       }else{
           special_count=1;
       }
   }
   
   int score=upper_count+lower_count+digit_count+special_count;
   
   if(strlen(password)<8 || score<=1){
       printf("Password Strength:Weak\n");
   }else if(strlen(password)>=12 && score==4){
       printf("Password Strength:Strong\n");
   }else{
       printf("Password Strngth:Medium\n");
   }
   return 0;
}