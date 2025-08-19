//Q. evaluation of pasfix expressions operations on stacks.
#include<stdio.h>
#include<ctype.h>
int stack [20],top=-1;
void push (int val){
	stack[++top]=val;
}
int pop(){
	return stack[top--];
}
int main (){
	char exp []="53*62/+4-";//(5*3)+(6/2)-4 = 15+3-4 = 14
	int i,op1,op2;
	for(i=0;exp[i];i++){
		if (isdigit(exp[i]))
			push(exp[i]-'0');
		else{
			op2=pop();op1=pop();
			switch(exp[i]){
				case'+':push(op1+op2);break;
				case'-':push(op1-op2);break;
				case'*':push(op1*op2);break;
				case'/':push(op1/op2);break;
			}
		}
	}
	printf("result=%d\n",pop());
	return 0;
}
