#include <stdio.h>
#include <string.h>
struct Employee 
{ 
int Num;
char name[10];
int lateA[50]; 
int leaveA[50]; 
int lateP[50]; 
int leaveP[50]; 
};
int main(int argc, char *argv[]){
	FILE * r=fopen("source06.txt","r");
	int PeopleNum=6,p;
	struct Employee employee[]=
	{
	{1,"",{0},{0},{0},{0}},
	{2,"",{0},{0},{0},{0}},
	{3,"",{0},{0},{0},{0}},
	{4,"",{0},{0},{0},{0}},
	{5,"",{0},{0},{0},{0}},
	{6,"",{0},{0},{0},{0}},
	{7,"",{0},{0},{0},{0}},
	{8,"",{0},{0},{0},{0}},
	{9,"",{0},{0},{0},{0}},
	{10,"",{0},{0},{0},{0}},
};
	int i,j,k,snum=0,quit,quitnei;
	//char *flag;
	char string[1000],c,Name[10];
	
	for(snum=0;snum<PeopleNum;snum++)
	{
	quit=0;
	while(1)
	{if(quit==1)break;
	fgets(string,999,r);
	 //fgets(string,999,r);
		//printf("%s", string);//µ÷ÊÔÓÃ 
		
		
		if(strstr(string,"ÐÕÃû"))
		{
			for(i=39;i<55;i++)
			if(string[i]==':')
			{
				//printf("%c%c\n",string[i+1],string[i+2]);
				
				for(j=i+1,k=0;;)
				{
				if(string[j]=='&'||string[j+1]=='&')break;
				employee[snum].name[k]=string[j];
				employee[snum].name[k+1]=string[j+1];
				j=j+2;k=k+2;
				}
				employee[snum].name[k]='\0';
				
				
				//printf("%d",snum);
				//½áÊø 
		     	
			}
			
			//ÕÒµ½ÐÕÃûºóÕÒ¿¼ÇÚ
			char x1,x2,y1,y2;
			int date=1,q,stop;    printf("\n%s\n",employee[snum].name);
			quitnei=0;
			while(1)
			{if(quitnei==1)break;
				fgets(string,999,r);
				if(strstr(string,"¿¼ÇÚ"))
				{quitnei=1;quit=1;
					for(date=1;date<=16;date++)
					{
					fgets(string,999,r);//printf("%s", string);
						if(strstr(string,":"))
						{
					
						stop=0;//Ôç³Ùµ½ 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='0'&&string[i-1]=='7'||string[i-2]=='0'&&string[i-1]=='8'||string[i-2]=='0'&&string[i-1]=='9'||string[i-2]=='1'&&string[i-1]=='0')
								{
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].lateA[date]=(((x1-'0')*10+(x2-'8'))*60+(y1-'0')*10+(y2-'0'))/10;
				    			stop=1;//printf("%d", employee[snum].lateA[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
				    			else employee[snum].lateA[date]=100;
				    			//else stop=1;
				    			
				    			
							}//Ôç³Ùµ½
							
							 stop=0;//ÔçÔçÍË 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='1'&&string[i-1]=='0'||string[i-2]=='1'&&string[i-1]=='1'||string[i-2]=='1'&&string[i-1]=='2')
								{
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].leaveA[date]=(((x1-'1')*10+(x2-'2'))*60+(y1-'0')*10+(y2-'0'))/(-15);
				    			stop=1;//printf("%d", employee[snum].leaveA[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
								else employee[snum].leaveA[date]=100;
				    		//	else stop=1;
				    			
				    			
							}//ÔçÔçÍË	 
							 
							 
							 stop=0;//ÏÂÎç³Ùµ½ 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='1'&&string[i-1]=='3'||string[i-2]=='1'&&string[i-1]=='4'||string[i-2]=='1'&&string[i-1]=='5')
								{
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].lateP[date]=(((x1-'1')*10+(x2-'3'))*60+(y1-'3')*10+(y2-'0'))/10;
				    			stop=1;//printf("%d", employee[snum].lateP[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
				    			else employee[snum].lateP[date]=100;
				    		//	else stop=1;
				    			
				    			
							}//ÏÂÎç³Ùµ½
							
						stop=0;//ÏÂÎçÔçÍË 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='1'&&string[i-1]=='5'||string[i-2]=='1'&&string[i-1]=='6'||string[i-2]=='1'&&string[i-1]=='7'||string[i-2]=='1'&&string[i-1]=='8'||string[i-2]=='1'&&string[i-1]=='9')
								{printf("%d ", date);
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].leaveP[date]=(((x1-'1')*10+(x2-'7'))*60+(y1-'3')*10+(y2-'0'))/(-15);
				    			stop=1;//printf("%d", employee[snum].leaveP[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
				    			else employee[snum].leaveP[date]=100;
				    		//	else stop=1;
				    			
				    			
							}//ÏÂÎçÔçÍË 
							
								 
							 
							 
				    	}
				    	else
						{		employee[snum].lateA[date]=100;
								employee[snum].leaveA[date]=100;
								employee[snum].lateP[date]=100;
								employee[snum].leaveP[date]=100;
						 } 
				    	
					}
				
					while(1)
					{fgets(string,999,r);
				       if(strstr(string,"¿¼ÇÚ"))break;
					}
				       
					for(date=17;date<=31;date++)
					{
					fgets(string,999,r);//printf("%s", string);
						if(strstr(string,":"))
						{
					
						stop=0;//Ôç³Ùµ½ 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='0'&&string[i-1]=='7'||string[i-2]=='0'&&string[i-1]=='8'||string[i-2]=='0'&&string[i-1]=='9'||string[i-2]=='1'&&string[i-1]=='0')
								{
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].lateA[date]=(((x1-'0')*10+(x2-'8'))*60+(y1-'0')*10+(y2-'0'))/10;
				    			stop=1;//printf("%d", employee[snum].lateA[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
				    			else employee[snum].lateA[date]=100;
				    			//else stop=1;
				    			
				    			
							}//Ôç³Ùµ½
							
							 stop=0;//ÔçÔçÍË 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='1'&&string[i-1]=='0'||string[i-2]=='1'&&string[i-1]=='1'||string[i-2]=='1'&&string[i-1]=='2')
								{
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].leaveA[date]=(((x1-'1')*10+(x2-'2'))*60+(y1-'0')*10+(y2-'0'))/(-15);
				    			stop=1;//printf("%d", employee[snum].leaveA[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
								else employee[snum].leaveA[date]=100;
				    		//	else stop=1;
				    			
				    			
							}//ÔçÔçÍË	 
							 
							 
							 stop=0;//ÏÂÎç³Ùµ½ 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='1'&&string[i-1]=='3'||string[i-2]=='1'&&string[i-1]=='4'||string[i-2]=='1'&&string[i-1]=='5')
								{
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].lateP[date]=(((x1-'1')*10+(x2-'3'))*60+(y1-'3')*10+(y2-'0'))/10;
				    			stop=1;//printf("%d", employee[snum].lateP[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
				    			else employee[snum].lateP[date]=100;
				    		//	else stop=1;
				    			
				    			
							}//ÏÂÎç³Ùµ½
							
						stop=0;//ÏÂÎçÔçÍË 
						for(i=30;;i++)
							{if(stop==1||i>900)break;
				    			if(string[i]==':')
								if(string[i-2]=='1'&&string[i-1]=='5'||string[i-2]=='1'&&string[i-1]=='6'||(string[i-2]=='1'&&string[i-1]=='7')||string[i-2]=='1'&&string[i-1]=='8'||string[i-2]=='1'&&string[i-1]=='9')
								{printf("%d ", date);
								x1=string[i-2];x2=string[i-1];y1=string[i+1];y2=string[i+2];
								employee[snum].leaveP[date]=(((x1-'1')*10+(x2-'7'))*60+(y1-'3')*10+(y2-'0'))/(-15);
				    			stop=1;//printf("%d", employee[snum].leaveP[date]);
					
								//printf("\n%c %c %c %c %d\n",x1,x2,y1,y2,employee[snum].lateA[date]);
				    			}
				    			else employee[snum].leaveP[date]=100;
				    		//	else stop=1;
				    			
				    			
							}//ÏÂÎçÔçÍË 
							
								 
							 
							 
				    	}
				    	else
						{		employee[snum].lateA[date]=100;
								employee[snum].leaveA[date]=100;
								employee[snum].lateP[date]=100;
								employee[snum].leaveP[date]=100;
						 } 
				    	
					}
				
				
				}
			
			}
		
		}
		
	 } 
}

