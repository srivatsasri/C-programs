#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<algorithm>

float  minimum(float a, float b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

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
   float l,b,s,d,cc,d1,td,t,dl,f,ll,be;
   float fl,es,wt,es1,es2,w,mu,vu,de,fck;
   float tv,x,d2,ast,fy,a,sp,spp,astp,d3,astb,fs,L,D,asts,dd,astsb,sps;
   cout<<"Design of one way slabs"<<endl;
   cout<<endl;
   cout<<"Enter the internal dimensions of a room(l,b): ";
   cin>>l;
   cin>>b;
   cout<<endl;
   cout<<"STEP 1:CALCUALTION OF FACTORED LOADS"<<endl;
   d=(b/25)*1000;
   cout<<"Deapth is: "<<d<<" mm"<<endl;
   cout<<"Enter the clear cover in mm: ";
   cin>>cc;
   cout<<"Enter the dia of bars in mm: ";
   cin>>d1;
   td= (d+cc+(d1/2));
   cout<<"Total deapth is : "<<td<<" mm"<<endl;
   cout<<endl;
   cout<<"Enter the thickness of the slab in mm: ";
   cin>>t;
   cout<<"Enter the live load: ";
   cin>>ll;
   cout<<"Enter floor finish: ";
   cin>>f;
   s= (t*25)/1000;
   dl= s+f;
   cout<<"Dead load: "<<dl<<" KN/m"<<endl;
   cout<<"Live load: "<<ll<<" KN/m"<<endl;
   fl = 1.5*(dl+ll);
   cout<<"Factored load= "<<fl<<" KN/m2"<<endl;
   cout<<endl;
   cout<<"Enter the thickness of wall in mm: "; 
   cin>>wt;
   cout<<"Checking for effective span"<<endl;
   es1=b+(wt/1000);
   es2=b+(d/1000);
   if (es1<es2)
   {
       cout<<"Effective span is:"<<es1<<" m"<<endl;

   }
   
    else
    {
        cout<<"Effective span is:"<<es2<<" m"<<endl;
    }
    float mini = minimum(es1,es2);
    w= fl*mini;
    cout<<"Total load per meter width= "<<w<<" KN"<<endl;
    cout<<endl;
    cout<<"STEP 2: ULTIMATE MOMENT AND SHEAR"<<endl;
    mu=(w*mini)/8;
    cout<<"Mu= "<<mu<<" KNm"<<endl;
    vu=w/2;
    cout<<"Vu= "<<vu<<" KN"<<endl;
    cout<<endl;
    cout<<"STEP 3: CHECK DEAPTH FOR BENDING"<<endl;
    cout<<"Enter the grade of concrete: ";
    cin>>fck;
    cout<<"Enter the width(b): ";
    cin>>be;
    de=sqrtf((mu*1000000)/(0.138*fck*be*1000));
    d2=de/1000;
    cout<<"Deapth is "<<d2<<endl;
    if (d2<(d/1000))
    {
        cout<<"Deapth "<<d/1000<<"  mm can be consider for calculations";
    }
    else
    {
        cout<<"Deapth should be increased";
    }
    cout<<endl;
    
    cout<<endl;
    cout<<"STEP 4:CHECK FOR SHEAR"<<endl;
    tv=((vu*1000)/((be*1000)*d));
    cout<<"Tv(Shear): "<<tv<<" N/mm2"<<endl;
    cout<<endl;
    cout<<"According to table 19 (IS456:2000):tc=0.28 N/mm2 "<<endl;
    cout<<"If tv<tc then wee not need stirup rod" <<endl;
    cout<<endl;
    cout<<"STEP 5: CALCULATION OF STEEL AREA"<<endl;
    float max = maximum(d2,d);
    x=1.2-(sqrtf(1.44-(6.6*mu*1000000)/(fck*be*1000*max*max)));
    cout<<"The value of x is :"<<x<<endl;
     float LA ;
    LA=d*(1-(0.416*x));
    cout<<"Lever Arm: "<<LA<<" mm"<<endl;
    cout<<"Enter the steel grade: ";
    cin>>fy;
    ast= (mu*1000000)/(0.87*fy*LA);
    cout<<"Ast required = "<<ast<<" mm2"<<endl;
    a= (0.785*d1*d1);
    cout<<"Area of steel of bar is: "<<a<<" mm2"<<endl;
    sp= ((be*1000*a)/ast);
    cout<<"Spacing reqiured is: "<<sp<<" mm"<<endl;
    cout<<"Enter the spacing based on "<<sp<<" : ";
    cin>>spp;
    cout<<"Enter the bar dia in mm :";
    cin>>d3;
    cout<<d3<<" mm @  "<<spp<<" mm c/c"<<endl;
    astb= (0.785*d3*d3);
    cout<<"The area of bar is "<<astb<<endl;
    astp= ((1000*astb)/spp);
    cout<<"Area of steel provided = "<<astp<<endl;
    cout<<"Area of steel required = "<<ast<<endl;
    if (ast<astp)
    {
       cout<<"The dia of bar is can be provided"<<endl;
       
    }
    else
    {
        cout<<"The dia of bars should be increased: "<<endl;
    }
    fs= ((0.58*fy*ast)/astp);
    cout<<"fs : "<<fs<<" N/mm2"<<endl;
    cout<<endl;
    cout<<"STEP 6: Modification factor"<<endl;
    L= ((b*1000)+d);
    D= (L / 31);
    cout<<"d: "<<D<<" mm"<<endl;
    cout<<endl;
    cout<<"STEP 7: Secondary steel(distribution steel)"<<endl;
    asts= (0.12*be*td*1000)/100;
    cout<<"The area of secondary steel is "<<asts<<" mm2"<<endl;
    cout<<"Enter the dia of secondary bar in mm: ";
    cin>>dd;
    astsb = (0.785*dd*dd);
    cout<<"The area of bars is "<<astsb<<" mm2"<<endl;
    sps=((be*1000*astsb)/asts);
    cout<<"Spacing required for secondary steel: "<<sps<<" mm c/c"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Design summary "<<endl;
    cout<<"Overall deapth of slab  = "<<td<<" mm"<<endl;
    cout<<"Clear cover of slab = "<<cc<<" mm"<<endl;
    cout<<"Reinforcement in shorter direction"<<endl;
    cout<<dd<<" mm bar @ "<<sps<<" mm c/c"<<endl;
    cout<<"Reinforcement in longer  direction"<<endl;
    cout<<d3<<" mm bar @ "<<spp<<" mm c/c"<<endl;
    cout<<"Concrete = M"<<fck<<endl;
    cout<<"Steel = Fe "<<fy<<endl;

    return 0;

}