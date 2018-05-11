#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int sbp();
int sbk();
int smp();
int smbp();
int smbk();
int smbt();
int srdm();
int main(){
	int sbp();
	int sbk();
	int srdm();
	cout<<">!?!>Zamenit sohranenia?<!?!<\n";
	cout<<"-> Y/N?\n";
	char s;
	cin>>s;
	if((s==89)||(s==121)){
		int smp();
		int smbp();
		int smbk();
		int smbt();
		cout<<"Sohranenia zamenemy\n";
		cout<<"vvedite 0 chtoby viyti\n";
		cin>>s;
	}
	
}
int srdm(){
	FILE *rdmo;
	rdmo=fopen("rdm.txt","w");
	for(int i=0; i<100; i++){
		if((i%10==0)&&(i))fprintf(rdmo,"\n");
		long o=rand()%100;
		fprintf(rdmo,"%2li ",o);
	}
}
int smbt(){
	ofstream mbto("mytank.txt");
	mbto<<"0\n";
}
int smbk(){
	ofstream mbko("mykorlib.txt");
	mbko<<"0\n";
}
int smbp(){
	ofstream mbpo("mypushlb.txt");
	mbpo<<"0\n";
}
int smp(){
	ofstream mpo("lickab.txt");
	mpo<<"Player\n";
	mpo<<"1000\n";
	mpo<<"0\n";
	mpo<<"0\n";
}
int sbk(){
	ofstream bko("korlib.txt");
	bko<<"17\n";
	for(int i=20; i<=100; i+=5){
		bko<<i<<endl;
		bko<<(i*100)<<endl;
	}
}
int sbp(){
	ofstream bpo("pushlb.txt");
	bpo<<"17\n";
	for(int i=4; i<=20; i++){
		bpo<<i<<endl;
		bpo<<(i*200)<<endl;
	}
}