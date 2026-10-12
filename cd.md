1) Implement DFA that accept all the strings of a’s and b’s 3rd symbol from is RHS always a .

#include <stdio.h>
int main(){
    char s[100];int st=0,i;
    printf("Enter string: ");scanf("%s",s);
    for(i=0;s[i];i++){
        if(s[i]!='a'&&s[i]!='b'){puts("Invalid");return 0;}
        st=((st<<1)|(s[i]=='a'))&7;
    }
    puts(st&4?"Accepted":"Rejected");
}

Enter string: abb
Accepted
Enter string: bab
Rejected










2) Implement the DFA that accepts all the string of a’s and b’s where number of a ‘s is divisible by 3 
and number of b‘s is divisible by 2. 

#include <stdio.h>
int main(){
    char s[100];int a=0,b=0,i;
    printf("Enter string: ");scanf("%s",s);
    for(i=0;s[i];i++){
        if(s[i]=='a')a=(a+1)%3;
        else if(s[i]=='b')b=(b+1)%2;
        else{puts("Invalid");return 0;}
    }
    puts(!a&&!b?"Accepted":"Rejected");
}

Enter string: aaabb
Accepted
Enter string: aab
Rejected








3) Implement DFA accepting the language of strings not ending with 00 over the input (0,1)

#include <stdio.h>
int main(){
    char s[100];int st=0,i;
    printf("Enter string: ");scanf("%s",s);
    for(i=0;s[i];i++){
        if(s[i]=='1')st=0;
        else if(s[i]=='0')st=st<2?st+1:2;
        else{puts("Invalid");return 0;}
    }
    puts(st!=2?"Accepted":"Rejected");
}

Enter string: 101
Accepted
Enter string: 1100
Rejected









4) Write a ‘C’ program to implement lexical analyzer using c program. 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char s[200],t[50],*kw[]={"int","float","if","else","while","for","return"};
    int i=0,j,k,x;
    printf("Enter code: ");fgets(s,200,stdin);
    while(s[i]){
        if(isspace(s[i])){i++;continue;}
        j=0;
        if(isalpha(s[i])||s[i]=='_'){
            while(isalnum(s[i])||s[i]=='_')t[j++]=s[i++];
            t[j]=0;k=0;
            for(x=0;x<7;x++)if(!strcmp(t,kw[x]))k=1;
            printf("%s\t%s\n",t,k?"Keyword":"Identifier");
        }else if(isdigit(s[i])){
            while(isdigit(s[i]))t[j++]=s[i++];
            t[j]=0;printf("%s\tNumber\n",t);
        }else{
            printf("%c\t%s\n",s[i],strchr("+-*/=<>%",s[i])?"Operator":"Symbol");i++;
        }
    }
}

Enter code: int x = 10 + y;
int     Keyword
x       Identifier
=       Operator
10      Number
+       Operator
y       Identifier
;       Symbol






















5) write recursive descent parser for the grammar S->(L) S->a L->L,S L->S

#include <stdio.h>
char *p;
int L();
int S(){
    if(*p=='a'){p++;return 1;}
    if(*p=='('){p++;if(L()&&*p==')'){p++;return 1;}}
    return 0;
}
int L(){
    if(!S())return 0;
    while(*p==','){p++;if(!S())return 0;}
    return 1;
}
int main(){
    char s[100];
    printf("Enter string: ");scanf("%s",s);p=s;
    puts(S()&&*p==0?"Accepted":"Rejected");
}

Enter string: (a,(a,a))
Accepted
Enter string: (a,)
Rejected



6) Write a C program to calculate first function for the grammar
 E->E+T E->T T->T*F T->F 
 F->(E)/id

#include <stdio.h>
#include <ctype.h>
#include <string.h>
char lhs[20],rhs[20][20],f[26][30];
int add(int A,char c){
    int l;
    if(strchr(f[A],c))return 0;
    l=strlen(f[A]);f[A][l]=c;f[A][l+1]=0;return 1;
}
int main(){
    int n,i,ch=1;char s[30],*q;
    printf("Number of productions: ");scanf("%d",&n);
    printf("Enter productions (e.g. E=E+T):\n");
    for(i=0;i<n;i++){scanf("%s",s);lhs[i]=s[0];strcpy(rhs[i],s+2);}
    while(ch){
        ch=0;
        for(i=0;i<n;i++){
            char c=rhs[i][0];
            if(!isupper(c))ch|=add(lhs[i]-'A',c);
            else for(q=f[c-'A'];*q;q++)ch|=add(lhs[i]-'A',*q);
        }
    }
    for(i=0;i<26;i++)if(f[i][0]){
        printf("FIRST(%c) = { ",'A'+i);
        for(q=f[i];*q;q++)printf("%c%s",*q,q[1]?", ":" ");
        puts("}");
    }
}

Number of productions: 6
Enter productions (e.g. E=E+T):
E=E+T
E=T
T=T*F
T=F
F=(E)
F=i
FIRST(E) = { (, i }
FIRST(F) = { (, i }
FIRST(T) = { (, i }
