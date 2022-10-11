#include<stdio.h>
#include<stdlib.h>
struct myarray{
	int tsize;
	int usize;
	int *ptr;
};
void createarray(struct myarray *a,int t_size,int u_size){
	a->tsize=t_size;
	a->usize=u_size;
	a->ptr=(int*) malloc(u_size*sizeof(int));
}
void setval(struct myarray *a);
void show(struct myarray *a);
int main(){
	struct myarray marks;
	createarray(&marks,10,2);
	setval(&marks);
	show(&marks);
	return 0;
}
void setval(struct myarray *a){
	printf("Enter marks:");
	scanf("%d%d",&(a->ptr)[1],&(a->ptr)[2]);
}
void show(struct myarray *a){
	printf("Marks1:%d\nMarks2:%d",(a->ptr)[1],(a->ptr)[2]);
}

