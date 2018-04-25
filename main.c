#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include<string.h>
#include "reg.h"


long status[] = {
	high_vol_status,
	low_vol_status,
	high_fre_status,
	low_fre_status,
	high_temp_status,
	low_temp_status,
	rate_temp_status,
	imesh_fault_status,
	emesh_open_status,
	emesh_fault_status,
	emesh1_status,
	emesh2_status,
	emesh3_status,
	emesh4_status,
	tamper_N0_status,
	tamper_P0_status,
};

const char status_print[][20] = {
	 "high_vol", "low_vol", "high_fre", "low_fre","high_temp","low_temp",
	"rate_temp","imesh_fault","emesh_open","emesh_fault","emesh1","emesh2","emesh3","emesh4","tamper_N0","tamper_P0",
}; 
	

int main(int argc, char** argv) {
    long reg;
	int flag,flag1;
	char i,len;
	char string[25];
	char attack_flag;

	printf("		   -------------BBL_reg_tool-------------\n");
	printf("\n\n\n");
	printf("Version:1.1\n\n");
go_on:
	attack_flag = 0;
	printf("Please input the value of the register:");
	scanf("%s",string);		//输入的的是字符串 
	sscanf(string, "%lx", &reg); 	//字符串转16进制 
	len = strlen(string);
	if(len != 8)
	{
		printf("\n\n");
		printf("This input  is incorrect!!\n");
		goto choose;
	}
	
	printf("\n\n");
	
	if(((reg & mod_flag) == mod_flag) && ((reg & mod_flag2) == 0)) 	//最高位置位，且后面的位都未置位的情况 
	{
		printf("The device is on power for the first time, or the BBL reg is not emptied.\n");
		attack_flag = 1; 	//触发标志位	
	}
	
	flag1 = sizeof(status)/sizeof(long);
	for(i = 0;i<flag1;i++)
	{
		if((reg & status[i]) == status[i])	//逐一比较寄存器中的触发位 
		{
			printf("The %s has been triggered\n",status_print[i]);
			attack_flag = 1;		
		}
	}
	
	if(!attack_flag)
	printf("No attack.\n");
	
	printf("-----------------------\n\n\n");
choose:	
	printf("-----------------------\n\n\n");
	
	goto go_on;
	
	while(1);
	return 1;
}
