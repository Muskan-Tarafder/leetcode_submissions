bool isValid(char* s) {
    int length=strlen(s);
    if(length%2!=0){
        return false;
    }
    char *stack=malloc(length*sizeof(char));
    int top=-1;
    for(int i=0;i<length;i++){
        char current=s[i];
        if(current=='[' || current=='{' || current=='(')
            stack[++top]=current;
        else
        {
            if (top==-1){
                free(stack);
                return false;
            }
            char topElement=stack[top--];
            if(current==')' && topElement!='(' || current=='}' && topElement!='{' || current==']' && topElement!='['){
            free(stack);
            return false;
        }
        } 
    }  
    bool result=(top==-1);
        free(stack);
        return result;  
}
