#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<algorithm>
float  maximum (float a, float b,float c,float d){
    if(a>b && a>c && a>d){
        return a;
    }
    else if(b>a && b>c && b>d)
    {
        return b;
    }
    else if(c>a && c>b && c>d)
    {
        return c;
    }
    else
    {
        return d;
    } 
    
}


using namespace std;
int main()
{
    cout<<"This is to calculate layout of corner steel"<<endl;
    cout<<endl;
    float l,b,r,od,ef,cc,d1,d2,ts,tf,tp,s,f,p,dl,ll,w,ax1,ax2,ax3,ax4;
    float ax,axx,ay1,ay2,sum,sm,sum1,sm1,x,d,fck,ws,la,ast,fy,sp,astb,spp;
    cout<<"Enter the length(lx) of slabs in m(shoter direction): ";
    cin>>l;
    cout<<"Enter the breath(ly) of slabs in m(longer direction): ";
    cin>>b;
    r=b/l;
    cout<<"(ly/lx)= "<<r<<endl;
    if (r<2)
    {
        cout<<"This is two way slab"<<endl;
    }
    else
    {
        cout<<"This is one way slab"<<endl;
    }
    cout<<"Enter the overall deapth of slab in mm= ";
    cin>>od;
    cout<<"Enter the clear cover for slab in mm= ";
    cin>>cc;
    cout<<"Enter the dia of bar= ";
    cin>>d1;
    ef=od-cc-(d1/2);
    cout<<"Effective deapth= "<<ef<<" mm"<<endl;
    cout<<endl;
    cout<<"STEP 2:DESIGN LOAD "<<endl;
    cout<<"Enter the slab thickness in mm= ";
    cin>>ts;
    cout<<"Enter the floor finish in mm= ";
    cin>>tf;
    cout<<"Enter the plastering in mm= ";
    cin>>tp;
    s=(ts*25*1)/1000;
    f=(tf*24*1)/1000;
    p=(tp*24*1)/1000;
    dl=s+f+p;
    cout<<"The total dead load is "<<dl<<" KN/m2"<<endl;
    cout<<"Enter the live load= ";
    cin>>ll;
    w=(1.5*dl)+(1.5*ll);
    cout<<"Design load is "<<w<<" KN/m2"<<endl;
    cout<<endl;
    cout<<"STEP 3: TYPE OF SLABS"<<endl;
    cout<<"(ly/lx)= "<<r<<endl;
    cout<<"Refer table number 26 in IS456:2000(pg no=91)"<<endl;
    cout<<"For value "<<r<<" enter the positive and negative values below"<<endl;
    cout<<"Enter the two (negative)values for shorter direction= ";
    cout<<"(Hint: while entering for both steps"<<endl;
    cout<<"first enter the smaller value)"<<endl;
    cin>>ax1;
    cin>>ax2;
    cout<<"Enter the two (positive)values for shorter direction= ";
    cin>>ax3;
    cin>>ax4;
    cout<<"Enter the two values for longer direction= "<<endl;
    cout<<"(Hint: first enter the larger value)"<<endl;
    cin>>ay1;
    cin>>ay2;
    ax=(ax1+ax2)/2;
    axx=(ax3+ax4)/2;
    cout<<endl;
    cout<<"Alpha x"<<endl;
    cout<<"Negative value= "<<ax<<endl;
    cout<<"Positive value= "<<axx<<endl;
    cout<<endl;
    cout<<"Alpha y"<<endl;
    cout<<"Negative value= "<<ay1<<endl;
    cout<<"Positive value= "<<ay2<<endl;
    cout<<endl;
    cout<<"Calculation of moments"<<endl;
    cout<<"For shorter span:"<<endl;
    sum=ax*w*l*l;
    sm=axx*w*l*l;
    cout<<"Support moment= "<<sum<<" KNm"<<endl;
    cout<<"Span moment= "<<sm<<" KNm"<<endl;
    cout<<endl;
    cout<<"For longer span:"<<endl;
    sum1=ay1*w*l*l;
    sm1=ay2*w*l*l;
    cout<<"Support moment= "<<sum1<<" KNm"<<endl;
    cout<<"Span moment= "<<sm1<<" KNm"<<endl;
    float max=maximum(sum,sm,sum1,sm1);
    cout<<"Maximum moment = "<<max<<" KNm"<<endl;
    cout<<"Enter the concrete grade= ";
    cin>>fck;
    cout<<"Enter the width of slabs in m= ";
    cin>>ws;
    d=sqrtf(max*1000000/(0.138*fck*ws*1000));
    cout<<"Checking for deapth"<<endl;
    cout<<"d= "<<d<<" mm"<<endl;
    if (d<ef)
    {
        cout<<"The taken deapth can be used"<<endl;
    }
    else
    {
        cout<<"Decrease the deapth"<<endl;
    }
    x= 1.2 - (sqrtf(1.44 - (6.6*max*1000000)/(fck*ws*1000*ef*ef)));
    cout<<x<<"(x/d) = "<<endl;
    la=ef*(1-(0.416*x));
    cout<<"Lever arm= "<<la<<" mm"<<endl;
    cout<<"Enter the steel grade= ";
    cin>>fy;
    ast= (max*1000000)/(0.87*fy*la);
    cout<<"Area of steel = "<<ast<<" mm2"<<endl;
    cout<<"Enter the dia of bar used for mat in mm = ";
    cin>>d2;
    astb=0.785*d2*d2;
    sp=(1000*astb)/ast;
    cout<<"Enter the spacing based on "<<sp<<" =";
    cin>>spp;
    cout<<"Provide "<<d2<<" mm @ "<<spp<<" mm c/c";





    



    




    




    return 0;
}