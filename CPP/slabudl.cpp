#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<algorithm>
float  maximum (float c, float d){
    if(c>d){
        return c;
    }
    else{
        return d;
    }
}

using namespace std;
int main()
{
    float l,b,td,tdd,d,cc,db,ts,tf,tp,s,f,p,dl,ll,tdl;
    float mf,x1,x2,ax1,ax2,x3,y1,y2,y3,mx,my;
    float dd,mu,fck,w,x,la,ast,asty,astp,fy,db1,db2,astb,astb1;
    float sp,spp,ef,x4,la1,sp1,sp2,fs,alp,alp1;
    cout<<"This is to calculate design of simply supported of two way slab"<<endl;
    cout<<"with UDL(Uniformly distributed load)"<<endl;
    cout<<endl;
    cout<<"Enter the length of slabs in m (longer direction): ";
    cin>>l;
    cout<<"Enter the breath of slabs in m (shoter direction): ";
    cin>>b;
    td=b/24;
    cout<<"Total deapth is "<<td<<" m"<<endl;
    cout<<"Enter the total deapth based on "<<td<<" mm : ";
    cin>>tdd;
    cout<<"Enter the clear cover in mm : ";
    cin>>cc;
    cout<<"Enter the dia of bars in mm :  ";
    cin>>db;
    d= tdd-cc-(db/2);
    cout<<"The value of d is "<<d<<" mm"<<endl;
    cout<<endl;
    cout<<"STEP 1: DESIGN LOADS "<<endl;
    cout<<"Enter the thickness of slabs in mm : ";
    cin>>ts;
    cout<<"Enter the thickness of floor finish in mm : ";
    cin>>tf;
    cout<<"Enter the thickness of plastering in mm : ";
    cin>>tp;
    s=(tdd*25*1)/1000;
    f=(tf*24*1)/1000;
    p=(tp*24*1)/1000;
    dl= s+f+p;
    cout<<"The total dead load is "<<dl<<" KN/m2"<<endl;
    cout<<"Enter the live load :";
    cin>>ll;
    tdl = 1.5*(dl+ll);
    cout<<"The total load(W) is : "<<tdl<<"KN/m2";
    cout<<endl;
    cout<<endl;
    cout<<"STEP 2:CALCULATIONS OF MAXIMUM FACTORED MOMENT "<<endl;
    mf=(l/b);
    cout<<"The value of (l/b) is "<<mf<<endl;
    cout<<"Refer the table number 27(pg no:91), IS456:2000 code book"<<endl;
    cout<<"For x axis: "<<endl;
    cout<<"Enter the two values which "<<mf<<" is lying in between "<<endl;
    cout<<"Hint : first enter the larger value and then enter the smaller value;"<<endl;
    cin>>x1;
    cin>>x2;
    cout<<"Enter the starting value (it should be less than "<<mf<<" ): ";
    cin>>x3;
    ax1= x2+(((x1-x2)/0.1)*(mf-x3));
    cout<<"Alpha x is "<<ax1<<endl;
    cout<<endl;
    cout<<"For y axis: "<<endl;
    cout<<"Enter the two values which "<<mf<<" is lying in between "<<endl;
    cout<<"Hint : first enter the larger value and then enter the smaller value;"<<endl;
    cin>>y1;
    cin>>y2;
    ax2= y1-((y1-y2)/0.1)*(mf-x3);
    cout<<"Alpha y is "<<ax2<<endl;
    mx=(ax1*tdl*b*b);
    my=(ax2*tdl*b*b);
    cout<<"Mx= "<<mx<<" KNm"<<endl;
    cout<<"My= "<<my<<" KNm"<<endl;
    float max=maximum(mx,my);
    cout<<"Mu= "<<max<<" KNm"<<endl;
    cout<<endl;
    cout<<"STEP 3: CHECK FOR DEAPTH "<<endl;
    cout<<"Enter the grade of concrete: ";
    cin>>fck;
    cout<<"Enter the width in m : ";
    cin>>w;
    dd=sqrtf((max*1000000)/(0.138*fck*w*1000));
    cout<<dd<<endl;
    if (dd<d)
    {
        cout<<d<<"mm can be used for further calculations";
    } 
    else
    {
        cout<<"Increase the deapth of slab ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"STEP 4: CALCULATION OF AREA OF STEEL"<<endl;
    x= (1.2 - sqrtf(1.44 -(6.6*max*1000000)/(fck*w*1000*d*d)));
    cout<<x<<" should be less than 0.48 for steel 415 grade"<<endl;
     if (x<0.48)
    {
        cout<<"The dia of bars can be taken ";
    }
    else
    {
        cout<<"Decrease the dia of bars";
    }
    cout<<endl;
    la=d*(1-(0.416*x));
    cout<<"Lever Arm is "<<la<<" mm"<<endl;
    cout<<endl;
    cout<<"Area of steel in shorter direction"<<endl;
    cout<<"Enter the grade of steel ";
    cin>>fy;
    cout<<"Enter the dia of bar(distribution bar)in mm: ";
    cin>>db1;
    ast=((max*1000000)/(0.87*fy*la));
    cout<<"Area of steel(distribution): "<<ast<<" mm2"<<endl;
    astb= 0.785*db1*db1;
    cout<<"Area of steel bars "<<astb<<" mm2"<<endl;
    sp=(1000*astb)/ast;
    cout<<"Spacing required is "<<sp<<" mm"<<endl;
    cout<<"Enter the spacing for bars based on "<<sp<<"  ";
    cin>>spp;
    cout<<"Provide "<<db1<<" mm bar @ "<<spp<<" mm c/c"<<endl;
    cout<<endl;
    cout<<"Area of steel in longer direction"<<endl;
    cout<<"Enter the dia of bars in longer direction in mm: ";
    cin>>db2;
    ef= tdd-cc-db1-(db2/2);
    cout<<"The effective deapth is: "<<ef<<" mm"<<endl;
    x4= 1.2-(sqrtf(1.44-(6.6*my*1000000)/(fck*w*1000*ef*ef)));
    cout<<"x/d = "<<x4<<endl;
    cout<<"Note: (x/d) value should be less than 0.48"<<endl;
    if (x4<0.48)
    {
        cout<<"The dia of bars can be taken "<<endl;
    }
    else
    {
        cout<<"Decrease the dia of bars"<<endl;
    }
    la1= ef*(1-(0.416*x4));
    cout<<"Lever arm is "<<la1<<" mm"<<endl;
    asty= (my*1000000)/(0.87*fy*la1);
    cout<<"Area of steel is "<<asty<<" mm2"<<endl;
    astb1= 0.785*db2*db2;
    sp1= (1000*astb1)/asty;
    cout<<sp1<<" mm"<<endl;
    cout<<"Enter the spacing based on "<<sp1<<": ";
    cin>>sp2;
    cout<<"Provide "<<db2<<" @ "<<sp2<<" mm c/c";
    cout<<endl;
    cout<<endl;
    cout<<"STEP 5: CHECK FOR DEFLECTION"<<endl;
    astp= (1000*astb)/spp;
    cout<<"Area of steel provided is "<<astp<<" mm2"<<endl;
    fs=0.58*fy*(ast/astp);
    cout<<"fs is "<<fs<<" N/mm2"<<endl;
    cout<<endl;
    cout<<"According to clause 23.2.1 in IS456:2000 code book"<<endl;
    cout<<"Allowable (L/D) = 30"<<endl;
    alp=(b*1000)/tdd;
    alp1= (b*1000)/d;
    cout<<"(L/D)= "<<alp<<endl;
    cout<<"(L/d)= "<<alp1<<endl;
    cout<<endl;
    cout<<"Summary of design "<<endl;
    cout<<"Over all deapth = "<<tdd<<" mm"<<endl;
    cout<<"Clear cover = "<<cc<<" mm"<<endl;
    cout<<"Reinforcement in shorter direction"<<endl;
    cout<<db1<<" mm bar @ "<<spp<<" mm c/c"<<endl;
    cout<<"Reinforcement in longer  direction"<<endl;
    cout<<db2<<" mm bar @ "<<sp2<<" mm c/c"<<endl;
    cout<<"Concrete = M"<<fck<<endl;
    cout<<"Steel = Fe "<<fy<<endl;










    
    

}
 