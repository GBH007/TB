#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int main(){
	ofstream bpo("pushlb.txt");
	bpo<<"17\n";
	for(int i=4; i<=20; i++){
		bpo<<i<<endl;
		bpo<<(i*200)<<endl;
	}
	ofstream bko("korlib.txt");
	bko<<"17\n";
	for(int i=20; i<=100; i+=5){
		bko<<i<<endl;
		bko<<(i*100)<<endl;
	}
	FILE *rdmo;
	rdmo=fopen("rdm.txt","w");
	for(int i=0; i<100; i++){
		if((i%10==0)&&(i))fprintf(rdmo,"\n");
		long o=rand()%100;
		fprintf(rdmo,"%2li ",o);
	}
	cout<<">!?!>Zamenit sohranenia?<!?!<\n";
	cout<<"-> Y/N?\n";
	char s;
	cin>>s;
	if((s==89)||(s==121)){
		ofstream mpo("lickab.txt");
		mpo<<"Player\n";
		mpo<<"1000\n";
		mpo<<"0\n";
		mpo<<"0\n";
		ofstream mbpo("mypushlb.txt");
		mbpo<<"0\n";
		ofstream mbko("mykorlib.txt");
		mbko<<"0\n";
		ofstream mbto("mytank.txt");
		mbto<<"1\n";
		mbto<<"4\n";
		mbto<<"20\n";
		mbto<<"800\n";
		mbto<<"2000\n";
		cout<<"Sohranenia zamenemy\n";
		cout<<"vvedite 0 chtoby viyti\n";
		cin>>s;
	}

}
