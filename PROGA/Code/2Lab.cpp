#include <stdlib.h> 
#include <iostream>
#include <ctime>
using namespace std;
#define N 15

void recursion_one(){
	int x;
	cin>>x;
	if (x != 0){
		if (x>0) cout<<x<<"   ";
		recursion_one();	

	} 
	
}
void one(){
	cout<<"������� �����:\n";
	//1. ������ � ����������� ������� � ���������� ������������������ ����� ��������������� ������ ����, � ������� �� ����� ������ ������������� �����. 
	//������ �� ������������.
	recursion_one();
	cout<<"\n";
} 

void recursion_two(int * a,int i=0, bool plus=0){
	if (i<N){
		if (plus && a[i]>0){
			cout<<a[i]<<" "; 
		}
		if (!plus && a[i]<0){
			cout<<a[i]<<" "; 
		}
		recursion_two(a,i+1, plus);
	}
	else if (!plus){
		recursion_two(a,0, 1);
	}	
}

void two(){
	int arr[N];
	srand(time(NULL));
	for (int i=0;i<15;i++)
		arr[i]=rand()%100-50;
	
	cout<<"��������� ������:\n";
	for (int i=0;i<15;i++)
		cout<<arr[i]<<"  ";
	cout<<"\n\n\n";
	cout<<"���������:\n";
	recursion_two(arr);

	cout<<"\n";
} 


void recursion_three(int x){
		if (x>0){
			if (x>1)  
				recursion_three(x/2); 
			cout<<(x-(x/2)*2); 
		}
		else cout<"������� ������������� �����";
}


void three(){
	//	3. �������� ����������� ������� ��� �������� ����� �� ���������� ������� ��������� � ��������.
	int x;
	cout<<"������� �����: ";
	cin>>x;
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n����� � 10 �������: "<<x<<"\n����� � 2 �������: ";
	recursion_three(x);
	cout<<endl;

}

main(){ 
	setlocale(LC_ALL, "Russian");
	system("chcp 1251  > text");
    int choice; 
   	cout<<"Input number of task (Number from 1 to 3):"; 
    cin>>choice;
	system("CLS"); 
    if(choice == 1){ 
        one(); 
    } 
    else if(choice == 2){ 
        two(); 
    }
    
    else if(choice == 3){ 
        three(); 
    }
    
system("PAUSE");
return 0; 
}



