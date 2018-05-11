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
int pmp(){
	ifstream mpli("mypushlb.txt");
	struct k{
		char name[5];
		long sa;
	};
	k mpl[20];
	int pmk;
	mpli>>pmk;
	for(int i=0; i<pmk; i++){
		mpli>>mpl[i].name;
		mpli>>mpl[i].sa;
	}
	while(true){
		int a,b;
		cout<<"****************************\n";
		cout<<"*Menu prosmotra moih pushek*\n";
		cout<<"****************************\n";
		cout<<"->Vvedite interval vvvoda 1-"<<pmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mpl[i].name<<" "<<mpl[i].sa<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int bml(long &mon){
	struct k{
		char name[5];
		long sa;
	};
	k pl[20],mpl[20];
	ifstream pushi("pushlb.txt");
	int pk;
	pushi>>pk;
	for(int i=0; i<pk; i++){
		pushi>>pl[i].name;
		pushi>>pl[i].sa;
	}
	ifstream mpli("mypushlb.txt");
	int pmk;
	mpli>>pmk;
	for(int i=0; i<pmk; i++){
		mpli>>mpl[i].name;
		mpli>>mpl[i].sa;
	}
	while(true){
		int v;
		cout<<"*********************\n";
		cout<<"*Menu pokupki pushki*\n";
		cout<<"*********************\n";
		for(int i=0; i<pk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<pl[i].name<<" "<<pl[i].sa<<"\n";
		}
		cout<<"-----------------------------------------\n";
		
		cout<<"->Vvedite nomer puski chtoby kupit 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
		if(!v)break;
		for(int i=0; i<5; i++)
			mpl[pmk].name[i]=pl[v-1].name[i];
		mpl[pmk].sa=pl[v-1].sa;
		pmk++;
		cout<<">>puska kuplena<<\n";
	}	
	long l=0;
	while(l<pmk-1){
		if(mpl[l].sa>mpl[l+1].sa){ 
			k h;
			for(int i=0; i<5; i++)
				h.name[i]=mpl[l].name[i];
			h.sa=mpl[l].sa;
			for(int i=0; i<5; i++)
				mpl[l].name[i]=mpl[l+1].name[i];
			mpl[l].sa=mpl[l+1].sa; 
			for(int i=0; i<5; i++)
				mpl[l+1].name[i]=h.name[i]; 
			mpl[l+1].sa=h.sa;
			if(l)l--;
		}
		else l++;
	}
	ofstream mplo("mypushlb.txt");
	mplo<<pmk<<"\n";
	for(int i=0; i<pmk; i++){
		mplo<<mpl[i].name<<"\n";
		mplo<<mpl[i].sa<<"\n";
	}	
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
	ifstream mkli("mykorlib.txt");
	struct k{
		char name[5];
		long hp;
	};
	k mkl[20];
	int kmk;
	mkli>>kmk;
	for(int i=0; i<kmk; i++){
		mkli>>mkl[i].name;
		mkli>>mkl[i].hp;
	}
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
			cout<<"|"<<(i+1)<<"| "<<mkl[i].name<<" "<<mkl[i].hp<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int bmk(long &mon){
	struct k{
		char name[5];
		long hp;
	};
	k kl[20],mkl[20];
	ifstream kori("korlib.txt");
	int kk;
	kori>>kk;
	for(int i=0; i<kk; i++){
		kori>>kl[i].name;
		kori>>kl[i].hp;
	}
	ifstream mkli("mykorlib.txt");
	int kmk;
	mkli>>kmk;
	for(int i=0; i<kmk; i++){
		mkli>>mkl[i].name;
		mkli>>mkl[i].hp;
	}
	while(true){
		int v;
		cout<<"***********************\n";
		cout<<"*Menu pokupki korpusov*\n";
		cout<<"***********************\n";
		for(int i=0; i<kk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<kl[i].name<<" "<<kl[i].hp<<"\n";
		}
		cout<<"-----------------------------------------\n";
		
		cout<<"->Vvedite nomer korpusa chtoby kupit 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
		if(!v)break;
		for(int i=0; i<5; i++)
			mkl[kmk].name[i]=kl[v-1].name[i];
		mkl[kmk].hp=kl[v-1].hp;
		kmk++;
		cout<<">>korpus kuplen<<\n";
	}	
	long l=0;
	while(l<kmk-1){
		if(mkl[l].hp>mkl[l+1].hp){ 
			k h;
			for(int i=0; i<5; i++)
				h.name[i]=mkl[l].name[i];
			h.hp=mkl[l].hp;
			for(int i=0; i<5; i++)
				mkl[l].name[i]=mkl[l+1].name[i];
			mkl[l].hp=mkl[l+1].hp; 
			for(int i=0; i<5; i++)
				mkl[l+1].name[i]=h.name[i]; 
			mkl[l+1].hp=h.hp;
			if(l)l--;
		}
		else l++;
	}
	ofstream mklo("mykorlib.txt");
	mklo<<kmk<<"\n";
	for(int i=0; i<kmk; i++){
		mklo<<mkl[i].name<<"\n";
		mklo<<mkl[i].hp<<"\n";
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
	ifstream kori("korlib.txt");
	struct k{
		char name[5];
		long hp;
	};
	k kl[20];
	int kk;
	kori>>kk;
	for(int i=0; i<kk; i++){
		kori>>kl[i].name;
		kori>>kl[i].hp;
	}
	while(true){
		int a,b;
		cout<<"*************************\n";
		cout<<"*Menu prosmotra korpusov*\n";
		cout<<"*************************\n";
		cout<<"->Vvedite interval vvvoda 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<kl[i].name<<" "<<kl[i].hp<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int pbp(){
	ifstream pushi("pushlb.txt");
	struct k{
		char name[5];
		long sa;
	};
	k pl[20];
	int pk;
	pushi>>pk;
	for(int i=0; i<pk; i++){
		pushi>>pl[i].name;
		pushi>>pl[i].sa;
	}
	while(true){
		int a,b;
		cout<<"***********************\n";
		cout<<"*Menu prosmotra pushek*\n";
		cout<<"***********************\n";
		cout<<"->Vvedite interval vvvoda 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<pl[i].name<<" "<<pl[i].sa<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int dvb(int v){
	if(v==1)bk();
	if(v==2)bp();
}
int bk(){
	ifstream kori("korlib.txt");
	struct k{
		char name[5];
		long hp;
	};
	k kl[20];
	int kk;
	kori>>kk;
	for(int i=0; i<kk; i++){
		kori>>kl[i].name;
		kori>>kl[i].hp;
	}
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
			cout<<"->>vvedite nazvanie(4 simvola)\n";
			cin>>kl[kk].name;
			cout<<"->>vvedite zdorovie\n";
			cin>>kl[kk].hp;
			kk++;
			cout<<">>korpus dobavlen<<\n";
		}
		if(v==2){
			int delk;
			for(int i=0; i<kk; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<kl[i].name<<" "<<kl[i].hp<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"vvedite nomer korpusa na udalenie 1-"<<kk<<"\n";
			cin>>delk;
			for(int i=delk; i<kk; i++){
				for(int l=0; l<5; l++)
					kl[i-1].name[l]=kl[i].name[l];
				kl[i-1].hp=kl[i].hp;
			}
			kk--;
			cout<<">>korpus udalen<<\n";
		}
		if(!v)break;
	}
	long l=0;
	while(l<kk-1){
		if(kl[l].hp>kl[l+1].hp){ 
			k h;
			for(int i=0; i<5; i++)
				h.name[i]=kl[l].name[i];
			h.hp=kl[l].hp;
			for(int i=0; i<5; i++)
				kl[l].name[i]=kl[l+1].name[i];
			kl[l].hp=kl[l+1].hp; 
			for(int i=0; i<5; i++)
				kl[l+1].name[i]=h.name[i]; 
			kl[l+1].hp=h.hp;
			if(l)l--;
		}
		else l++;
	}
	ofstream koro("korlib.txt");
	koro<<kk<<"\n";
	for(int i=0; i<kk; i++){
		koro<<kl[i].name<<"\n";
		koro<<kl[i].hp<<"\n";
	}
}
int bp(){   
	ifstream pushi("pushlb.txt");
	struct k{
		char name[5];
		long sa;
	};
	k pl[20];
	int pk;
	pushi>>pk;
	for(int i=0; i<pk; i++){
		pushi>>pl[i].name;
		pushi>>pl[i].sa;
	}
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
			cout<<"->>vvedite nazvanie(4 simvola)\n";
			cin>>pl[pk].name;
			cout<<"->>vvedite silu attaki\n";
			cin>>pl[pk].sa;
			pk++;
			cout<<">>pushka dobavlena<<\n";
		}
		if(v==2){
			int delk;
			for(int i=0; i<pk; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<pl[i].name<<" "<<pl[i].sa<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"vvedite nomer pushki na udalenie 1-"<<pk<<"\n";
			cin>>delk;
			for(int i=delk; i<pk; i++){
				for(int l=0; l<5; l++)
					pl[i-1].name[l]=pl[i].name[l];
				pl[i-1].sa=pl[i].sa;
			}
			pk--;
			cout<<">>pushka udalena<<\n";
		}
		if(!v)break;
	}
	long l=0;
	while(l<pk-1){
		if(pl[l].sa>pl[l+1].sa){ 
			k h;
			for(int i=0; i<5; i++)
				h.name[i]=pl[l].name[i];
			h.sa=pl[l].sa;
			for(int i=0; i<5; i++)
				pl[l].name[i]=pl[l+1].name[i];
			pl[l].sa=pl[l+1].sa; 
			for(int i=0; i<5; i++)
				pl[l+1].name[i]=h.name[i]; 
			pl[l+1].sa=h.sa;
			if(l)l--;
		}
		else l++;
	}
	ofstream pusho("pushlb.txt");
	pusho<<pk<<"\n";
	for(int i=0; i<pk; i++){
		pusho<<pl[i].name<<"\n";
		pusho<<pl[i].sa<<"\n";
	}
}