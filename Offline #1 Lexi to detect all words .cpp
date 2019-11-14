/*** Imrul Hasan - Reg:16101034 - Sec:A(A2) ***/
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int main ()
{
    //All the possible type
    char keywords[32][10]={"break","case","char","const","continue","default","do","auto","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while",};
    char arithmatical[8][5]={"+","-","*","/","%","++","--","="};
    char punctuation[3][2]={",",":",";"};
    char parenthesis[6][3]={"(",")","{","}","[","]"};
    char logical[6][3]={"<",">","<=",">=","==","!="};

    //All the type from gets()
    char *keywordss[15];
    char *arithmaticall[10];
    char *punctuationn[10];
    char *parenthesiss[10];
    char *logicall[10];

    //For Special Case
    char *identifierr[20];
    char *constantt[20];
    char *invalid[20];

        //Input String
        char str[80];
        gets(str);
        const char s[2] = " ";
        char *token;
        int i;
        //size of *char
        int key=0;
        int arith=0;
        int punc=0;
        int peren=0;
        int log=0;
        int con_count=0;
        int iden=0;
        int inv=0;

        token = strtok(str, s);

        while( token != NULL )
        {
        ///Code for Checking Keywords
        for(i=0; i<32; i++)
        {
            if(((strcmp(keywords[i],token))==0))
            {
                int flag=0;
                for(int c=1;c<=key;c++)
                {
                    if(((strcmp(keywordss[c],token))==0))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    key++;
                    keywordss[key]=token;
                }
            }
        }

        ///Code for Checking Arithmatic Operator
        for(i=0; i<8; i++){
            if(((strcmp(arithmatical[i],token))==0)){
                int flag=0;
                for(int c=1;c<=arith;c++){
                    if(((strcmp(arithmaticall[c],token))==0)){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    arith++;
                    arithmaticall[arith]=token;
                }
            }
        }

        ///Code for Checking Punctuation
        for(i=0; i<3; i++){
            if(((strcmp(punctuation[i],token))==0)){
                int flag=0;
                for(int c=1;c<=punc;c++){
                    if(((strcmp(punctuationn[c],token))==0)){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    punc++;
                    punctuationn[punc]=token;
                }
            }
        }

        ///Code for Checking Parenthesis
        for(i=0; i<6; i++){
            if(((strcmp(parenthesis[i],token))==0)){
                int flag=0;
                for(int c=1;c<=peren;c++){
                    if(((strcmp(parenthesiss[c],token))==0)){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    peren++;
                    parenthesiss[peren]=token;
                }
            }
        }

        ///Code for Checking Logical Operator
        for(i=0; i<6; i++){
            if(((strcmp(logical[i],token))==0)){
                int flag=0;
                for(int c=1;c<=log;c++){
                    if(((strcmp(logicall[c],token))==0)){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    log++;
                    logicall[log]=token;
                }
            }
        }

        ///Code for checking constant
        int con=0;
        int len;
        if(isdigit(token[0]))
        {
            len = strlen(token);
            for(int x=0;x<len;x++)
            {
                if(isdigit(token[x]))
                {
                    con++;
                }
            }
            if(con==len)
            {
                int flag=0;
                for(int c=1;c<=con_count;c++)
                {
                    if(((strcmp(constantt[c],token))==0))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    con_count++;
                    constantt[con_count]=token;
                }
            }
            else
            {
                //printf("Invalid Input\n");
                inv++;
                invalid[inv]=token;
            }
        }

        ///Code for checking Identifier
        int yeah=0;
        for(i=0; i<32; i++)
        {
            if(((strcmp(keywords[i],token))!=0))
            {
                yeah++;
            }
        }
        if(yeah==32)
        {
            int l;
            if(isalpha(token[0]) || token[0]=='_')
            {
                int flag=0;
                for(int c=1;c<=iden;c++){
                    if(((strcmp(identifierr[c],token))==0))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    iden++;
                    identifierr[iden]=token;
                }
            }
        }
        token = strtok(NULL, s);
    }

    ///Printing all the possible types
    printf("keyword(%d): ",key);
    for(int i=1;i<=key;i++)
    {
        if(i==key)
        {
            printf("%s ",keywordss[i]);
            break;
        }
        printf("%s, ",keywordss[i]);
    }
    printf("\n");

    printf("Arithmatical(%d): ",arith);
    for(int i=1;i<=arith;i++){
        if(i==arith){
            printf("%s ",arithmaticall[i]);
            break;
        }
        printf("%s, ",arithmaticall[i]);
    }
    printf("\n");

    printf("Punctuation(%d): ",punc);
    for(int i=1;i<=punc;i++){
        if(i==punc){
            printf("%s ",punctuationn[i]);
            break;
        }
        printf("%s, ",punctuationn[i]);
    }
    printf("\n");

    printf("Parenthesis(%d): ",peren);
    for(int i=1;i<=peren;i++){
        if(i==peren){
            printf("%s ",parenthesiss[i]);
            break;
        }
        printf("%s, ",parenthesiss[i]);
    }
    printf("\n");

    printf("Logical(%d): ",log);
    for(int i=1;i<=log;i++){
        if(i==log){
            printf("%s ",logicall[i]);
            break;
        }
        printf("%s, ",logicall[i]);
    }
    printf("\n");

    printf("Constant(%d): ",con_count);
    for(int i=1;i<=con_count;i++){
        if(i==con_count){
            printf("%s ",constantt[i]);
            break;
        }
        printf("%s, ",constantt[i]);
    }
    printf("\n");

    printf("Identifier(%d): ",iden);
    for(int i=1;i<=iden;i++){
        if(i==iden){
            printf("%s ",identifierr[i]);
            break;
        }
        printf("%s, ",identifierr[i]);
    }
    printf("\n");

    printf("Invalid(%d): ",inv);
    for(int i=1;i<=inv;i++){
        if(i==inv){
            printf("%s ",invalid[i]);
            break;
        }
        printf("%s, ",invalid[i]);
    }
    printf("\n");

    main();
    return(0);
}
