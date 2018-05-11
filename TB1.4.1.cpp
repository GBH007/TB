#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const long n=200;
int adm();
int bk();
int bp();
int bmt();
int pbk();
int pbp();
int lib();
int oru();
int sozmt();
int razmt();
int mag();
int pmk();
int pmp();
int pmt();
int bmk(long &mon);
int bml(long &mon);
int kupkor(long &mon);
int kuppush(long &mon);
int slc(char *name, long &mon,long &win,long &lose);
int dlc(char *name, long &mon,long &win,long &lose);
int smpl(long *mpl,long *cmp, long &pmk);
int spl(long *pl,long *cp, long &pk);
int dmpl(long *mpl,long *cmp, long &pmk);
int dpl(long *pl,long *cp, long &pk);
int smkl(long *mkl,long *cmk, long &kmk);
int skl(long *kl,long *ck, long &kk);
int dmkl(long *mkl,long *cmk, long &kmk);
int dkl(long *kl,long *ck, long &kk);
int smtl(long *mtl, long *mtl1, long *cmpt,long *cmkt, long &kmt);
int dmtl(long *mtl, long *mtl1, long *cmpt,long *cmkt, long &kmt);
int mpmk(long &mon);
int mpmp(long &mon);
int titry();
int menb1();//!!!
int boi();//!!!
int bois(long &sa, long &hp);//!!
int war(long &sa,long &hp,long &sav,long &hpv,long &mon,long &win,long &lose);//!!
int smen();//11111111
int main(){
	long vybor=1;
	while(vybor){
		cout<<"<*************>\n";
		cout<<"<*TANK*BATTLE*>\n";
		cout<<"<*************>\n";
		cout<<"   *V-1.4.1*   \n";
		cout<<"   *********   \n";
		cout<<"<-1-> orugeinai\n";
		cout<<"<-2-> magazine\n";
		cout<<"<-3-> titry\n";
		cout<<"<-4-> boi\n";//!!!!
		cout<<"<-5-> smena nika\n";//11111
		cout<<"<-0-> vyiti\n";
		char buf[30];
		cin>>buf;
		vybor=atoi(buf);
		//cin>>vybor;
		if(vybor==404)lib();
		if(vybor==1)oru();
		if(vybor==2)mag();
		if(vybor==3)titry();
		if(vybor==4)menb1();//!!!
		if(vybor==5)smen();//111
		if(!vybor){titry(); break;}
	}
}
int smen(){//11111
	char name[30];
	long mon,win,lose,v,hpv;
	slc(name,mon,win,lose);
	v=1;
	while(v){
		cout<<"************\n";
		cout<<"*smenit nik*\n";
		cout<<"************\n";
		cout<<"tekushii nik  "<<name<<"\n";
		cout<<"->1 prodolgit\n";
		cout<<"->0 vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(!v)break;
		else{
			cout<<"->>Vvedite novyi nik\n";
			cin>>name;
		}
	}
	dlc(name,mon,win,lose);
	return 0;
}
int war(long &sa,long &hp,long &sav,long &hpv,long &mon,long &win,long &lose){//!!!
	cout<<"-------------------------------\n";
	cout<<"|          menu boia          |\n";
	cout<<"-------------------------------\n";
	cout<<"-------------------------------\n";
	cout<<"-------------------------------\n";
	cout<<"|      boi nachinetsia        |\n";
	cout<<"-------------------------------\n";
	cout<<"-------------------------------\n";
	long a,b,c,d;
	a=hp;
	b=sa;
	c=hpv;
	d=sav;
	srand(time(0));
	while(true){
		long r,ma,va,hod;
		//rdm(r);
	        r=rand();
		ma=b*(r%3);
		cout<<"PC teriaet "<<ma<<"hp\n";
		if(ma/b==2)cout<<"VOT ETO KRIT!!!!!!!!\n";
		cout<<"-------------------------------\n";
		c-=ma;
		if(c<1){cout<<"Ty pobedil!\n"; win++; mon+=hpv*60/hp; break;}
		//rdm(r);
		r=rand();
		va=d*(r%3);
		cout<<"igrock teriaet "<<va<<"hp\n";
		if(va/d==2)cout<<"VOT ETO KRIT!!!!!!!!\n";
		cout<<"-------------------------------\n";
		a-=va;
		if(a<1){cout<<"Ty proigral!\n"; lose++; break;}
	}
}
int bois(long &sa, long &hp){//!!!
	char name[30];
	long mon,win,lose,v,hpv,sav;
	slc(name,mon,win,lose);
	v=1;
	while(v){
		cout<<"******************\n";
		cout<<"*Vybor protivnica*\n";
		cout<<"******************\n";
		cout<<"------------------------------------------------\n";
		cout<<"|    uroven   | zdorove | sila ataki | nagrada |\n";
		cout<<"------------------------------------------------\n";
		printf("|1) legkii    |   %3li   |     %2li     |   %3li   |\n",(hp-5),(sa-1),((hp-5)*60/hp));
		cout<<"------------------------------------------------\n";
		printf("|2) srednij   |   %3li   |     %2li     |   %3li   |\n",hp,sa,(hp*60/hp));
		cout<<"------------------------------------------------\n";
		printf("|3) tiageliy  |   %3li   |     %2li     |   %3li   |\n",(hp+5),(sa+1),((hp+5)*60/hp));
		cout<<"------------------------------------------------\n";
		printf("|4) ADMINamin |   100   |     20     |   %3li   |\n",(100*60/hp));
		cout<<"------------------------------------------------\n";
		cout<<"|0) exit                                       |\n";
		cout<<"------------------------------------------------\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);		
		//cin>>v;
		if(!v)break;
		if(v==1){sav=sa-1; hpv=hp-5;}
		if(v==2){sav=sa; hpv=hp;}
		if(v==3){sav=sa+1; hpv=hp+5;}
		if(v==4){sav=20; hpv=100;}
		war(sa,hp,sav,hpv,mon,win,lose);
	}
	dlc(name,mon,win,lose);
}
int boit(){//!!!
	long mtl[n],mtl1[n],kmt,cmpt[n],cmkt[n];
	smtl(mtl,mtl1,cmpt,cmkt,kmt);
	while(true){
		long a,b;
		cout<<"******************\n";
		cout<<"*Menu VYBOR tanka*\n";
		cout<<"******************\n";
		cout<<"----------------------------------\n";
		cout<<"| nomer | sila ataki |  zdorove  |\n";
		for(long i=0; i<kmt; i++){
			cout<<"----------------------------------\n";
			printf("| %5li | %10li | %9li |\n",(i+1),mtl[i],mtl1[i]);
		}
		cout<<"----------------------------------\n";
		cout<<"->Vvedite nomer tanka dlia boia 1-"<<kmt<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		a=atoi(buf);		
		//cin>>a;
		if((a>0)&&(a<=kmt)){bois(mtl[a-1],mtl1[a-1]);}
		else break;
	}
}
int menb1(){//!!
	cout<<"***********\n";
	cout<<"*menu boia*\n";
	cout<<"***********\n";
	cout<<"1) vstupit v boi\n";
	cout<<"0) vyiti\n";
	int v;
	char buf[30];
	cin>>buf;
	v=atoi(buf);
	//cin>>v;
	if(v==1)boit();
}
int titry(){
	cout<<"\n\n";
	cout<<"==================================\n";
	cout<<"| Avtor        | GBH007          |\n";
	cout<<"==================================\n";
	cout<<"      |                    |      \n";
	cout<<"==================================\n";
	cout<<"| Ideia        | GBH007 | I Stas |\n";
	cout<<"==================================\n";
	cout<<"      |                    |      \n";
	cout<<"==================================\n";
	cout<<"| Programmisty | GBH007          |\n";
	cout<<"==================================\n";
	cout<<"      |                    |      \n";
	cout<<"==================================\n";
	cout<<"| Beta-testery | I Stas          |\n";
	cout<<"==================================\n";
	cout<<"      |                    |      \n";
	cout<<"==================================\n";
	cout<<"|     20.12.2011-13.01.2012      |\n";
	cout<<"==================================\n";
	cout<<"\n\n";
	char a[30];
	cout<<"Vvedite 0 chtoby vyiti\n";
	cin>>a;
}
int mpmp(long &mon){
	long mpl[n],cmp[n],pmk,v;
	smpl(mpl,cmp,pmk);
	v=1;
	while(v){
		cout<<"*********************\n";
		cout<<"*Menu prodagi pushek*\n";
		cout<<"*********************\n";
		cout<<"----------------------------------\n";
		cout<<"| nomer | sila ataki |  stoimost |\n";
		for(long i=0; i<pmk; i++){
			cout<<"----------------------------------\n";
			printf("| %5li | %10li | %9li |\n",(i+1),mpl[i],cmp[i]);
		}
		cout<<"----------------------------------\n";
		cout<<"->Vvedite nomer pushki chtoby prodat 1-"<<pmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if((v<1)||(v>pmk))break;
		mon+=cmp[v-1];
		for(long i=v; i<pmk; i++){
			mpl[i-1]=mpl[i];
			cmp[i-1]=cmp[i];
		}
		pmk--;
		cout<<">>pushka prodana<<\n";
	}
	dmpl(mpl,cmp,pmk);
}
int mpmk(long &mon){
	long mkl[n],cmk[n],kmk,v;
	smkl(mkl,cmk,kmk);
	v=1;
	while(v){
		cout<<"**********************\n";
		cout<<"*Menu prodagi korpusa*\n";
		cout<<"**********************\n";
		cout<<"----------------------------------\n";
		cout<<"| nomer |   zdorove  |  stoimost |\n";
		for(long i=0; i<kmk; i++){
			cout<<"----------------------------------\n";
			printf("| %5li | %10li | %9li |\n",(i+1),mkl[i],cmk[i]);
		}
		cout<<"----------------------------------\n";
		cout<<"->Vvedite nomer korpusa chtoby prodat 1-"<<kmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if((v<1)||(v>kmk))break;
		mon+=cmk[v-1];
		for(long i=v; i<kmk; i++){
			mkl[i-1]=mkl[i];
			cmk[i-1]=cmk[i];
		}
		kmk--;
		cout<<">>korpus prodan<<\n";
	}
	dmkl(mkl,cmk,kmk);
}
int slc(char *name, long &mon,long &win,long &lose){
	ifstream slci("lickab.txt");
	slci>>name>>mon>>win>>lose;
	if(mon/100000>0)mon=99999;
	else mon%=100000;
}
int dlc(char *name, long &mon,long &win,long &lose){
	ofstream dlco("lickab.txt");
	dlco<<name<<endl<<mon<<endl<<win<<endl<<lose;
	if(mon/100000>0)mon=99999;
	else mon%=100000;
}
int razmt(){
	long mtl[n],mtl1[n],kmt,mpl[n],pmk,mkl[n],kmk,cmpt[n],cmkt[n],cmp[n],cmk[n];
	smtl(mtl,mtl1,cmpt,cmkt,kmt);
	smpl(mpl,cmp,pmk);
	smkl(mkl,cmk,kmk);
	while(true){
		int v;
		cout<<"**************************\n";
		cout<<"*Menu razbora moih tankov*\n";
		cout<<"**************************\n";
		cout<<"1) razobrat tank\n";
		cout<<"0) vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1){
			cout<<"----------------------------------\n";
			cout<<"| nomer | sila ataki |  zdorove  |\n";
			for(long i=0; i<kmt; i++){
				cout<<"----------------------------------\n";
				printf("| %5li | %10li | %9li |\n",(i+1),mtl[i],mtl1[i]);
			}
			cout<<"----------------------------------\n";
			cout<<"->vvedite nomer tanka\n";
			cout<<"-> ili 0 chtoby vyiti\n";
			long q;
			cin>>buf;
			q=atol(buf);
			if((q<1)||(q>kmt))break;
			mpl[pmk]=mtl[q-1];
			cmp[pmk]=cmpt[q-1];
			pmk++;
			mkl[kmk]=mtl1[q-1];
			cmk[kmk]=cmkt[q-1];
			kmk++;
			for(long i=q; i<kmt; i++){
				mtl[i-1]=mtl[i];
				mtl1[i-1]=mtl1[i];
				cmpt[i-1]=cmpt[i];
				cmkt[i-1]=cmkt[i];
			}
			kmt--;
			cout<<">>tank razobran<<\n";
		}
		if(!v)break;
	}
	dmtl(mtl,mtl1,cmpt,cmkt,kmt);
	dmpl(mpl,cmp,pmk);
	dmkl(mkl,cmk,kmk);
}
int sozmt(){
	long mtl[n],mtl1[n],kmt,mpl[n],pmk,mkl[n],kmk,cmpt[n],cmkt[n],cmp[n],cmk[n];
	smtl(mtl,mtl1,cmpt,cmkt,kmt);
	smpl(mpl,cmp,pmk);
	smkl(mkl,cmk,kmk);
	while(true){
		int v;
		cout<<"****************************\n";
		cout<<"*Menu sozdaniai moih tankov*\n";
		cout<<"****************************\n";
		cout<<"1) sozdat tank\n";
		cout<<"0) vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1){
			cout<<"----------------------\n";
			cout<<"| nomer | sila ataki |\n";
			cout<<"----------------------\n";
			for(long i=0; i<pmk; i++){
				printf("| %5li | %10li |\n",(i+1),mpl[i]);
				cout<<"----------------------\n";
			}
			cout<<"->>vvedite nomer puski dlai tanka\n";
			cout<<"->>ili 0 chtoby vyiti\n";
			long vub,vub1;
			cin>>buf;
			vub=atol(buf);
			if((vub<1)||(vub>pmk))break;
			cout<<"---------------------\n";
			cout<<"| nomer |  zdorove  |\n";
			cout<<"---------------------\n";
			for(long i=0; i<kmk; i++){
				printf("| %5li | %9li |\n",(i+1),mkl[i]);
			cout<<"---------------------\n";
			}
			cout<<"->>vvedite nomer korpusa dlai tanka\n";
			cin>>buf;
			vub1=atol(buf);
			if((vub1<1)||(vub1>kmk))break;
			mtl[kmt]=mpl[vub-1];
			cmpt[kmt]=cmp[vub-1];
			for(long i=vub; i<pmk; i++){
				mpl[i-1]=mpl[i];
				cmp[i-1]=cmp[i];
			}
			pmk--;
			mtl1[kmt]=mkl[vub1-1];
			cmkt[kmt]=cmk[vub1-1];
			for(long i=vub; i<kmk; i++){
				mkl[i-1]=mkl[i];
				cmk[i-1]=cmk[i];
			}
			kmk--;
			kmt++;
			cout<<">>tank sozdan<<\n";
		}
		if(!v)break;
	}
	dmtl(mtl,mtl1,cmpt,cmkt,kmt);
	dmpl(mpl,cmp,pmk);
	dmkl(mkl,cmk,kmk);
}
int pmt(){
	long mtl[n],mtl1[n],kmt,cmpt[n],cmkt[n];
	smtl(mtl,mtl1,cmpt,cmkt,kmt);
	while(true){
		long a,b;
		cout<<"****************************\n";
		cout<<"*Menu prosmotra moih tankov*\n";
		cout<<"****************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<kmt<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		a=atol(buf);
		//cin>>a;
		if(!a)break;
		cin>>buf;
		b=atol(buf);
		if((a<1)||(a>kmt))break;
		if((b<1)||(b>kmt))break;
		a--;
		cout<<"----------------------------------\n";
		cout<<"| nomer | sila ataki |  zdorove  |\n";
		for(long i=a; i<b; i++){
			cout<<"----------------------------------\n";
			printf("| %5li | %10li | %9li |\n",(i+1),mtl[i],mtl1[i]);
		}
		cout<<"----------------------------------\n";
	}
}
int dmtl(long *mtl, long *mtl1,long *cmpt,long *cmkt, long &kmt){
	long l=0;
	while(l<kmt-1){
		if(mtl[l]>mtl[l+1]){
			long h,h1,h2,h3;
			h=mtl[l];
			mtl[l]=mtl[l+1];
			mtl[l+1]=h;
			h1=mtl1[l];
			mtl1[l]=mtl1[l+1];
			mtl1[l+1]=h1;
			h2=cmpt[l];
			cmpt[l]=cmpt[l+1];
			cmpt[l+1]=h2;
			h3=cmkt[l];
			cmkt[l]=cmkt[l+1];
			cmkt[l+1]=h3;
			if(l)l--;
		}
		else l++;
	}
	ofstream mtlo("mytank.txt");
	mtlo<<kmt<<"\n";
	for(long i=0; i<kmt; i++){
		mtlo<<mtl[i]<<"\n";
		mtlo<<mtl1[i]<<"\n";
		mtlo<<cmpt[i]<<"\n";
		mtlo<<cmkt[i]<<"\n";
	}
}
int smtl(long *mtl, long *mtl1,long *cmpt,long *cmkt, long &kmt){
	ifstream mtli("mytank.txt");
	mtli>>kmt;
	for(long i=0; i<kmt; i++){
		mtli>>mtl[i];
		mtli>>mtl1[i];
		mtli>>cmpt[i];
		mtli>>cmkt[i];
	}
}
int bmt(){
	int v=1;
	while(v){
		cout<<"***********\n";
		cout<<"*moi tanki*\n";
		cout<<"***********\n";
		cout<<"*1* posmotret moi tanki\n";
		cout<<"*2* sozdat novyi tank\n";
		cout<<"*3* razobrat tank\n";
		cout<<"*0* vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1)pmt();
		if(v==2)sozmt();
		if(v==3)razmt();
		if(!v)break;
	}
}
int smpl(long *mpl,long *cmp, long &pmk){
	ifstream mpli("mypushlb.txt");
	mpli>>pmk;
	for(long i=0; i<pmk; i++){
		mpli>>mpl[i];
		mpli>>cmp[i];
	}
}
int spl(long *pl,long *cp, long &pk){
	ifstream pushi("pushlb.txt");
	pushi>>pk;
	for(long i=0; i<pk; i++){
		pushi>>pl[i];
		pushi>>cp[i];
	}
}
int dmpl(long *mpl,long *cmp, long &pmk){
	long l=0;
	while(l<pmk-1){
		if(mpl[l]>mpl[l+1]){
			long h,h1;
			h=mpl[l];
			mpl[l]=mpl[l+1];
			mpl[l+1]=h;
			h1=cmp[l];
			cmp[l]=cmp[l+1];
			cmp[l+1]=h1;
			if(l)l--;
		}
		else l++;
	}
	ofstream mplo("mypushlb.txt");
	mplo<<pmk<<"\n";
	for(long i=0; i<pmk; i++){
		mplo<<mpl[i]<<"\n";
		mplo<<cmp[i]<<"\n";
	}
}
int dpl(long *pl,long *cp, long &pk){
	long l=0;
	while(l<pk-1){
		if(pl[l]>pl[l+1]){
			long h,h1;
			h=pl[l];
			pl[l]=pl[l+1];
			pl[l+1]=h;
			h1=cp[l];
			cp[l]=cp[l+1];
			cp[l+1]=h1;
			if(l)l--;
		}
		else l++;
	}
	ofstream plo("pushlb.txt");
	plo<<pk<<"\n";
	for(long i=0; i<pk; i++){
		plo<<pl[i]<<"\n";
		plo<<cp[i]<<"\n";
	}
}
int smkl(long *mkl,long *cmk, long &kmk){
	ifstream mkli("mykorlib.txt");
	mkli>>kmk;
	for(long i=0; i<kmk; i++){
		mkli>>mkl[i];
		mkli>>cmk[i];
	}
}
int skl(long *kl,long *ck, long &kk){
	ifstream kori("korlib.txt");
	kori>>kk;
	for(long i=0; i<kk; i++){
		kori>>kl[i];
		kori>>ck[i];
	}
}
int dmkl(long *mkl,long *cmk, long &kmk){
	long l=0;
	while(l<kmk-1){
		if(mkl[l]>mkl[l+1]){
			long h,h1;
			h=mkl[l];
			mkl[l]=mkl[l+1];
			mkl[l+1]=h;
			h1=cmk[l];
			cmk[l]=cmk[l+1];
			cmk[l+1]=h1;
			if(l)l--;
		}
		else l++;
	}
	ofstream mklo("mykorlib.txt");
	mklo<<kmk<<"\n";
	for(long i=0; i<kmk; i++){
		mklo<<mkl[i]<<"\n";
		mklo<<cmk[i]<<"\n";
	}
}
int dkl(long *kl,long *ck, long &kk){
	long l=0;
	while(l<kk-1){
		if(kl[l]>kl[l+1]){
			long h,h1;
			h=kl[l];
			kl[l]=kl[l+1];
			kl[l+1]=h;
			h1=ck[l];
			ck[l]=ck[l+1];
			ck[l+1]=h1;
			if(l)l--;
		}
		else l++;
	}
	ofstream klo("korlib.txt");
	klo<<kk<<"\n";
	for(long i=0; i<kk; i++){
		klo<<kl[i]<<"\n";
		klo<<ck[i]<<"\n";
	}
}
int pmp(){
	long mpl[n],cmp[n],pmk;
	smpl(mpl,cmp,pmk);
	while(true){
		long a,b;
		cout<<"****************************\n";
		cout<<"*Menu prosmotra moih pushek*\n";
		cout<<"****************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<pmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		a=atol(buf);
		if(!a)break;
		cin>>buf;
		b=atol(buf);
		if((a<1)||(a>pmk))break;
		if((b<1)||(b>pmk))break;
		a--;
		cout<<"----------------------\n";
		cout<<"| nomer | sila ataki |\n";
		for(long i=a; i<b; i++){
			cout<<"----------------------\n";
			printf("| %5li | %10li |\n",(i+1),mpl[i]);
		}
		cout<<"----------------------\n";
	}
}
int bml(long &mon){
	long pl[n],mpl[n],cmp[n],cp[n],pk,pmk;
	spl(pl,cp,pk);
	smpl(mpl,cmp,pmk);
	while(true){
		long v;
		cout<<"*********************\n";
		cout<<"*Menu pokupki pushki*\n";
		cout<<"*********************\n";
		cout<<"----------------------------------\n";
		cout<<"| nomer | sila ataki |    cena   |\n";
		for(long i=0; i<pk; i++){
			cout<<"----------------------------------\n";
			printf("| %5li | %10li | %9li |\n",(i+1),pl[i],cp[i]);
		}
		cout<<"----------------------------------\n";
		cout<<"->Vvedite nomer puski chtoby kupit 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		v=atol(buf);
		//cin>>v;
		if((v<1)||(v>pk))break;
		if(cp[v-1]>mon)cout<<"!<ne hvataet deneg>!\n";
		else{
			mpl[pmk]=pl[v-1];
			cmp[pmk]=cp[v-1];
			pmk++;
			mon-=cp[v-1];
			cout<<">>puska kuplena<<\n";
		}
	}
	dmpl(mpl,cmp,pmk);
}
int kuppush(long &mon){
	int v=1;
	while(v){
		cout<<"***************\n";
		cout<<"*pokupka puski*\n";
		cout<<"***************\n";
		cout<<"\n---------------------------------\n| Na schetu | ";
		cout<<mon;
		cout<<"\n---------------------------------\n";
		cout<<"1) kupit pusku\n";
		cout<<"2) prodat pushku\n";
		cout<<"0) vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1)bml(mon);
		if(v==2)mpmp(mon);
		if(!v)break;
	}
}
int pmk(){
	long mkl[n],kmk,cmk[n];
	smkl(mkl,cmk,kmk);
	while(true){
		long a,b;
		cout<<"******************************\n";
		cout<<"*Menu prosmotra moih korpusov*\n";
		cout<<"******************************\n";
		cout<<"->Vvedite interval vvvoda 1-"<<kmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];		
		cin>>buf;
		a=atol(buf);
		if(!a)break;
		cin>>buf;
		b=atol(buf);
		if((a<1)||(a>kmk))break;
		if((b<1)||(b>kmk))break;
		a--;
		cout<<"---------------------\n";
		cout<<"| nomer |  zdorove  |\n";
		for(long i=a; i<b; i++){
			cout<<"---------------------\n";
			printf("| %5li | %9li |\n",(i+1),mkl[i]);
		}
		cout<<"---------------------\n";
	}
}
int bmk(long &mon){
	long kl[n],mkl[n],ck[n],cmk[n],kk,kmk;
	smkl(mkl,cmk,kmk);
	skl(kl,ck,kk);
	while(true){
		long v;
		cout<<"***********************\n";
		cout<<"*Menu pokupki korpusov*\n";
		cout<<"***********************\n";
		cout<<"----------------------------------\n";
		cout<<"| nomer |  zdorove   |   cena    |\n";
		for(long i=0; i<kk; i++){
			cout<<"----------------------------------\n";
			printf("| %5li | %10li | %9li |\n",(i+1),kl[i],ck[i]);
		}
		cout<<"----------------------------------\n";
		cout<<"->Vvedite nomer korpusa chtoby kupit 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if((v<1)||(v>kk))break;
		if(ck[v-1]>mon)cout<<"!<ne hvataet deneg>!\n";
		else{
			mkl[kmk]=kl[v-1];
			cmk[kmk]=ck[v-1];
			kmk++;
			mon-=ck[v-1];
			cout<<">>korpus kuplen<<\n";
		}
	}
	dmkl(mkl,cmk,kmk);
}
int kupkor(long &mon){
	int v=1;
	while(v){
		cout<<"*****************\n";
		cout<<"*pokupka korpusa*\n";
		cout<<"*****************\n";
		cout<<"\n---------------------------------\n| Na schetu | ";
		cout<<mon;
		cout<<"\n---------------------------------\n";
		cout<<"1) kupit korpus\n";
		cout<<"2) prodat korpus\n";
		cout<<"0) vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1)bmk(mon);
		if(v==2)mpmk(mon);
		if(!v)break;
	}
}
int mag(){
	int v=1;
	while(v){
		cout<<"**********\n";
		cout<<"*magazine*\n";
		cout<<"**********\n";
		char name[30];
		long mon,win,lose;
		slc(name,mon,win,lose);
		cout<<"\n------------------------------------------\n ";
		cout<<name;
		cout<<"\n------------------------------------------\n ";
		cout<<mon;
		cout<<"\n------------------------------------------\n\n";
		cout<<"$-1-$ kupit korpus\n";
		cout<<"$-2-$ kupit pushku\n";
		//cout<<"$-3-$ kupit tank\n";          ???
		cout<<"$-0-$ vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1)kupkor(mon);
		if(v==2)kuppush(mon);
		dlc(name,mon,win,lose);
		if(!v)break;
	}
}
int oru(){
	int v=1;
	while(v){
		cout<<"***********\n";
		cout<<"*orugeinai*\n";
		cout<<"***********\n";
		char name[30];
		long mon,win,lose,v,hpv,sav;
		slc(name,mon,win,lose);
		cout<<"\n------------------------------------------\nNik  | ";
		cout<<name;
		cout<<"\n------------------------------------------\nWin  | ";
		cout<<win;
		cout<<"\n------------------------------------------\nLose | ";
		cout<<lose;
		cout<<"\n------------------------------------------\n\n";
		cout<<"=1= moi korpusa\n";
		cout<<"=2= moi pushki\n";
		cout<<"=3= moi tanki\n";
		cout<<"=0= vyiti\n";
		char buf[30];
		cin>>buf;
		v=atoi(buf);
		//cin>>v;
		if(v==1)pmk();
		if(v==2)pmp();
		if(v==3)bmt();
		if(!v)break;
	}
}
int lib(){
	cout<<"Vvedite parol\n";
	long v=1;
	cin>>v;
	if(v!=404){return 0;}
	while(v){
		cout<<"*****************\n";
		cout<<"*menu biblioteka*\n";
		cout<<"*****************\n";
		cout<<"1)admin\n";
		//cout<<"2)posmotret faily v biblioteke kor\n";
		//cout<<"3)posmotret faily v biblioteke push\n";
		cout<<"0)vyiti\n";
		cin>>v;
		if(v==1)adm();
		//if(v==2)pbk();
		//if(v==3)pbp();
		if(!v)break;
	}
}//все меню админа не переведены на буфер!!
int pbk(){
	long kl[n],ck[n],kk;
	skl(kl,ck,kk);
	while(true){
		long a,b;
		cout<<"*************************\n";
		cout<<"*Menu prosmotra korpusov*\n";
		cout<<"*************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		char buf[30];
		cin>>buf;
		a=atol(buf);
		if(!a)break;
		cin>>buf;
		b=atol(buf);
		if((a<1)||(a>kk))break;
		if((b<1)||(b>kk))break;
		a--;
		cout<<"---------------------\n";
		cout<<"| nomer |  zdorove  |\n";
		for(long i=a; i<b; i++){
			cout<<"---------------------\n";
			printf("| %5li | %9li |\n",(i+1),kl[i]);
		}
		cout<<"---------------------\n";
	}
}
int pbp(){//без буфера!!
	long pl[n],cp[n],pk;
	spl(pl,cp,pk);
	while(true){
		long a,b;
		cout<<"***********************\n";
		cout<<"*Menu prosmotra pushek*\n";
		cout<<"***********************\n";
		cout<<"->Vvedite interval vvoda 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if(!a)break;
		cin>>b;
		if((a<1)||(a>pk))break;
		if((b<1)||(b>pk))break;
		a--;
		cout<<"----------------------\n";
		cout<<"| nomer | sila ataki |\n";
		for(long i=a; i<b; i++){
			cout<<"----------------------\n";
			printf("| %5li | %10li |\n",(i+1),pl[i]);
		}
		cout<<"----------------------\n";
	}
}
int adm(){//без буфера!!
	long par;
	int v=1;
	cout<<"->>>vvedite parol\n";
	cin>>par;
	if(par==404)
	while (v){
		cout<<" -************- \n";
		cout<<"-+*Menu ADMIN*+-\n";
		cout<<" -************- \n";
		cout<<"1> dobavit korpusa\n";
		cout<<"2> dobavit pushki\n";
		cout<<"3> dobavit deneg\n";
		cout<<"0> vyiti\n";
		cin>>v;
		if(v==1)bk();
		if(v==2)bp();
		if(v==3){
			char name[30];
			long mon,win,lose,v2;
			v2=1;
			slc(name,mon,win,lose);
			while(v2){
				cout<<"--------------------------------------------\n";
				cout<<"| na schetu | "<<mon<<" \n";
				cout<<"--------------------------------------------\n";
				cout<<"->>vvedite na skolko uvelichit\n";
				cout<<"->>ili 0 chtoby vyiti\n";
				cin>>v2;
				if(!v2)break;
				mon+=v2;
			}
			dlc(name,mon,win,lose);
		}
		if(!v)break;
	}
}
int bk(){//без буфера!!
	long kl[n],ck[n],kk;
	skl(kl,ck,kk);
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
			cout<<"->>vvedite zdorovie\n";
			cout<<"->>ili 0 chtoby vyiti\n";
			cin>>kl[kk];
			if(kl[kk]<1)break;
			cout<<"->>vvedite cenu\n";
			cin>>ck[kk];
			if(ck[kk]<0)break;
			kk++;
			cout<<">>korpus dobavlen<<\n";
		}
		if(v==2){
			long delk;
			cout<<"---------------------\n";
			cout<<"| nomer |  zdorove  |\n";
			for(long i=0; i<kk; i++){
				cout<<"---------------------\n";
				printf("| %5li | %9li |\n",(i+1),kl[i]);
			}
			cout<<"---------------------\n";
			cout<<"->vvedite nomer korpusa na udalenie 1-"<<kk<<"\n";
			cout<<"->Ili 0 chtoby vyiti\n";
			cin>>delk;
			if((delk<1)||(delk>kk))break;
			for(long i=delk; i<kk; i++){
				kl[i-1]=kl[i];
				ck[i-1]=ck[i];
			}
			kk--;
			cout<<">>korpus udalen<<\n";
		}
		if(!v)break;
	}
	dkl(kl,ck,kk);
}
int bp(){//без буфера!!
	long pl[n],cp[n],pk;
	spl(pl,cp,pk);
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
			cout<<"->>vvedite silu attaki\n";
			cout<<"->>Ili 0 chtoby vyiti\n";
			cin>>pl[pk];
			if(pl[pk]<1)break;
			cout<<"->>vvedite cenu\n";
			cin>>cp[pk];
			if(cp[pk]<0)break;
			pk++;
			cout<<">>pushka dobavlena<<\n";
		}
		if(v==2){
			long delk;
			cout<<"----------------------\n";
			cout<<"| nomer | sila ataki |\n";
			for(long i=0; i<pk; i++){
				cout<<"----------------------\n";
				printf("| %5li | %10li | %9li |\n",(i+1),pl[i]);
			}
			cout<<"----------------------\n";
			cout<<"->vvedite nomer pushki na udalenie 1-"<<pk<<"\n";
			cout<<"->Ili 0 chtoby vyiti\n";
			cin>>delk;
			if((delk<1)||(delk>pk))break;
			for(long i=delk; i<pk; i++){
				pl[i-1]=pl[i];
				cp[i-1]=cp[i];
			}
			pk--;
			cout<<">>pushka udalena<<\n";
		}
		if(!v)break;
	}
	dpl(pl,cp,pk);
}
