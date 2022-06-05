#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
    float s,d,w,cc,db,g,r,t,b,ad,dd,a,c,f;
    float dl,ll,tl,mu,d1,fck,bb,x,z,ast,fy,be,ts,as;
    float n,nn,pt,astt,dbd,sp,v,tw,fs;
    cout<<"THIS PROGRAM IS TO DESIGN OF STAIRCASE"<<endl;
    cout<<endl;
    cout<<"STEP 1 : THICKNESS OF WAIST SLAB"<<endl;
    cout<<"Enter the span(in m) of staircase= ";
    cin>>s;
    cout<<"Enter the breadth of flight in m  = ";
    cin>>be;
    d=(s*1000)/30;
    cout<<"d= "<<d<<" mm"<<endl;
    cout<<"Enter the clear cover in mm = ";
    cin>>cc;
    cout<<"Enter the dia of bars(main reinforcement) in mm= ";
    cin>>db;
    w=d+cc+(db/2);
    cout<<"Waist of slab = "<<w<<" mm"<<endl;
    cout<<"Assume the deapth of waist based on "<<w<<" : ";
    cin>>ad;
    dd= ad-cc-(db/2);
    cout<<"Effective deapth = "<<dd<<" mm"<<endl;
    cout<<endl;
    cout<<"STEP 2 : DEAD LOAD FROM STAIRCASE SLAB(ON PLAN) "<<endl;
    cout<<"Enter the going of staircase(in mm) = ";
    cin>>g;
    cout<<"Enter the risier of flight(in mm) = ";
    cin>>r;
    cout<<"Enter the thread of flight(in mm) = ";
    cin>>t;
    cout<<"Enter the floor finish(in mm) = ";
    cin>>f;
    b=sqrtf((g*g)+(r*r));
    cout<<"B=  "<<b<<" mm"<<endl;
    a=((25/(g/1000))*(((ad/1000)*(b/1000))+(((r/1000)*(t/1000))/2)));
    c=((f/1000)*(t/1000)*23.5)/(g/1000);
    cout<<a<<endl;
    cout<<c<<endl;
    dl=a+c;
    cout<<"Dead load is "<<dl<<" KN/m2"<<endl;
    cout<<endl;
    cout<<"STEP 3 : DESIGN LOAD "<<endl;
    cout<<"Enter the live load for staircase = ";
    cin>>ll;
    tl= 1.5*(dl+ll);
    cout<<"Total load = "<<tl<<" KN/m2"<<endl;
    cout<<endl;
    cout<<"STEP 4 : BENDING MOMENT PER WIDTH OF STAIRCASE "<<endl;
    cout<<"Enter the concrete grade = ";
    cin>>fck;
    cout<<"Enter the width(b)= ";
    cin>>bb;
    mu= (tl*s*s)/10;
    cout<<"Moment (mu) = "<<mu<<" KN"<<endl;
    d1=sqrtf((mu*1000000)/(0.138*fck*bb*1000));
    cout<<"d = "<<d1<<" mm"<<endl;
    if (d1<dd)
    {
        cout<<"The deapth of is correct"<<endl;
    }
    else
    {
        cout<<"The deapth should be increased"<<endl;
    }
    cout<<endl;
    cout<<"STEP 5 : AREA OF STEEL"<<endl;
    cout<<"Enter the steel grade = ";
    cin>>fy;
    x = 1.2 - (sqrtf((1.44)-((6.68*mu*1000000)/(fck*bb*1000*dd*dd))));
    cout<<"(x/d) value = "<<x<<endl;
    z=dd*(1-(0.416*x));
    cout<<"Lever arm = "<<z<<" mm"<<endl;
    ast = ((mu*1000000)/(0.87*fy*z));
    cout<<"Area = "<<ast<<" per m width "<<endl;
    ts = ast*be;
    cout<<"Total steel = "<<ts<<" mm2"<<endl;
    as=0.785*db*db;
    n= ts/as;
    cout<<"Enter the number of bars based on "<<n<<" ";
    cin>>nn;
    cout<<"Provide "<<nn<<" numbers of "<<db<<" mm of bars"<<endl;
    cout<<endl;
    pt= (nn*as*100)/((be*1000)*dd);
    cout<<"Percentage(%) of steel = "<<pt<<" %"<<endl;
    cout<<endl;
    cout<<"STEP 6 : DISTRIBUTION STEEL "<<endl;
    astt = (0.12/100)*bb*1000*ad;
    cout<<"Area of steel bars(distribution bars) = "<<astt<<endl;
    cout<<"Enter the dia for distribution bars in mm = ";
    cin>>dbd;
    cout<<"Enter the spacing of distribution bars = ";
    cin>>sp;
    cout<<"Provide "<<dbd<<" mm @ "<<sp<<" mm c/c "<<endl;
    cout<<endl;
    cout<<"STEP 7 : CHECK FOR SHEAR "<<endl;
    v= (tl*s)/2;
    cout<<"V = "<<v<<"KN/m width"<<endl;
    tw= (v*1000)/(1000*dd);
    cout<<"Tw = "<<tw<<" N/mm2"<<endl;
    cout<<tw<<" Should be lesser than 0.28"<<endl;
    cout<<endl;
    cout<<"STEP 8: DEFLECTIONS CHECK "<<endl;
    fs= (nn*as*0.58*fy/ts);
    cout<<"fs = "<<fs<<" N/mm2"<<endl;












    















}