FILE *file=fopen("kaoqin0702.csv","w");
if(file)
{	 
fprintf(file,"ÉÏÎç³Ùµ½,");
for(j=1;j<=31;j++)
fprintf(file,"%d,",j);
fprintf(file,"\n");
for(i=0;i<PeopleNum;i++)
{
fprintf(file,"%s,",employee[i].name);
for(k=1;k<=31;k++)
if(employee[i].lateA[k]==100)
fprintf(file,",");
else
fprintf(file,"%d,",employee[i].lateA[k]);
fprintf(file,"\n");
}

fprintf(file,"\n");

fprintf(file,"ÉÏÎçÔçÍË,");
for(j=1;j<=31;j++)
fprintf(file,"%d,",j);
fprintf(file,"\n");
for(i=0;i<PeopleNum;i++)
{
fprintf(file,"%s,",employee[i].name);
for(k=1;k<=31;k++)
if(employee[i].leaveA[k]==100)
fprintf(file,",");
else
fprintf(file,"%d,",employee[i].leaveA[k]);
fprintf(file,"\n");
}

fprintf(file,"\n");

fprintf(file,"ÏÂÎç³Ùµ½,");
for(j=1;j<=31;j++)
fprintf(file,"%d,",j);
fprintf(file,"\n");
for(i=0;i<PeopleNum;i++)
{
fprintf(file,"%s,",employee[i].name);
for(k=1;k<=31;k++)
if(employee[i].lateP[k]==100)
fprintf(file,",");
else
fprintf(file,"%d,",employee[i].lateP[k]);
fprintf(file,"\n");
}

fprintf(file,"\n");

fprintf(file,"ÏÂÎçÔçÍË,");
for(j=1;j<=31;j++)
fprintf(file,"%d,",j);
fprintf(file,"\n");
for(i=0;i<PeopleNum;i++)
{
fprintf(file,"%s,",employee[i].name);
for(k=1;k<=31;k++)
if(employee[i].leaveP[k]==100)
fprintf(file,",");
else
fprintf(file,"%d,",employee[i].leaveP[k]);
fprintf(file,"\n");
}


}





	fclose(r);
	fclose(file);
return 0;
} 

