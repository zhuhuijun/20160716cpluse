int main(int argc, char const *argv[])
{
	pid_t children=fork();
	if(children==-1){
		printf("call fork error\n", );
		return -1;
	}
	if (children==1)
	{
		printf("is children \n");
	}else{
		printf("child pid is%d \n",children);
	}
	return 0;
}