#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
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
int bmk(int &mon);
int bml(int &mon);
int kupkor(int &mon);
int kuppush(int &mon);
int slc(char *name, int &mon,int &win,int &lose);
int dlc(char *name, int &mon,int &win,int &lose);
int smpl(int *mpl,int *cmp, int &pmk);
int spl(int *pl,int *cp, int &pk);
int dmpl(int *mpl,int *cmp, int &pmk);
int dpl(int *pl,int *cp, int &pk);
int smkl(int *mkl,int *cmk, int &kmk);
int skl(int *kl,int *ck, int &kk);
int dmkl(int *mkl,int *cmk, int &kmk);
int dkl(int *kl,int *ck, int &kk);
int smtl(int *mtl, int *mtl1, int *cmpt,int *cmkt, int &kmt);
int dmtl(int *mtl, int *mtl1, int *cmpt,int *cmkt, int &kmt);
int mpmk(int &mon);
int mpmp(int &mon);
int titry();
int menb1();//!!!
int boi();//!!!
int bois(int &sa, int &hp);//!!
int war(int &sa,int &hp,int &sav,int &hpv,int &mon,int &win,int &lose);//!!
int rdm(int &o);//!!!
int smen();//11111111
int main(){
	int vybor=1;
	while(vybor){
		cout<<"<*************>\n";
		cout<<"<*TANK*BATTLE*>\n";
		cout<<"<*************>\n";
		cout<<"    *V-1.a*    \n";
		cout<<"    *******    \n";
		cout<<"<-1-> biblioteka\n";
		cout<<"<-2-> orugeinai\n";
		cout<<"<-3-> magazine\n";
		cout<<"<-4-> titry\n";
		cout<<"<-5-> boi\n";//!!!!
		cout<<"<-6-> smena nika\n";//11111
		cout<<"<-0-> vyiti\n";
		cin>>vybor;
		if(vybor==1)lib();
		if(vybor==2)oru();
		if(vybor==3)mag();
		if(vybor==4)titry();
		if(vybor==5)menb1();//!!!
		if(vybor==6)smen();//111
		if(!vybor){titry(); break;}
	}
}
int smen(){//11111
	char name[30];
	int mon,win,lose,v,hpv,sav;
	slc(name,mon,win,lose);
	v=1;
	while(v){
		cout<<"************\n";
		cout<<"*smenit nik*\n";
		cout<<"************\n";
		cout<<"tekushii nik  "<<name<<"\n";
		cout<<"->1 prodolgit\n";
		cout<<"->0 vyiti\n";
		cin>>v;
		if(!v)break;
		else{
			cout<<"->>Vvedite novyi nik\n";
			cin>>name;
		}
	}
	dlc(name,mon,win,lose);
}
int war(int &sa,int &hp,int &sav,int &hpv,int &mon,int &win,int &lose){//!!!
	cout<<"-------------------------------\n";
	cout<<"|          menu boia          |\n";
	cout<<"-------------------------------\n";
	cout<<"-------------------------------\n";
	cout<<"-------------------------------\n";
	cout<<"|      boi nachinetsia        |\n";
	cout<<"-------------------------------\n";
	cout<<"-------------------------------\n";
	int a,b,c,d;
	a=hp;
	b=sa;
	c=hpv;
	d=sav;
	while(true){
		int r,ma,va,hod;
		rdm(r);
		ma=b*(r%3);
		cout<<"PC teriaet "<<ma<<"hp\n";
		if(ma/b==2)cout<<"VOT ETO KRIT!!!!!!!!\n";
		cout<<"-------------------------------\n";
		c-=ma;
		if(c<1){cout<<"Ty pobedil!\n"; win++; mon+=hpv/25*20; break;}
		rdm(r);
		va=d*(r%3);
		cout<<"igrock teriaet "<<va<<"hp\n";
		if(va/d==2)cout<<"VOT ETO KRIT!!!!!!!!\n";
		cout<<"-------------------------------\n";
		a-=va;
		if(a<1){cout<<"Ty proigral!\n"; lose++; break;}
	}
}
int bois(int &sa, int &hp){//!!!
	char name[30];
	int mon,win,lose,v,hpv,sav;
	slc(name,mon,win,lose);
	v=1;
	while(v){
		cout<<"******************\n";
		cout<<"*Vybor protivnica*\n";
		cout<<"******************\n";
		cout<<"1) legkii    ""25hp 5sa""   nagrada 20\n";
		cout<<"2) srednij   ""50hp 10sa""  nagrada 40\n";
		cout<<"3) tiageliy  ""75hp 15sa""  nagrada 60\n";
		cout<<"4) ADMINamin ""100hp 20sa"" nagrada 80\n";
		cout<<"0) exit\n";
		cin>>v;
		if(!v)break;
		if(v==1){sav=5; hpv=25;}
		if(v==2){sav=10; hpv=50;}
		if(v==3){sav=15; hpv=75;}
		if(v==4){sav=20; hpv=100;}
		war(sa,hp,sav,hpv,mon,win,lose);
	}
	dlc(name,mon,win,lose);
}
int rdm(int &o){//!!!
	ifstream fi("rdm.txt");
	int m[100];
	for(int i=0; i<100; i++){
		fi>>m[i];
	}
	o=m[0];
	for(int i=1; i<100; i++)
		m[i-1]=m[i];
	m[99]=o;
	ofstream fo("rdm.txt");
	for(int i=0; i<100; i++){
		if((i%10==0)&&(i))fo<<endl;
		fo<<m[i]<<" ";
	}
}
int boit(){//!!!
	int mtl[200],mtl1[200],kmt,cmpt[200],cmkt[200];
	smtl(mtl,mtl1,cmpt,cmkt,kmt);
	while(true){
		int a,b;
		cout<<"******************\n";
		cout<<"*Menu VYBOR tanka*\n";
		cout<<"******************\n";
		for(int i=0; i<kmt; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mtl[i]<<" "<<mtl1[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		cout<<"->Vvedite nomer tanka dlia boia 1-"<<kmt<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
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
	cin>>v;
	if(v)boit();
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
	cout<<"|     20.12.2011-22.12.2011      |\n";
	cout<<"==================================\n";
	cout<<"\n\n";
	int a;
	cout<<"Vvedite 0 chtoby vyiti\n";
	cin>>a;
}
int mpmp(int &mon){
	int mpl[200],cmp[200],pmk,v;
	smpl(mpl,cmp,pmk);
	v=1;
	while(v){
		cout<<"*********************\n";
		cout<<"*Menu prodagi pushek*\n";
		cout<<"*********************\n";
		for(int i=0; i<pmk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mpl[i]<<" | "<<cmp[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		cout<<"->Vvedite nomer pushki chtoby prodat 1-"<<pmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
		if((v<1)||(v>pmk))break;
		mon+=cmp[v-1];
		for(int i=v; i<pmk; i++){
			mpl[i-1]=mpl[i];
			cmp[i-1]=cmp[i];
		}
		pmk--;
		cout<<">>pushka prodana<<\n";
	}
	dmpl(mpl,cmp,pmk);
}
int mpmk(int &mon){
	int mkl[200],cmk[200],kmk,v;
	smkl(mkl,cmk,kmk);
	v=1;
	while(v){
		cout<<"**********************\n";
		cout<<"*Menu prodagi korpusa*\n";
		cout<<"**********************\n";
		for(int i=0; i<kmk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mkl[i]<<" | "<<cmk[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		cout<<"->Vvedite nomer korpusa chtoby prodat 1-"<<kmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
		if((v<1)||(v>kmk))break;
		mon+=cmk[v-1];
		for(int i=v; i<kmk; i++){
			mkl[i-1]=mkl[i];
			cmk[i-1]=cmk[i];
		}
		kmk--;
		cout<<">>korpus prodan<<\n";
	}
	dmkl(mkl,cmk,kmk);
}
int slc(char *name, int &mon,int &win,int &lose){
	ifstream slci("lickab.txt");
	slci>>name>>mon>>win>>lose;
	if(mon/100000>0)mon=99999;
	else mon%=100000;
}
int dlc(char *name, int &mon,int &win,int &lose){
	ofstream dlco("lickab.txt");
	dlco<<name<<endl<<mon<<endl<<win<<endl<<lose;
	if(mon/100000>0)mon=99999;
	else mon%=100000;
}
int razmt(){
	int mtl[200],mtl1[200],kmt,mpl[200],pmk,mkl[200],kmk,cmpt[200],cmkt[200],cmp[200],cmk[200];
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
		cin>>v;
		if(v==1){
			for(int i=0; i<kmt; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<mtl[i]<<" "<<mtl1[i]<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"->vvedite nomer tanka\n";
			cout<<"-> ili 0 chtoby vyiti\n";
			int q;
			cin>>q;
			if((q<1)||(q>kmt))break;
			mpl[pmk]=mtl[q-1];
			cmp[pmk]=cmpt[q-1];
			pmk++;
			mkl[kmk]=mtl1[q-1];
			cmk[kmk]=cmkt[q-1];
			kmk++;
			for(int i=q; i<kmt; i++){
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
	int mtl[200],mtl1[200],kmt,mpl[200],pmk,mkl[200],kmk,cmpt[200],cmkt[200],cmp[200],cmk[200];
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
		cin>>v;
		if(v==1){
			cout<<"---------------------------------------\n";
			for(int i=0; i<pmk; i++){
				cout<<" "<<(i+1)<<" | "<<mpl[i]<<"\n";
				cout<<"---------------------------------------\n";
			}
			cout<<"->>vvedite nomer puski dlai tanka\n";
			cout<<"->>ili 0 chtoby vyiti\n";
			int vub,vub1;
			cin>>vub;
			if((vub<1)||(vub>pmk))break;			
			cout<<"---------------------------------------\n";
			for(int i=0; i<kmk; i++){
				cout<<" "<<(i+1)<<" | "<<mkl[i]<<"\n";
				cout<<"---------------------------------------\n";
			}
			cout<<"->>vvedite nomer korpusa dlai tanka\n";
			cin>>vub1;
			if((vub1<1)||(vub>kmk))break;
			mtl[kmt]=mpl[vub-1];
			cmpt[kmt]=cmp[vub-1];
			for(int i=vub; i<pmk; i++){
				mpl[i-1]=mpl[i];
				cmp[i-1]=cmp[i];
			}
			pmk--;
			mtl1[kmt]=mkl[vub1-1];
			cmkt[kmt]=cmk[vub1-1];
			for(int i=vub; i<kmk; i++){
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
	int mtl[200],mtl1[200],kmt,cmpt[200],cmkt[200];
	smtl(mtl,mtl1,cmpt,cmkt,kmt);
	while(true){
		int a,b;
		cout<<"****************************\n";
		cout<<"*Menu prosmotra moih tankov*\n";
		cout<<"****************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<kmt<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if((a<1)||(a>kmt))break;
		cin>>b;
		if((b<1)||(b>kmt))break;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mtl[i]<<" "<<mtl1[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int dmtl(int *mtl, int *mtl1,int *cmpt,int *cmkt, int &kmt){
	long l=0;
	while(l<kmt-1){
		if(mtl[l]>mtl[l+1]){ 
			int h,h1,h2,h3;
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
	for(int i=0; i<kmt; i++){
		mtlo<<mtl[i]<<"\n";
		mtlo<<mtl1[i]<<"\n";
		mtlo<<cmpt[i]<<"\n";
		mtlo<<cmkt[i]<<"\n";
	}
}
int smtl(int *mtl, int *mtl1,int *cmpt,int *cmkt, int &kmt){
	ifstream mtli("mytank.txt");
	mtli>>kmt;
	for(int i=0; i<kmt; i++){
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
		cin>>v;
		if(v==1)pmt();
		if(v==2)sozmt();
		if(v==3)razmt();
		if(!v)break;
	}
}
int smpl(int *mpl,int *cmp, int &pmk){
	ifstream mpli("mypushlb.txt");
	mpli>>pmk;
	for(int i=0; i<pmk; i++){
		mpli>>mpl[i];
		mpli>>cmp[i];
	}
}
int spl(int *pl,int *cp, int &pk){
	ifstream pushi("pushlb.txt");
	pushi>>pk;
	for(int i=0; i<pk; i++){
		pushi>>pl[i];
		pushi>>cp[i];
	}
}
int dmpl(int *mpl,int *cmp, int &pmk){
	long l=0;
	while(l<pmk-1){
		if(mpl[l]>mpl[l+1]){ 
			int h,h1;
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
	for(int i=0; i<pmk; i++){
		mplo<<mpl[i]<<"\n";
		mplo<<cmp[i]<<"\n";
	}
}
int dpl(int *pl,int *cp, int &pk){
	long l=0;
	while(l<pk-1){
		if(pl[l]>pl[l+1]){ 
			int h,h1;
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
	for(int i=0; i<pk; i++){
		plo<<pl[i]<<"\n";
		plo<<cp[i]<<"\n";
	}
}
int smkl(int *mkl,int *cmk, int &kmk){
	ifstream mkli("mykorlib.txt");
	mkli>>kmk;
	for(int i=0; i<kmk; i++){
		mkli>>mkl[i];
		mkli>>cmk[i];
	}
}
int skl(int *kl,int *ck, int &kk){
	ifstream kori("korlib.txt");
	kori>>kk;
	for(int i=0; i<kk; i++){
		kori>>kl[i];
		kori>>ck[i];
	}
}
int dmkl(int *mkl,int *cmk, int &kmk){
	long l=0;
	while(l<kmk-1){
		if(mkl[l]>mkl[l+1]){ 
			int h,h1;
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
	for(int i=0; i<kmk; i++){
		mklo<<mkl[i]<<"\n";
		mklo<<cmk[i]<<"\n";
	}
}
int dkl(int *kl,int *ck, int &kk){
	long l=0;
	while(l<kk-1){
		if(kl[l]>kl[l+1]){ 
			int h,h1;
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
	for(int i=0; i<kk; i++){
		klo<<kl[i]<<"\n";
		klo<<ck[i]<<"\n";
	}
}
int pmp(){
	int mpl[200],cmp[200],pmk;
	smpl(mpl,cmp,pmk);
	while(true){
		int a,b;
		cout<<"****************************\n";
		cout<<"*Menu prosmotra moih pushek*\n";
		cout<<"****************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<pmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if((a<1)||(a>pmk))break;
		cin>>b;
		if((b<1)||(b>pmk))break;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mpl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int bml(int &mon){
	int pl[200],mpl[200],cmp[200],cp[200],pk,pmk;
	spl(pl,cp,pk);
	smpl(mpl,cmp,pmk);
	while(true){
		int v;
		cout<<"*********************\n";
		cout<<"*Menu pokupki pushki*\n";
		cout<<"*********************\n";
		for(int i=0; i<pk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<pl[i]<<" | "<<cp[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		cout<<"->Vvedite nomer puski chtoby kupit 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
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
int kuppush(int &mon){
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
		cin>>v;
		if(v==1)bml(mon);
		if(v==2)mpmp(mon);
		if(!v)break;
	}
}
int pmk(){
	int mkl[200],kmk,cmk[200];
	smkl(mkl,cmk,kmk);
	while(true){
		int a,b;
		cout<<"******************************\n";
		cout<<"*Menu prosmotra moih korpusov*\n";
		cout<<"******************************\n";
		cout<<"->Vvedite interval vvvoda 1-"<<kmk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if((a<1)||(a>kmk))break;
		cin>>b;
		if((b<1)||(b>kmk))break;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<mkl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int bmk(int &mon){
	int kl[200],mkl[200],ck[200],cmk[200],kk,kmk;
	smkl(mkl,cmk,kmk);
	skl(kl,ck,kk);
	while(true){
		int v;
		cout<<"***********************\n";
		cout<<"*Menu pokupki korpusov*\n";
		cout<<"***********************\n";
		for(int i=0; i<kk; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<kl[i]<<" | "<<ck[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
		cout<<"->Vvedite nomer korpusa chtoby kupit 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>v;
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
int kupkor(int &mon){
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
		cin>>v;
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
		int mon,win,lose;
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
		cin>>v;
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
		cout<<"=3= moi tanki\n";
		cout<<"=0= vyiti\n";
		cin>>v;
		if(v==1)pmk();
		if(v==2)pmp();
		if(v==3)bmt();
		if(!v)break;
	}
}
int lib(){
	int v=1;
	while(v){
		cout<<"*****************\n";
		cout<<"*menu biblioteka*\n";
		cout<<"*****************\n";
		cout<<"1)admin\n";
		cout<<"2)posmotret faily v biblioteke kor\n";
		cout<<"3)posmotret faily v biblioteke push\n";
		cout<<"0)vyiti\n";
		cin>>v;
		if(v==1)adm();
		if(v==2)pbk();
		if(v==3)pbp();
		if(!v)break;
	}
}
int pbk(){
	int kl[200],ck[200],kk;
	skl(kl,ck,kk);
	while(true){
		int a,b;
		cout<<"*************************\n";
		cout<<"*Menu prosmotra korpusov*\n";
		cout<<"*************************\n";
		cout<<"->Vvedite interval vvoda 1-"<<kk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if((a<1)||(a>kk))break;
		cin>>b;
		if((b<1)||(b>kk))break;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<kl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int pbp(){
	int pl[200],cp[200],pk;
	spl(pl,cp,pk);
	while(true){
		int a,b;
		cout<<"***********************\n";
		cout<<"*Menu prosmotra pushek*\n";
		cout<<"***********************\n";
		cout<<"->Vvedite interval vvoda 1-"<<pk<<endl;
		cout<<"->Ili 0 chtoby vyiti\n";
		cin>>a;
		if((a<1)||(a>pk))break;
		cin>>b;
		if((b<1)||(b>pk))break;
		a--;
		for(int i=a; i<b; i++){
			cout<<"-----------------------------------------\n";
			cout<<"|"<<(i+1)<<"| "<<pl[i]<<"\n";
		}
		cout<<"-----------------------------------------\n";
	}
}
int adm(){
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
			int mon,win,lose,v2;
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
int bk(){
	int kl[200],ck[200],kk;
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
			int delk;
			for(int i=0; i<kk; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<kl[i]<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"->vvedite nomer korpusa na udalenie 1-"<<kk<<"\n";
			cout<<"->Ili 0 chtoby vyiti\n";
			cin>>delk;
			if((delk<1)||(delk>kk))break;
			for(int i=delk; i<kk; i++){
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
int bp(){
	int pl[200],cp[200],pk;
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
			int delk;
			for(int i=0; i<pk; i++){
				cout<<"-----------------------------------------\n";
				cout<<"|"<<(i+1)<<"| "<<pl[i]<<"\n";
			}
			cout<<"-----------------------------------------\n";
			cout<<"->vvedite nomer pushki na udalenie 1-"<<pk<<"\n";
			cout<<"->Ili 0 chtoby vyiti\n";
			cin>>delk;
			if((delk<1)||(delk>pk))break;
			for(int i=delk; i<pk; i++){
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