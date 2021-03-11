#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=1e5;

int main(){
    long double arr[maxn] = {0};
    int sum = 0 , k = 0, s;
    long long n;

    cin>>n;
    
    for(long long i=0; i<n; i++){
        cin >> arr[i];
        // محاسبه جمع کل برای بدست اوردن میانگین
        sum += arr[i];
    }
    
    // میانگین
    sum /= n;
    
    for(long long i=0; i<n ;i++){
        s = arr[i]-sum;
        s = pow(s,2);
        k += s;
    }

    k/=n;
    cout<<"variyans: "<<k<<endl;

    // مرتب سازی برای بدست اوردن مد
    sort(arr,arr+n);
    long long j=1,f,z=1,c;

    f=arr[0];
    c=arr[0];
    for(long long i=1;i<n;i++){
        if(arr[i]==f){
            j++;
            continue;
        }
        else{
            if(z<j){
                z=j;
                c=arr[i-1];
            }
            f=arr[i];
            j=1;
        }
    }
    cout<<"mod: "<<c;
    return 0;
}
