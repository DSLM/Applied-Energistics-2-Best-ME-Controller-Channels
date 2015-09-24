#include <iostream>
using namespace std;
int aeC1[10][10][10]={0},aeC2[10][10][10]={0},aeC3[10][10][10]={0},i,j,k,t=0,s=0,n=0;
int Run3(int a3,int b3,int c3){
	if(aeC2[a3+1][b3][c3]==100)aeC2[a3][b3][c3]++;
	if(aeC2[a3][b3+1][c3]==100)aeC2[a3][b3][c3]++;
	if(aeC2[a3][b3][c3+1]==100)aeC2[a3][b3][c3]++;
	if(aeC2[a3-1][b3][c3]==100)aeC2[a3][b3][c3]++;
	if(aeC2[a3][b3-1][c3]==100)aeC2[a3][b3][c3]++;
	if(aeC2[a3][b3][c3-1]==100)aeC2[a3][b3][c3]++;
	return 0;
}
int Run2(int a2,int b2,int c2){
	if(aeC2[a2+1][b2][c2]==0&a2<9){Run3(a2+1,b2,c2);if(aeC2[a2+1][b2][c2]==0){aeC2[a2+1][b2][c2]=50;}Run2(a2+1,b2,c2);}
	if(aeC2[a2][b2+1][c2]==0&b2<9){Run3(a2,b2+1,c2);if(aeC2[a2][b2+1][c2]==0){aeC2[a2][b2+1][c2]=50;}Run2(a2,b2+1,c2);}
	if(aeC2[a2][b2][c2+1]==0&c2<9){Run3(a2,b2,c2+1);if(aeC2[a2][b2][c2+1]==0){aeC2[a2][b2][c2+1]=50;}Run2(a2,b2,c2+1);}
	if(aeC2[a2-1][b2][c2]==0&a2>1){Run3(a2-1,b2,c2);if(aeC2[a2-1][b2][c2]==0){aeC2[a2-1][b2][c2]=50;}Run2(a2-1,b2,c2);}
	if(aeC2[a2][b2-1][c2]==0&b2>1){Run3(a2,b2-1,c2);if(aeC2[a2][b2-1][c2]==0){aeC2[a2][b2-1][c2]=50;}Run2(a2,b2-1,c2);}
	if(aeC2[a2][b2][c2-1]==0&c2>1){Run3(a2,b2,c2-1);if(aeC2[a2][b2][c2-1]==0){aeC2[a2][b2][c2-1]=50;}Run2(a2,b2,c2-1);}
	return 0;
}
int Run1(int a1,int b1,int c1){
	aeC2[a1][b1][c1]=100;
	if(aeC2[a1+1][b1][c1]==1){aeC2[a1+1][b1][c1]=100;Run1(a1+1,b1,c1);}
	if(aeC2[a1][b1+1][c1]==1){aeC2[a1][b1+1][c1]=100;Run1(a1,b1+1,c1);}
	if(aeC2[a1][b1][c1+1]==1){aeC2[a1][b1][c1+1]=100;Run1(a1,b1,c1+1);}
	if(aeC2[a1-1][b1][c1]==1){aeC2[a1-1][b1][c1]=100;Run1(a1-1,b1,c1);}
	if(aeC2[a1][b1-1][c1]==1){aeC2[a1][b1-1][c1]=100;Run1(a1,b1-1,c1);}
	if(aeC2[a1][b1][c1-1]==1){aeC2[a1][b1][c1-1]=100;Run1(a1,b1,c1-1);}
	return 0;
}
int ae(int a,int b,int c,int d){
	d++;
	if(a==9){
	    for(i=0;i<=10;i++){
	    	for(j=0;j<=10;j++){
	    	    for(k=0;k<=10;k++){
	    	        aeC2[i][j][k]=aeC1[i][j][k];
	    	        if(i>=2&j>=2&k>=2&i<=8&j<=8&k<=8){
				    	if(aeC1[i][j][k]>=1&aeC1[i-1][j][k]>=1&aeC1[i+1][j][k]>=1&aeC1[i][j-1][k]>=1&aeC1[i][j+1][k]>=1) aeC2[i][j][k]=2;
    		            if(aeC1[i][j][k]>=1&aeC1[i-1][j][k]>=1&aeC1[i+1][j][k]>=1&aeC1[i][j][k-1]>=1&aeC1[i][j][k+1]>=1) aeC2[i][j][k]=2;
    		            if(aeC1[i][j][k]>=1&aeC1[i][j][k-1]>=1&aeC1[i][j][k+1]>=1&aeC1[i][j-1][k]>=1&aeC1[i][j+1][k]>=1) aeC2[i][j][k]=2;
		            }
				}
		    }
		}
		i=1;j=1;k=1;
		for(i=1;i<=9;i++){
	    	for(j=1;j<=9;j++){
	    	    for(k=1;k<=9;k++){
	    	        if(aeC2[i][j][k]==1)break; 
				}
				if(aeC2[i][j][k]==1)break; 
		    }
		    if(aeC2[i][j][k]==1)break; 
		}
		if(aeC2[i][j][k]==0) return 0;
		Run1(i,j,k);
		for(i=0;i<=10;i++){
	    	for(j=0;j<=10;j++){
	    	    for(k=0;k<=10;k++){
	    	        if(aeC2[i][j][k]!=100)aeC2[i][j][k]=0;
				}
		    }
		}
		Run2(1,1,1);
		for(i=1;i<=9;i++){
	    	for(j=1;j<=9;j++){
	    	    for(k=1;k<=9;k++){
	    	        if(aeC2[i][j][k]!=100&aeC2[i][j][k]!=50) t=t+aeC2[i][j][k];
				}
		    }
		}
		if(t>s){
			s=t;
			for(i=1;i<10;i++){
	    	    for(j=1;j<10;j++){
	    	        for(k=1;k<10;k++){
						aeC3[i][j][k]=aeC2[i][j][k];
			    	}
	    	    }
	    	}
	    cout<<s<<endl;
        for(i=1;i<=9;i++){
    	    for(j=1;j<=9;j++){
	        	for(k=1;k<=9;k++){
	        	    cout<<aeC3[i][j][k]<<' ';
    			}
		    	cout<<endl;
    		}
	    	cout<<endl;
        	}
		}
		t=0;
		for(i=0;i<=10;i++){
	   	    for(j=0;j<=10;j++){
	            for(k=0;k<=10;k++){
					aeC2[i][j][k]=0;
		    	}
	   	    }
	    }
		
	}
	else{
	    aeC1[a][b][c]=1;
        ae(2+(d-d%49)/49,2+(d%49-d%7)/7,2+d%7,d);
        aeC1[a][b][c]=0;
	    ae(2+(d-d%49)/49,2+(d%49-d%7)/7,2+d%7,d);
    }
	return 0;
}
int main(){
    ae(2,2,2,0);
    cout<<s<<endl;
    for(i=2;i<=8;i++){
	    for(j=2;j<=8;j++){
	    	for(k=2;k<=8;k++){
	    	    cout<<aeC3[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
    return 0;
}
