#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
int dvb(int v);
int bk();
int bp();
int pbk();
int pbp();
int lib();
int oru();
int mag();
int pmk();
int pmp();
int bmk(long &mon);
int bml(long &mon);
int kupkor(long &mon);
int kuppush(long &mon);
int smpl(int *mpl, int &pmk);
int spl(int *pl, int &pk);
int dmpl(int *mpl, int &pmk);
int dpl(int *pl, int &pk);
int smkl(int *mkl, int &kmk);
int skl(int *kl, int &kk);
int dmkl(int *mkl, int &kmk);
int dkl(int *kl, int &kk);
int main(){
	int vybor=1;
	while(vybor){
		cout<<"*************\n";
		cout<<"*TANK*BATTLE*\n";
		cout<<"*************\n";
		cout<<"   *V-0.1*   \n";
		cout<<"   *******   \n";
		cout<<"<-1-> biblioteka\n";
		cout<<"<-2-> orugeinai\n";
		cout<<"<-3-> magazine\n";
		cout<<"<-0-> vyiti\n";
		cin>>vybor;
		if(vybor==1)lib();
		if(vybor==2)oru();
		if(vybor==3)mag();
		if(!vybor)break;
	}
}
int smpl(int *mpl, int &pmk){
	ifstream mpli("mypushlb.txt");
	mpli>>pmk;
	for(int i=0; i<pmk; i++){
		mpli>>mpl[i];
	}
}
int spl(int *pl, int &pk){
	ifstream pushi("pushlb.txt");
	pushi>>pk;
	for(int i=0; i<pk; i++){
		pushi>>pl[i];
	}
}
int dmpl(int *mpl, int &pmk){
	long l=0;
	while(l<pmk-1){
		if(mpl[l]>mpl[l+1]){ 
			int h;
			h=mpl[l];
			mpl[l]=mpl[l+1];  
			mpl[l+1]=h;
			if(l)l--;
		}
		else l++;
	}
	ofstream mplo("mypushlb.txt");
	mplo<<pmk<<"\n";
	for(int i=0; i<pmk; i++){
		mplo<<mpl[i]<<"\n";
	}
}
int dpl(int *pl, int &pk){
	long l=0;
	while(l<pk-1){
		if(pl[l]>pl[l+1]){ 
			int h;
			h=pl[l];
			pl[l]=pl[l+1];  
			pl[l+1]=h;
			if(l)l--;
		}
		else l++;
	}
	ofstream plo("pushlb.txt");
	plo<<pk<<"\n";
	for(int i=0; i<pk; i++){
		plo<<pl[i]<<"\n";
	}
}
int smkl(int *mkl, int &kmk){
	ifstream mkli("mykorlib.txt");
	mkli>>kmk;
	for(int i=0; i<kmk; i++){
		mkli>>mkl[i];
	}
}
int skl(int *kl, int &kk){
	ifstream kori("korlib.txt");
	kori>>kk;
	for(int i=0; i<kk; i++){
		kori>>kl[i];
	}
}
int dmkl(int *mkl, int &kmk){
	long l=0;
	while(l<kmk-1){
		if(mkl[l]>mkl[l+1]){ 
			int h;
			h=mkl[l];
			mkl[l]=mkl[l+1];  
			mkl[l+1]=h;
			if(l)l--;
		}
		else l++;
	}
	ofstream mklo("mykorlib.txt");
	mklo<<kmk<<"\n";
	for(int i=0; i<kmk; i++){
		mklo<<mkl[i]<<"\n";
	}
}
int dkl(int *kl, int &kk){
	long l=0;
	while(l<kk-1){
		if(kl[l]>kl[l+1]){ 
			int h;
			h=kl[l];
			kl[l]=kl[l+1];  
			kl[l+1]=h;
			if(l)l--;
		}
		else l++;
	}
	ofstream klo("korlib.txt");
	klo<<kk<<"\n";
	for(int i=0; i<kk; i++){
		klo<<kl[i]<<"\n";
	}
}
int pmp(){
	int mpl[200],pmk;
	smpl(mpl,pmk);
	while(true){
		int a,b;
		cout<<"****************************\n";
		cout<<"*Menu prosmotra moih pushek*\n";
		cout<<"****************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<pmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mpl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int bml(long &mon){
	int pl[200],mpl[200],pk,pmk;
	spl(pl,pk);
	smpl(mpl,pmk);
	while(true){
		int v;
		cout<<"*********************\n";
		cout<<"*Menu pokupki pushki*\n";
		cout<<"*********************\n";
		for(int i=0; i<pk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<pl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		
		cout<<"->Vvedite nomer puski chtoby kupit 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
		if(!v)break;
		mpl[pmk]=pl[v-1];
		pmk++;
		cout<<">>puska kuplena<<\n";
	}	
	dmpl(mpl,pmk);	
}
int kuppush(long &mon){
	int v=1;
	while(v){
		cout<<"***************\n";
		cout<<"*pokupka puski*\n";
		cout<<"***************\n";
		cout<<"\n---------------------------------\nNa schetu | ";
		cout<<mon;
		cout<<"\n---------------------------------\n";
		cout<<"1) kupit pusku\n";
		cout<<"0) vyiti\n";
		cin>>v;
		if(v==1)bml(mon);
		if(!v)break;
	}
}
int pmk(){
	int mkl[200],kmk;
	smkl(mkl,kmk);
	while(true){
		int a,b;
		cout<<"******************************\n";
		cout<<"*Menu prosmotra moih korpusov*\n";
		cout<<"******************************\n";
		cout<<"->Vvedite interval vvvoda 1-"<<kmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mkl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int bmk(long &mon){
	int kl[200],mkl[200],kk,kmk;
	smkl(mkl,kmk);
	skl(kl,kk);
	while(true){
		int v;
		cout<<"***********************\n";
		cout<<"*Menu pokupki korpusov*\n";
		cout<<"***********************\n";
		for(int i=0; i<kk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<kl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		
		cout<<"->Vvedite nomer korpusa chtoby kupit 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
		if(!v)break;
		mkl[kmk]=kl[v-1];
		kmk++;
		cout<<">>korpus kuplen<<\n";
	}	
	dmkl(mkl,kmk);
}
int kupkor(long &mon){
	int v=1;
	while(v){
		cout<<"*****************\n";
		cout<<"*pokupka korpusa*\n";
		cout<<"*****************\n";
		cout<<"\n---------------------------------\nNa schetu | ";
		cout<<mon;
		cout<<"\n---------------------------------\n";
		cout<<"1) kupit korpus\n";
		cout<<"0) vyiti\n";
		cin>>v;
		if(v==1)bmk(mon);
		if(!v)break;
	}
}
int mag(){
	int v=1;
	while(v){
		cout<<"**********\n";
		cout<<"*magazine*\n";
		cout<<"**********\n";	
		ifstream lk("lickab.txt");
		char nick[30];
		long mon;
		lk>>nick>>mon;
		cout<<"\n------------------------------------------\n ";
		cout<<nick;
		cout<<"\n------------------------------------------\n ";
		cout<<mon;
		cout<<"\n------------------------------------------\n\n";
		cout<<"$-1-$ kupit korpus\n";
		cout<<"$-2-$ kupit pushku\n";
		//cout<<"$-3-$ kupit tank\n";          ???
		cout<<"$-0-$ vyiti\n";
		cin>>v;
		if(v==1)kupkor(mon);
		if(v==2)kuppush(mon);
		if(!v)break;
	}
}
int oru(){
	int v=1;
	while(v){
		cout<<"***********\n";
		cout<<"*orugeinai*\n";
		cout<<"***********\n";	
		ifstream lk("lickab.txt");
		char nick[30];
		long pob,por;
		lk>>nick>>pob>>pob>>por;
		cout<<"\n------------------------------------------\nNik  | ";
		cout<<nick;
		cout<<"\n------------------------------------------\nWin  | ";
		cout<<pob;
		cout<<"\n------------------------------------------\nLose | ";
		cout<<por;
		cout<<"\n------------------------------------------\n\n";
		cout<<"=1= moi korpusa\n";
		cout<<"=2= moi pushki\n";
		//cout<<"=3= moi tanki\n";
		cout<<"=0= vyiti\n";
		cin>>v;
		if(v==1)pmk();
		if(v==2)pmp();
		if(!v)break;
	}
}
int lib(){
	int v=1;
	while(v){
		cout<<"*****************\n";
		cout<<"*menu biblioteka*\n";
		cout<<"*****************\n";
		cout<<"1)dobavit faily v biblioteku kor\n";
		cout<<"2)dobavit faily v biblioteku push\n";
		cout<<"3)posmotret faily v biblioteke kor\n";
		cout<<"4)posmotret faily v biblioteke push\n";
		cout<<"0)vyiti\n";
		cin>>v;
		if(v==1)dvb(v);
		if(v==2)dvb(v);
		if(v==3)pbk();
		if(v==4)pbp();
		if(!v)break;
	}
}
int pbk(){
	int kl[200],kk;
	skl(kl,kk);
	while(true){
		int a,b;
		cout<<"*************************\n";
		cout<<"*Menu prosmotra korpusov*\n";
		cout<<"*************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<kl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int pbp(){
	int pl[200],pk;
	spl(pl,pk);
	while(true){
		int a,b;
		cout<<"***********************\n";
		cout<<"*Menu prosmotra pushek*\n";
		cout<<"***********************\n";
		cout<<"->Vvedite interval vvoda 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<pl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int dvb(int v){
	if(v==1)bk();
	if(v==2)bp();
}
int bk(){
	int kl[200],kk;
	skl(kl,kk);
	int v=1;
	while(v){
		cout<<"*******************************\n";
		cout<<"*Menu dobavit v biblioteky kor*\n";
		cout<<"*******************************\n";
		cout<<"1)dobavit korpus\n";
		cout<<"2)udalit korpus\n";
		cout<<"0)Vyiti\n";
		cin>>v;
		if(v==1){
			//cout<<"->>vvedite nazvanie(4 simvola)\n";
			//cin>>kl[kk].name;
			cout<<"->>vvedite zdorovie\n";
			cin>>kl[kk];
			kk++;
			cout<<">>korpus dobavlen<<\n";
		}
		if(v==2){
			int delk;
			for(int i=0; i<kk; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<kl[i]<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"->vvedite nomer korpusa na udalenie 1-"<<kk<<"\n";
			cout<<"->Ili 0 chtoby vyiti\n";
			cin>>delk;
			if(!delk)break;
			for(int i=delk; i<kk; i++){
				kl[i-1]=kl[i];
			}
			kk--;
			cout<<">>korpus udalen<<\n";
		}
		if(!v)break;
	}
	dkl(kl,kk);
}
int bp(){
	int pl[200],pk;
	spl(pl,pk);
	int v=1;
	while(v){
		cout<<"********************************\n";
		cout<<"*Menu dobavit v biblioteky push*\n";
		cout<<"********************************\n";
		cout<<"1)dobavit pushku\n";
		cout<<"2)udalit pushku\n";
		cout<<"0)Vyiti\n";
		cin>>v;
		if(v==1){
			//cout<<"->>vvedite nazvanie(4 simvola)\n";
			//cin>>pl[pk].name;
			cout<<"->>vvedite silu attaki\n";
			cin>>pl[pk];
			pk++;
			cout<<">>pushka dobavlena<<\n";
		}
		if(v==2){
			int delk;
			for(int i=0; i<pk; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<pl[i]<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"->vvedite nomer pushki na udalenie 1-"<<pk<<"\n";
			cout<<"->Ili 0 chtoby vyiti\n";
			cin>>delk;
			if(!delk)break;
			for(int i=delk; i<pk; i++){
				pl[i-1]=pl[i];
			}
			pk--;
			cout<<">>pushka udalena<<\n";
		}
		if(!v)break;
	}
	dpl(pl,pk);
}